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
