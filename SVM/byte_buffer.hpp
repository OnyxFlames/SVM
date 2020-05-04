#pragma once

#include "common.hpp"
#include <array>

/*
	for constructing a type to and from bytes
	Note: endianess-unaware, maybe turn into a class that does endianess checks
*/

bool isLittleEndian();
bool isBigEndian();

template <typename T>
union ByteBuffer
{
	T data;
	// endianess unaware, use operator[]
	uint8_t bytes[sizeof(T)];

	const uint8_t& operator[](size_t i);
};

template<typename T>
inline const uint8_t& ByteBuffer<T>::operator[](size_t i)
{
	if (isLittleEndian())
	{
		return bytes[sizeof(T) - 1 - i];
	}
	else// if (isBigEndian())
	{
		return bytes[i];
	}

}
