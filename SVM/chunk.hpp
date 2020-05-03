#pragma once

#include "common.hpp"

#include <vector>

#include "object.hpp"

#include "code_buffer.hpp"

class Chunk
{
private:
	CodeBuffer mCode;
	std::vector<Object> mConstants;
public:
	Chunk();

	size_t write(uint8_t byte);

	size_t addConstant(Object obj);
	Object getConstant(size_t idx);
};

