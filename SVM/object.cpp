#include "object.hpp"

#include "object_arith.inl"
#include "vm_code_gen.hpp"

#include <sstream>
#include "allocator.hpp"

#include "debug.hpp"

#include "string_util.hpp"

Object::Object()
	:	mType(ObjectType::Nil)
{
	
	mData.obj = nullptr;
}

Object::Object(const Object& rhs)
{
	this->mType = rhs.mType;
	// special case for strings
	if (mType == ObjectType::String)
	{
		mData.cstr = clone_string(rhs.mData.cstr);
	}
	else
	{
		this->mData = rhs.mData;
	}
}

Object::Object(Object&& rhs) noexcept
{
	this->mType = rhs.mType;
	// special case for strings
	if (mType == ObjectType::String)
	{
		mData.cstr = clone_string(rhs.mData.cstr);
		//free_string(rhs.mData.cstr);
	}
	else
	{
		this->mData = rhs.mData;
	}
}

Object::Object(int8_t i8)
	:	mType(ObjectType::Int8)
{
	mData.i8 = i8;
}

Object::Object(uint8_t u8)
	: mType(ObjectType::UInt8)
{
	mData.u8 = u8;
}

Object::Object(int16_t i16)
	: mType(ObjectType::Int16)
{
	mData.i16 = i16;
}

Object::Object(uint16_t u16)
	: mType(ObjectType::UInt16)
{
	mData.u16 = u16;
}

Object::Object(int32_t i32)
	: mType(ObjectType::Int32)
{
	mData.i32 = i32;
}

Object::Object(uint32_t u32)
	: mType(ObjectType::UInt32)
{
	mData.u32 = u32;
}

Object::Object(float f32)
	: mType(ObjectType::Float32)
{
	mData.f32 = f32;
}
// 64 bit Sapphire
#if defined(SVM_64BIT)
Object::Object(int64_t i64)
	: mType(ObjectType::Int64)
{
	mData.i64 = i64;
}

Object::Object(uint64_t u64)
	: mType(ObjectType::UInt64)
{
	mData.u64 = u64;
}
Object::Object(double f64)
	: mType(ObjectType::Float64)
{
	mData.f64 = f64;
}
#endif
Object::Object(const char* str)
	:	mType(ObjectType::String)
{
	mData.cstr = clone_string(str);
}

Object::Object(FILE* file)
	:	mType(ObjectType::FileHandle)
{
	mData.file = file;
}

Object::~Object()
{
	if (mType == ObjectType::String)
	{
		auto& alloc = Allocator::getGlobalAllocator();
		alloc.mark_free(static_cast<void*>(mData.cstr));
	}
}


Object& Object::operator=(const Object& rhs)
{
	// free the old string
	if (mType == String)
		 free_string(mData.cstr);

	this->mType = rhs.mType;
	// special case for strings
	if (mType == ObjectType::String)
	{
		mData.cstr = clone_string(rhs.mData.cstr);
	}
	else
	{
		this->mData = rhs.mData;
	}

	return *this;
}

Object& Object::operator=(Object&& rhs) noexcept
{
	// free the old string
	if (mType == String)
		 free_string(mData.cstr);

	this->mType = rhs.mType;
	// special case for strings
	if (mType == ObjectType::String)
	{
		mData.cstr = clone_string(rhs.mData.cstr);
	}
	else
	{
		this->mData = rhs.mData;
	}

	return *this;
}

Object& Object::operator=(const int8_t i8)
{
	mData.i8 = i8;
	mType = Int8;
	return *this;
}

Object& Object::operator=(const uint8_t u8)
{
	mData.u8 = u8;
	mType = UInt8;
	return *this;
}

Object& Object::operator=(const int16_t i16)
{
	mData.i16 = i16;
	mType = Int16;
	return *this;
}

Object& Object::operator=(const uint16_t u16)
{
	mData.u16 = u16;
	mType = UInt16;
	return *this;
}

Object& Object::operator=(const int32_t i32)
{
	mData.i32 = i32;
	mType = Int32;
	return *this;
}

Object& Object::operator=(const uint32_t u32)
{
	mData.u32 = u32;
	mType = UInt32;
	return *this;
}



