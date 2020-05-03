#pragma once

#include <cstdint>
#include <cassert>
#include <cstdlib>
#include <cstddef>
#include <string>

//#define SVM_64BIT

// enable debugging features
#define SVM_DEBUG
// enable features that allow the VM to be developed
#define SVM_DEVELOPER_FEATURES

// release candidate
//#define SVM_RELEASE

#if defined(SVM_DEBUG)

//#define SVM_DEBUG_ALLOCATOR

#endif

#if defined(SVM_DEBUG) && defined(SVM_RELEASE)
#error Release candidate cannot have debugging features enabled.
#endif
