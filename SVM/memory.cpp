#include "memory.hpp"

#include "common.hpp"

void* reallocate(void* prev, size_t old_size, size_t new_size)
{
	if (new_size == 0)
	{
		std::free(prev);
		return nullptr;
	}

	return std::realloc(prev, new_size);
}
