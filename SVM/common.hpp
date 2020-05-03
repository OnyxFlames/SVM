#pragma once

#include <cstdint>
#include <cassert>
#include <cstdlib>
#include <cstddef>
#include <string>

// enable debugging features
#define SVM_DEBUG

// release candidate
//#define SVM_RELEASE

#if defined(SVM_DEBUG)

//#define SVM_DEBUG_ALLOCATOR

#endif

#if defined(SVM_DEBUG) && defined(SVM_RELEASE)
#error Release candidate cannot have debugging features enabled.
#endif