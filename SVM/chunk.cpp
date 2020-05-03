#include "chunk.hpp"

#include "memory.hpp"

Chunk::Chunk()

{
}

size_t Chunk::write(uint8_t byte)
{
	return mCode.write(byte);
}

size_t Chunk::addConstant(Object obj)
{
	mConstants.push_back(obj);
	return mConstants.size() - 1;
}

Object Chunk::getConstant(size_t idx)
{
	if (idx > mConstants.size())
		return Object();
	else
		return mConstants[idx];
}
