#pragma once

// Compiler
#if defined(__CC_ARM)
#define SVM_PLATFORM_COMPILER_ARM
#define SVM_PLATOFMR_COMPILER "ARMC"
#elif defined(__clang__)
#define SVM_PLATFORM_COMPILER_CLANG
#define SVM_PLATOFMR_COMPILER "Clang"
#elif defined(__GNUC__)
#define SVM_PLATFORM_COMPILER_GCC
#define SVM_PLATOFMR_COMPILER "GCC"
#elif defined(__INTEL_COMPILER)
#define SVM_PLATFORM_COMPILER_INTEL
#define SVM_PLATOFMR_COMPILER "IntelC"
#elif defined (_MSC_VER)
#define SVM_PLATFORM_COMPILER_MSVC
#define SVM_PLATOFMR_COMPILER "MSVC"
#else
#define SVM_PLATFORM_COMPILER_UNKNOWN
#define SVM_PLATFORM_COMPILER "Unknown"
#endif

// OS
#if defined(__ANDROID__)
#define SVM_PLATFORM_OS_ANDROID
#define SVM_PLATFORM_OS "Android"
#elif  defined(__FreeBDS__) || defined(__NetBSD__) || defined(__OpenBSD__)\
	|| defined(__bsdi__) || defined(__DragonFly__)
#define SVM_PLATFORM_OS_BSD
#define SVM_PLATFORM_OS "BSD"
#elif defined(__linux__)
#define SVM_PLATFORM_OS_LINUX
#define SVM_PLATFORM_OS "Linux"
#elif defined(macintosh) || defined(Macintosh) || (defined(__APPLE__) && defined(__MACH__))
#define SVM_PLATFORM_OS_OSX
#define SVM_PLATFORM_OS "OSX"
#elif defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
#define SVM_PLATFORM_OS_WINDOWS
#define SVM_PLATFORM_OS "Windows"
#else
#define SVM_PLATFORM_OS_UNKNOWN
#define SVM_PLATFORM_OS "Unknown"
#endif

// CPU
#if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64)
#define SVM_PLATFORM_CPU_AMD64
#define SVM_PLATFORM_CPU "AMD64"
#elif defined(__arm__) || defined(_ARM) || defined (_M_ARM) || defined(__arm)
#define SVM_PLATFORM_CPU_ARM
#define SVM_PLATFORM_CPU "ARM"
#elif defined(__aarch64__)
#define SVM_PLATFORM_CPU_ARM64
#define SVM_PLATFORM_CPU "ARM64"
#elif defined(i386) || defined(__i386) || defined(__i386__) ||\
	defined(__i486__) || defined(__i586__) || defined(__i686__) ||\
	defined(__IA32__) || defined(_M_I86) || defined(_M_IX86) || defined(__X86__)
#define SVM_PLATFORM_CPU_X86
#define SVM_PLATFORM_CPU "x86"
#elif defined(__ia64__) || defined(_IA64) || defined(__ia64) || defined(_M_IA64) || defined(__itanium__)
#define SVM_PLATFORM_CPU_IA64
#define SVM_PLATFORM_CPU "IA-64"
#else
#define SVM_PLATFORM_CPU_UNKNOWN
#define SVM_PLATFORM_CPU "Unknown"
#endif