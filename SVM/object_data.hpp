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
	
	int64_t i64;
	uint64_t u64;
	
	float f32;
	
	double f64;
	

	char* cstr;

	Object* obj;
};

