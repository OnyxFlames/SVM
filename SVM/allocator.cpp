#include "allocator.hpp"



Allocator::Block* Allocator::find_block(void* block)
{
	for (auto& it : mBlocks)
		if (it.get() == block)
			return &it;
	return nullptr;
}

Allocator::Block* Allocator::find_block(size_t size)
{
	for (auto& it : mBlocks)
		if (it.size >= size)
			return &it;
	return nullptr;
}

void* Allocator::allocate(size_t size)
{
#if defined(SVM_DEBUG_ALLOCATOR)
	debug_printf("Requesting %d bytes (returning %d)\n", size, next_power(size));
#endif

	Block* block = find_block(size);

	if (block && block->free)
	{
		block->free = false;
		return block->get();
	}
	else
	{
		mBlocks.push_back(Block(size));
		return mBlocks.back().get();
	}
}

void Allocator::mark_free(void* block)
{
	Block* used_block = find_block(block);

	if (used_block)
	{
		if (used_block->free)
		{
			debug_printf("Block already freed!\n");
			return;
		}
#if defined(SVM_DEBUG_ALLOCATOR)
		debug_printf("Freeing block %p (%d bytes)\n", used_block->get(), used_block->size);
#endif
		used_block->free = true;
	}
	else
		debug_printf("Invalid block\n");
}

Allocator& Allocator::getGlobalAllocator()
{
	static std::unique_ptr<Allocator> global;
	
	if (!global)
		global = std::make_unique<Allocator>();
		
	return *global;
}

size_t next_power(size_t size)
{
	const size_t count = sizeof(size_t) * 8;

	for (size_t i = 0; i < count; ++i)
	{
		const size_t value = 1 << i;

		if (value >= size)
			return value;
	}
	return 0;
}
