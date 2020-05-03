#pragma once

#include "common.hpp"

class CodeBuffer
{
private:
	uint8_t* mCode;
	size_t mCount;
	size_t mCapacity;
public:

	CodeBuffer();

	size_t write(const uint8_t byte);
	size_t write(const std::initializer_list<uint8_t> bytes);

	bool write_at(size_t offset, const uint8_t byte);

	uint8_t* get();
};