Object& Object::operator=(const float f32)
{
	mData.f32 = f32;
	mType = Float32;
	return *this;
}
#if defined(SVM_64BIT)
Object& Object::operator=(const int64_t i64)
{
	mData.i64 = i64;
	mType = Int64;
	return *this;
}

Object& Object::operator=(const uint64_t u64)
{
	mData.u64 = u64;
	mType = UInt64;
	return *this;
}
Object& Object::operator=(const double f64)
{
	mData.f64 = f64;
	mType = Float64;
	return *this;
}
#endif // SVM_64BIT
Object& Object::operator=(char* str)
{
	// free the old string
	if (mType == String)
		 free_string(mData.cstr);

	mData.cstr = clone_string(str);
	// explicitly free this string
	free_string(str);
	mType = ObjectType::String;
	return *this;
}

Object Object::operator+(const Object& rhs)
{
	Object ret;
	Object& curr = *this;

	if (mType == ObjectType::String)
	{
		ret = concat_string(mData.cstr, rhs.mData.cstr);
	}
	else
	{
#if defined(SVM_64BIT)
		OBJECT_NUMERIC_BINARY_ARITH64(ret, curr, rhs, +);
#else
		OBJECT_NUMERIC_BINARY_ARITH32(ret, curr, rhs, +);
#endif
	}
	return ret;
}

Object Object::operator-(const Object& rhs)
{
	Object ret;
	Object& curr = *this;

#if defined(SVM_64BIT)
	OBJECT_NUMERIC_BINARY_ARITH64(ret, curr, rhs, -);
#else
	OBJECT_NUMERIC_BINARY_ARITH32(ret, curr, rhs, -);
#endif

	return ret;
}

Object Object::operator*(const Object& rhs)
{
	Object ret;
	Object& curr = *this;

#if defined(SVM_64BIT)
	OBJECT_NUMERIC_BINARY_ARITH64(ret, curr, rhs, *);
#else
	OBJECT_NUMERIC_BINARY_ARITH32(ret, curr, rhs, *);
#endif

	return ret;
}

Object Object::operator/(const Object& rhs)
{
	Object ret;
	Object& curr = *this;

#if defined(SVM_64BIT)
	OBJECT_NUMERIC_BINARY_ARITH64(ret, curr, rhs, /);
#else
	OBJECT_NUMERIC_BINARY_ARITH32(ret, curr, rhs, /);
#endif

	return ret;
}

Object Object::operator%(const Object& rhs)
{
	Object ret;
	Object& curr = *this;

#if defined(SVM_64BIT)
	OBJECT_INTEGRAL_BINARY_ARITH64(ret, curr, rhs, %);
#else
	OBJECT_INTEGRAL_BINARY_ARITH32(ret, curr, rhs, %);
#endif

	return ret;
}

Object Object::operator<<(const Object& rhs)
{
	Object ret;
	Object& curr = *this;

#if defined(SVM_64BIT)
	OBJECT_INTEGRAL_BINARY_ARITH64(ret, curr, rhs, <<);
#else
	OBJECT_INTEGRAL_BINARY_ARITH32(ret, curr, rhs, <<);
#endif

	return ret;
}

Object Object::operator>>(const Object& rhs)
{
	Object ret;
	Object& curr = *this;

#if defined(SVM_64BIT)
	OBJECT_INTEGRAL_BINARY_ARITH64(ret, curr, rhs, >>);
#else
	OBJECT_INTEGRAL_BINARY_ARITH32(ret, curr, rhs, >>);
#endif

	return ret;
}

Object& Object::operator++()
{
	Object& curr = *this;

#if defined(SVM_64BIT)
	OBJECT_NUMERIC_UNARY_ARITH64(ret, curr, +1);
#else
	OBJECT_NUMERIC_UNARY_ARITH32(curr, curr, +1);
#endif

	return curr;
}

Object& Object::operator--()
{
	Object& curr = *this;

#if defined(SVM_64BIT)
	OBJECT_NUMERIC_UNARY_ARITH64(ret, curr, -1);
#else
	OBJECT_NUMERIC_UNARY_ARITH32(curr, curr, -1);
#endif

	return curr;
}

const ObjectType Object::getType() const
{
	return mType;
}

const ObjectData& Object::getData() const
{
	return mData;
}

