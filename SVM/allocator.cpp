#include "allocator.hpp"



Allocator::Block* Allocator::find_block(void* block)
{
	for (auto& it : mBlocks)
		if (it.get() == block)
			return &it;
	return nullptr;
}
// should finding a block by size implicitly be free?
Allocator::Block* Allocator::find_block(size_t size)
{
	for (auto& it : mBlocks)
		if (it.size >= size)
			return &it;
	return nullptr;
}

Allocator::Block* Allocator::find_free_block(size_t size)
{
	for (auto& it : mBlocks)
		if (it.size >= size && it.free)
			return &it;
	return nullptr;
}

Allocator::~Allocator()
{
#if defined(SVM_DEBUG_ALLOCATOR)
	if (mBlocks.size() > 0)
		debug_printf("Allocated Blocks[%d]:\n", mBlocks.size());
	for (auto& it : mBlocks)
	{
		debug_printf("\tBlock: %p Size: %d Free: %s\n",
			it.get(), it.size, (it.free ? "true" : "false"));
	}
#endif
}

void* Allocator::allocate(size_t size)
{
#if defined(SVM_DEBUG_ALLOCATOR)
	debug_printf("Requesting %d bytes (returning %d)\n", size, next_power(size));
#endif

	Block* block = find_free_block(size);

	if (block && block->free)
	{
		block->free = false;
#if defined(SVM_DEBUG_ALLOCATOR)
		debug_printf("Returning old block %p\n", block->get());
#endif
		return block->get();
	}
	else
	{
		mBlocks.push_back(Block(size));
#if defined(SVM_DEBUG_ALLOCATOR)
		debug_printf("Returning new block %p\n", mBlocks.back().get());
#endif
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
			debug_printf("Multiple free on block %p (%d bytes)\n", used_block->get(), used_block->size);
			return;
		}
#if defined(SVM_DEBUG_ALLOCATOR)
		debug_printf("Freeing block %p (%d bytes)\n", used_block->get(), used_block->size);
#endif
		used_block->free = true;
	}
	else
		debug_printf("%p is not a valid block (or isn't owned by this allocator)\n", block);
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
