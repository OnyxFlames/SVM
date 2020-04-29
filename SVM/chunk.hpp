#pragma once

#include "common.hpp"

#include <vector>

#include "object.hpp"

class Chunk
{
private:
	uint8_t* mCode;
	size_t mCount;
	size_t mCapacity;

	std::vector<Object> mConstants;
public:
	Chunk();

	size_t write(uint8_t byte);

	size_t addConstant(Object obj);
	Object getConstant(size_t idx);
};

