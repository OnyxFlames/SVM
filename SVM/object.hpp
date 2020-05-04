#pragma once

#include "object_type.hpp"
#include "object_data.hpp"

#include <vector>

class Object
{
private:
	ObjectType mType;
	ObjectData mData;

public:
	explicit Object();
	Object(const Object& rhs);
	Object(Object&& rhs) noexcept;
	explicit Object(int8_t i8);
	explicit Object(uint8_t u8);
	explicit Object(int16_t i16);
	explicit Object(uint16_t u16);
	explicit Object(int32_t i32);
	explicit Object(uint32_t u32);
#if defined(SVM_64BIT)
	explicit Object(int64_t i64);
	explicit Object(uint64_t u64);
	explicit Object(double f64);
#endif
	explicit Object(float f32);
	explicit Object(const char* str);
	explicit Object(FILE* file);

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
	Object operator<<(const Object& rhs);
	Object operator>>(const Object& rhs);
	Object& operator++();
	Object& operator--();

	const ObjectType getType() const;
	const ObjectData& getData() const;

	const std::string str() const;

	/* 
		convert the object to this type, narrow types clear unused data,
		allowing the object to behave more expectedly when casting down, then casting up
	*/
	bool cast_to(ObjectType type);
	
	static Object from_bytes(const ObjectType type, const std::vector<uint8_t>& bytes);
	static std::vector<uint8_t> to_bytes(const Object& object);
};
