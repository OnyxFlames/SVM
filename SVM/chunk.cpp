#include "chunk.hpp"

#include "memory.hpp"

Chunk::Chunk()
	:	mCode(nullptr)
	,	mCount(0)
	,	mCapacity(0)
{
}

size_t Chunk::write(uint8_t byte)
{
	if (mCapacity < mCount + 1)
	{
		size_t old_capacity = mCapacity;
		mCapacity = grow_capacity(old_capacity);
		mCode = grow_array(mCode, uint8_t, old_capacity, mCapacity);
	}

	mCode[mCount] = byte;
	++mCount;

	return mCount;
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
