#pragma once

#include "object_type.hpp"
#include "object_data.hpp"

class Object
{
private:
	ObjectType mType;
	ObjectData mData;

public:
	Object();
	Object(const Object& rhs);
	Object(Object&& rhs) noexcept;
	Object(int8_t i8);
	Object(uint8_t u8);
	Object(int16_t i16);
	Object(uint16_t u16);
	Object(int32_t i32);
	Object(uint32_t u32);
#if defined(SVM_64BIT)
	Object(int64_t i64);
	Object(uint64_t u64);
	Object(double f64);
#endif
	Object(float f32);
	
	Object(const char* str);

	~Object();

	Object& operator=(const Object& rhs);
	Object& operator=(Object&& rhs) noexcept;
	Object& operator=(const int8_t i8);
	Object& operator=(const uint8_t u8);
	Object& operator=(const int16_t i16);
	Object& operator=(const uint16_t u16);
	Object& operator=(const int32_t i32);
	Object& operator=(const uint32_t u32);
	Object& operator=(const int64_t i64);
	Object& operator=(const uint64_t u64);
	Object& operator=(const float f32);
	Object& operator=(const double f64);
	Object& operator=(char* str);

	Object operator+(const Object& rhs);
	Object operator-(const Object& rhs);
	Object operator*(const Object& rhs);
	Object operator/(const Object& rhs);
	Object operator%(const Object& rhs);

	const ObjectType getType() const;
	const ObjectData& getData() const;

	const std::string str() const;

	/* 
		convert the object to this type, narrow types clear unused data,
		allowing the object to behave more expectedly when casting down, then casting up
	*/
	bool cast_to(ObjectType type);
};
