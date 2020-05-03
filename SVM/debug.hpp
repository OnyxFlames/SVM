#pragma once

#include "common.hpp"

#if defined(SVM_DEBUG)

#define debug_print(X) do { printf("[Debug]: " ##X); } while(false)
#define debug_printf(X, ...) do { printf("[Debug]: " ##X, __VA_ARGS__); } while(false)

#define debug_print_func() do { printf("[Debug]: %s\n", __FUNCSIG__); } while(false)

#else

#define debug_print(X)
#define debug_printf(X, ...)
#define debug_print_func()

#endif