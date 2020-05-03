#include "file_util.hpp"

#include "platform.hpp"

#if __cpp_lib_filesystem
#include <filesystem>
namespace fs = std::filesystem;
#define HAS_STD_FILESYSTEM
#elif  __cpp_lib_experimental_filesystem

#if defined(SVM_PLATFORM_COMPILER_MSVC)
#	define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#endif
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#define HAS_STD_FILESYSTEM
#endif

#include <fstream>

std::string get_extension(const std::string filepath)
{
#if defined(HAS_STD_FILESYSTEM)
	return fs::path(filepath).extension().string();
#else
	if (filepath.find_last_of('.') != std::string::npos)
		return filepath.substr(filepath.find_last_of('.'));
	else
		return "";
#endif
}

uintmax_t get_filesize(const std::string filepath)
{
#if defined(HAS_STD_FILESYSTEM)
	return fs::file_size(fs::path(filepath));
#else
	std::ifstream f(filepath);
	f.seekg(0, std::ios::end);
	uintmax_t size = static_cast<uintmax_t>(f.tellg());
	f.seekg(0, std::ios::beg);
	f.close();
	return size;
#endif
}
