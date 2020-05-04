#pragma once

#include "common.hpp"

enum ObjectType : uint8_t
{
	Nil,
	
	Int8,
	UInt8,

	Int16,
	UInt16,

	Int32,
	UInt32,

	Int64,
	UInt64,

	Float32,
	Float64,

	String,

	FileHandle,

	SVMObject,

	TypeCount,
};

std::string to_string(ObjectType type);

uint8_t width(const ObjectType type);

bool operator>(const ObjectType lhs, const ObjectType rhs);
bool operator<(const ObjectType lhs, const ObjectType rhs);