const std::string Object::str() const
{
	std::stringstream ss;

	switch (mType)
	{
	case Nil: return "Nil";
	case Int8: ss << (int16_t)mData.i8; break;
	case UInt8: ss << (int16_t)mData.u8; break;
	case Int16: ss << mData.i16; break;
	case UInt16: ss << mData.u16; break;
	case Int32: ss << mData.i32; break;
	case UInt32: ss << mData.u32; break;

#if defined(SVM_64BIT)
	case Int64: ss << mData.i64; break;
	case UInt64: ss << mData.u64; break;
	case Float64: ss << mData.f64; break;
#endif
	case Float32: ss << mData.f32; break;
	case String: ss << mData.cstr; break;
	case SVMObject: ss << mData.obj; break;
	default: return "ErrorType";
	}

	return ss.str();
}

#include "byte_buffer.hpp"

Object Object::from_bytes(const ObjectType type, const std::vector<uint8_t>& bytes)
{
	switch (type)
	{
		case Int8:
		{
			ByteBuffer<int8_t> i8;
			i8.bytes[0] = bytes[0];
			return Object(i8.data);
		}
		case UInt8:
		{
			ByteBuffer<uint8_t> u8;
			u8.bytes[0] = bytes[0];
			return Object(u8.data);
		}
		case Int16:
		{
			ByteBuffer<int16_t> i16;
			for (size_t i = 0; i < sizeof(int16_t); ++i)
				i16.bytes[i] = bytes[i];
			return Object(i16.data);
		}
		case UInt16:
		{
			ByteBuffer<uint16_t> u16;
			for (size_t i = 0; i < sizeof(uint16_t); ++i)
				u16.bytes[i] = bytes[i];
			return Object(u16.data);
		}
		case Int32:
		{
			ByteBuffer<int32_t> i32;
			for (size_t i = 0; i < sizeof(int32_t); ++i)
				i32.bytes[i] = bytes[i];
			return Object(i32.data);
		}
		case UInt32:
		{
			ByteBuffer<uint32_t> u32;
			for (size_t i = 0; i < sizeof(uint32_t); ++i)
				u32.bytes[i] = bytes[i];
			return Object(u32.data);
		}
		case Float32:
		{
			ByteBuffer<uint8_t> f32;
			for (size_t i = 0; i < sizeof(float); ++i)
				f32.bytes[i] = bytes[i];
			return Object(f32.data);
		}
#if defined(SVM_64BIT)
		case Int64:
		{
			ByteBuffer<int64_t> i64;
			for (size_t i = 0; i < sizeof(int64_t); ++i)
				i64.bytes[i] = bytes[i];
			return Object(i64.data);
		}
		case UInt64:
		{
			ByteBuffer<uint64_t> u64;
			for (size_t i = 0; i < sizeof(uint64_t); ++i)
				u64.bytes[i] = bytes[i];
			return Object(u64.data);
		}
		case Float64:
		{
			ByteBuffer<double> f64;
			for (size_t i = 0; i < sizeof(double); ++i)
				f64.bytes[i] = bytes[i];
			return Object(f64.data);
		}
#endif
		case String:
		{
			// save the string copy by directly initializing it
			char* str = static_cast<char*>(Allocator::getGlobalAllocator().allocate(bytes.size() + 1));
			str[bytes.size()] = '\0';
			Object ret;
			ret.mType = String;
			ret.mData.cstr = str;
			return ret;
		}
		default: 
			printf("Unable to contruct arbitrary object of type %s from bytes.\n", to_string(type).c_str());
			return Object();
		break;
	}

}
// Note: assumes little-endian, when porting to big endian platforms this needs to be tweaked into endian-aware functions
std::vector<uint8_t> Object::to_bytes(const Object& object)
{
	std::vector<uint8_t> ret;
	switch (object.getType())
	{
		case Int8:
		{
			ByteBuffer<int8_t> i8;
			i8.data = object.getData().i8;
			for (size_t i = 0; i < sizeof(int8_t); ++i)
				ret.push_back(i8[i]);
			return ret;
		}
		case UInt8:
		{
			ByteBuffer<uint8_t> u8;
			u8.data = object.getData().u8;
			for (size_t i = 0; i < sizeof(uint8_t); ++i)
				ret.push_back(u8[i]);
			return ret;
		}
		case Int16:
		{
			ByteBuffer<int16_t> i16;
			i16.data = object.getData().i16;
			for (size_t i = 0; i < sizeof(int16_t); ++i)
				ret.push_back(i16[i]);
			return ret;
		}
		case UInt16:
		{
			ByteBuffer<uint16_t> u16;
			u16.data = object.getData().u16;
			for (size_t i = 0; i < sizeof(uint16_t); ++i)
				ret.push_back(u16[i]);
			return ret;
		}
		case Int32:
		{
			ByteBuffer<int32_t> i32;
			i32.data = object.getData().i32;
			for (size_t i = 0; i < sizeof(int32_t); ++i)
				ret.push_back(i32[i]);
			return ret;
		}
		case UInt32:
		{
			ByteBuffer<uint32_t> u32;
			u32.data = object.getData().u32;
			for (size_t i = 0; i < sizeof(uint32_t); ++i)
				ret.push_back(u32[i]);
			return ret;
		}
		case Float32:
		{
			ByteBuffer<float> f32;
			f32.data = object.getData().f32;
			for (size_t i = 0; i < sizeof(float); ++i)
				ret.push_back(f32[i]);
			return ret;
		}
		case String:
		{
			char* str = object.mData.cstr;
			const size_t size = std::strlen(str);

			for (size_t i = 0; i < size; ++i)
				ret.push_back(static_cast<uint8_t>(str[i]));
			ret.push_back('\0');
			return ret;
		}
#if defined(SVM_64BIT)
		case Int64:
		{
			ByteBuffer<int32_t> i64;
			i64.data = object.getData().i64;
			for (size_t i = 0; i < sizeof(int64_t); ++i)
				ret.push_back(i64[i]);
			return ret;
		}
		case UInt64:
		{
			ByteBuffer<uint8_t> u64;
			u64.data = object.getData().u64;
			for (size_t i = 0; i < sizeof(uint64_t); ++i)
				ret.push_back(u64[i]);
			return ret;
		}
		case Float64:
		{
			ByteBuffer<uint8_t> f64;
			f64.data = object.getData().f64;
			for (size_t i = 0; i < sizeof(double); ++i)
				ret.push_back(f64[i]);
			return ret;
		}
#endif
		default: 
			printf("Unable to convert object of type %s into bytestream.\n", to_string(object.getType()).c_str());
			return std::vector<uint8_t>();
	}
}

