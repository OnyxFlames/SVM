#pragma once

#include "common.hpp"
#include "object_type.hpp"

enum class ObjectTypeTrait : uint8_t
{
	ErrorType =		0,
	Integral =		1 << 0,
	Floating =		1 << 1,
	Numeric =		Integral | Floating,
	Pointer =		1 << 2,

};

bool is_nil(ObjectType type);
bool is_integral(ObjectType type);
bool is_floating(ObjectType type);
bool is_numeric(ObjectType type);
bool is_pointer(ObjectType type);

ObjectType widen(ObjectType type);
ObjectType narrow(ObjectType type);
