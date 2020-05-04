#pragma once

#include "common.hpp"
#include <array>

/*
	for constructing a type to and from bytes
	Note: endianess-unaware, maybe turn into a class that does endianess checks
*/

template <typename T>
union ByteBuffer
{
	T data;
	uint8_t bytes[sizeof(T)];
};