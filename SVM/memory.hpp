#pragma once

#define MIN_CAPACITY 8
#define GROWTH_RATE 2

static_assert(GROWTH_RATE > 1, "Growth rate must be higher than 1");

#define grow_capacity(cap)\
	((cap) < MIN_CAPACITY ? MIN_CAPACITY : (cap) * GROWTH_RATE)

#define grow_array(arr, type, oldcap, newcap)\
	static_cast<type*>(reallocate(arr, sizeof(type) * oldcap, sizeof(type) * newcap))

#define free_array(type, arr, oldcap)\
	reallocate(arr, sizeof(type) * (oldcap), 0)

void* reallocate(void* prev, size_t old_size, size_t new_size);