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

Object::Object(float f32)
	: mType(ObjectType::Float32)
{
	mData.f32 = f32;
}

Object::Object(double f64)
	: mType(ObjectType::Float64)
{
	mData.f64 = f64;
}

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
	//TODO: Add check if current type is a string, to mark it as free before reallocating
	this->mType = rhs.mType;
	// special case for strings
	if (mType == ObjectType::String)
	{
		mData.cstr = clone_string(rhs.mData.cstr);
		free_string(rhs.mData.cstr);
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

Object& Object::operator=(const float f32)
{
	mData.f32 = f32;
	mType = Float32;
	return *this;
}

Object& Object::operator=(const double f64)
{
	mData.f64 = f64;
	mType = Float64;
	return *this;
}

Object& Object::operator=(char* str)
{
	mData.cstr = clone_string(str);
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
		OBJECT_NUMERIC_ARITH(ret, curr, rhs, +);
	}
	return ret;
}

Object Object::operator-(const Object& rhs)
{
	Object ret;
	Object& curr = *this;

	OBJECT_NUMERIC_ARITH(ret, curr, rhs, -);

	return ret;
}

Object Object::operator*(const Object& rhs)
{
	Object ret;
	Object& curr = *this;

	OBJECT_NUMERIC_ARITH(ret, curr, rhs, *);

	return ret;
}

Object Object::operator/(const Object& rhs)
{
	Object ret;
	Object& curr = *this;

	OBJECT_NUMERIC_ARITH(ret, curr, rhs, /);

	return ret;
}

Object Object::operator%(const Object& rhs)
{
	Object ret;
	Object& curr = *this;

	OBJECT_INTEGRAL_ARITH(ret, curr, rhs, %);

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
	case Int8: ss << mData.i8; break;
	case UInt8: ss << mData.u8; break;
	case Int16: ss << mData.i16; break;
	case UInt16: ss << mData.u16; break;
	case Int32: ss << mData.i32; break;
	case UInt32: ss << mData.u32; break;
	case Int64: ss << mData.i64; break;
	case UInt64: ss << mData.u64; break;
	case Float32: ss << mData.f32; break;
	case Float64: ss << mData.f64; break;
	case String: ss << mData.cstr; break;
	case SVMObject: ss << mData.obj; break;
	default: return "ErrorType";
	}

	return ss.str();
}
