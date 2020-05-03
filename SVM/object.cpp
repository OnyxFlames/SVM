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
		OBJECT_NUMERIC_ARITH64(ret, curr, rhs, +);
#else
		OBJECT_NUMERIC_ARITH32(ret, curr, rhs, +);
#endif
	}
	return ret;
}

Object Object::operator-(const Object& rhs)
{
	Object ret;
	Object& curr = *this;

#if defined(SVM_64BIT)
	OBJECT_NUMERIC_ARITH64(ret, curr, rhs, -);
#else
	OBJECT_NUMERIC_ARITH32(ret, curr, rhs, -);
#endif

	return ret;
}

Object Object::operator*(const Object& rhs)
{
	Object ret;
	Object& curr = *this;

#if defined(SVM_64BIT)
	OBJECT_NUMERIC_ARITH64(ret, curr, rhs, *);
#else
	OBJECT_NUMERIC_ARITH32(ret, curr, rhs, *);
#endif

	return ret;
}

Object Object::operator/(const Object& rhs)
{
	Object ret;
	Object& curr = *this;

#if defined(SVM_64BIT)
	OBJECT_NUMERIC_ARITH64(ret, curr, rhs, /);
#else
	OBJECT_NUMERIC_ARITH32(ret, curr, rhs, /);
#endif

	return ret;
}

Object Object::operator%(const Object& rhs)
{
	Object ret;
	Object& curr = *this;

#if defined(SVM_64BIT)
	OBJECT_INTEGRAL_ARITH64(ret, curr, rhs, %);
#else
	OBJECT_INTEGRAL_ARITH32(ret, curr, rhs, %);
#endif

	return ret;
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