#include "string_util.hpp"

#include "common.hpp"

#include "allocator.hpp"

char* clone_string(const char* src)
{
	const size_t size = std::strlen(src) + 1;
	auto& alloc = Allocator::getGlobalAllocator();
	char* ret = static_cast<char*>(alloc.allocate(size));
	std::memcpy(ret, src, size);

	return ret;
}
