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

char* concat_string(const char* str1, const char* str2)
{
	const size_t size1 = std::strlen(str1), size2 = std::strlen(str2);
	auto& alloc = Allocator::getGlobalAllocator();

	char* ret = static_cast<char*>(alloc.allocate(size1 + size2 + 1));

	if (!ret)
		return nullptr;

	std::memcpy(ret, str1, size1);
	std::memcpy(ret + size1, str2, size2);
	//ret[size1 + size2] = '\0';

	return ret;
}

void free_string(char* str)
{
	auto& alloc = Allocator::getGlobalAllocator();
	alloc.mark_free(str);

}
