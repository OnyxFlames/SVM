#pragma once

#include "common.hpp"

#include <vector>
#include <memory>

#include "debug.hpp"

size_t next_power(size_t size);

class Allocator
{
public:
	struct Block
	{
		bool free;
		size_t size;
		std::unique_ptr<uint8_t[]> data;

		Block(size_t _size)
			:	size(next_power(_size))
			,	free(false)
		{
			data = std::make_unique<uint8_t[]>(size);
		}

		void* get()
		{
			return static_cast<void*>(data.get());
		}
	};
private:
	std::vector<Block> mBlocks;

	Block* find_block(void* block);
	Block* find_block(size_t size);
	Block* find_free_block(size_t size);
public:

	~Allocator();


	void* allocate(size_t size);
	void mark_free(void* block);

	static Allocator& getGlobalAllocator();
};

