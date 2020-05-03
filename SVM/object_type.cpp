#include "object_type.hpp"

#include <string>

#define type_string_case(type) case ObjectType::type: return #type

std::string to_string(ObjectType type)
{
	switch (type)
	{
		type_string_case(Nil);
		type_string_case(Int8);
		type_string_case(UInt8);
		type_string_case(Int16);
		type_string_case(UInt16);
		type_string_case(Int32);
		type_string_case(UInt32);
		type_string_case(Int64);
		type_string_case(UInt64);
		type_string_case(Float32);
		type_string_case(Float64);
		type_string_case(String);
		type_string_case(SVMObject);
	default: return "Unknown Type";
	}
}

const static uint8_t _type_width[ObjectType::TypeCount] =
{
	0, // Nil
	1, // Int8
	1, // UInt8
	2, // Int16
	2, // UInt16
	4, // Int32
	4, // UInt32
	8, // Int64
	8, // UInt64
	4, // Float32
	8, // Float64
	0, // String
	0, // SVMObject
};

uint8_t width(const ObjectType type)
{
	return _type_width[type];
}


bool operator>(const ObjectType lhs, const ObjectType rhs)
{
	return _type_width[lhs] > _type_width[rhs];
}

bool operator<(const ObjectType lhs, const ObjectType rhs)
{
	return _type_width[lhs] < _type_width[rhs];
}
