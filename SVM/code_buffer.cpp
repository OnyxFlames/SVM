#include "code_buffer.hpp"

#include "memory.hpp"

CodeBuffer::CodeBuffer()
	: mCode(nullptr)
	, mCount(0)
	, mCapacity(0)
{
}

CodeBuffer::~CodeBuffer()
{
	free_array(uint8_t, mCode, mCapacity);
}

// TODO: phase out memory.hpp for a cleaner allocation 
// Note, CodeBuffer doesnt use the VM's runtime allocator, this is intentional
size_t CodeBuffer::write(const uint8_t byte)
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

size_t CodeBuffer::write(const std::initializer_list<uint8_t> bytes)
{
	size_t wrote = 0;
	for (auto it : bytes)
		wrote = write(it);

	return wrote;
}

bool CodeBuffer::write_at(size_t offset, const uint8_t byte)
{
	if (offset < mCount)
	{
		mCode[offset] = byte;
		return true;
	}
	else
		return false;
}

uint8_t* CodeBuffer::get()
{
	return mCode;
}

const size_t CodeBuffer::size() const
{
	return mCount;
}
