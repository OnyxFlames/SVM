#include "object_type_traits.hpp"

static const ObjectTypeTrait type_traits[ObjectType::TypeCount] =
{
	ObjectTypeTrait::ErrorType, // Nil

	ObjectTypeTrait::Integral, // Int8,
	ObjectTypeTrait::Integral, // UInt8

	ObjectTypeTrait::Integral, // Int16
	ObjectTypeTrait::Integral, // UInt16

	ObjectTypeTrait::Integral, // Int32
	ObjectTypeTrait::Integral, // UInt32

	ObjectTypeTrait::Integral, // Int64
	ObjectTypeTrait::Integral, // UInt64

	ObjectTypeTrait::Floating, // Float32
	ObjectTypeTrait::Floating, // Float64

	ObjectTypeTrait::Pointer, // String

	ObjectTypeTrait::Pointer, // SVMObject
};

bool operator&(const ObjectTypeTrait& lhs, const ObjectTypeTrait& rhs)
{
	return (static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}

bool is_nil(ObjectType type)
{
	return type == ObjectType::Nil;
}

bool is_integral(ObjectType type)
{
	return type_traits[static_cast<uint8_t>(type)] & ObjectTypeTrait::Integral;
}

bool is_floating(ObjectType type)
{
	return type_traits[static_cast<uint8_t>(type)] & ObjectTypeTrait::Floating;
}

bool is_numeric(ObjectType type)
{
	return type_traits[static_cast<uint8_t>(type)] & ObjectTypeTrait::Numeric;
}

bool is_pointer(ObjectType type)
{
	return type_traits[static_cast<uint8_t>(type)] & ObjectTypeTrait::Pointer;
}

ObjectType widen(ObjectType type)
{
	switch (type)
	{
	case Int8: return Int16;
	case UInt8: return UInt16;

	case Int16: return Int32;
	case UInt16: return UInt32;

	case Int32: return Int64;
	case UInt32: return UInt64;

	case Float32: return Float64;

	default: return type;
	}
}

ObjectType narrow(ObjectType type)
{
	switch (type)
	{
	case Int16: return Int8;
	case UInt16: return UInt8;

	case Int32: return Int16;
	case UInt32: return UInt16;

	case Int64: return Int32;
	case UInt64: return UInt32;

	case Float64: return Float32;

	default: return type;
	}
}
