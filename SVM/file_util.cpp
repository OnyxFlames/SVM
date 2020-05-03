#include "file_util.hpp"

#if __cpp_lib_filesystem
#include <filesystem>
namespace fs = std::filesystem;
#define HAS_STD_FILESYSTEM

#elif  __cpp_lib_experimental_filesystem
// TODO: Check if platform is MSVC
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#define HAS_STD_FILESYSTEM
#endif

std::string get_extension(const std::string filepath)
{
#if defined(HAS_STD_FILESYSTEM)
	return fs::path(filepath).extension().string();
#else
	return filepath.substr(filepath.find_last_of('.'));
#endif
}