// Note: this assumes 64-bit Sapphire, using u64 to modify numbers
#if defined(SVM_64BIT)
bool Object::cast_to(ObjectType type)
{

	ObjectData buffer = mData;
	mData.obj = nullptr;

	// if we're wider
	if (mType > type)
	{
		switch (width(type))
		{
		case 1: mData.u64 = buffer.u64 & 0xff; break;
		case 2: mData.u64 = buffer.u64 & 0xffff; break;
		case 4: mData.u64 = buffer.u64 & 0xffffffff; break;
		case 8: mData.u64 = buffer.u64 & 0xffffffffffffffff; break;
		default: printf("Invalid casting type\n");  return false;
		}
	}
	else if (mType < type)
	{
		switch (width(mType))
		{
		case 1: mData.u64 = buffer.u64 & 0xff; break;
		case 2: mData.u64 = buffer.u64 & 0xffff; break;
		case 4: mData.u64 = buffer.u64 & 0xffffffff; break;
		case 8: mData.u64 = buffer.u64 & 0xffffffffffffffff; break;
		default: printf("Invalid casting type\n");  return false;
		}
	}

	mType = type;
	return true;
}
#else
bool Object::cast_to(ObjectType type)
{

	ObjectData buffer = mData;
	mData.obj = nullptr;

	// if we're wider
	if (mType > type)
	{
		switch (width(type))
		{
		case 1: mData.u32 = buffer.u32 & 0xff; break;
		case 2: mData.u32 = buffer.u32 & 0xffff; break;
		case 4: mData.u32 = buffer.u32 & 0xffffffff; break;
		default: printf("Invalid casting type\n");  return false;
		}
	}
	else if (mType < type)
	{
		switch (width(mType))
		{
		case 1: mData.u32 = buffer.u32 & 0xff; break;
		case 2: mData.u32 = buffer.u32 & 0xffff; break;
		case 4: mData.u32 = buffer.u32 & 0xffffffff; break;
		default: printf("Invalid casting type\n");  return false;
		}
	}

	mType = type;
	return true;
}
#endif