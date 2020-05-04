#pragma once

#include "common.hpp"

class Object;

union ObjectData
{
	int8_t i8;
	uint8_t u8;

	int16_t i16;
	uint16_t u16;

	int32_t i32;
	uint32_t u32;
	
	float f32;
	
#if defined(SVM_64BIT)
	double f64;
	int64_t i64;
	uint64_t u64;
#endif
	char* cstr;

	FILE* file;

	Object* obj;

	// default value
	ObjectData()
	{
		obj = nullptr;
	}
};

