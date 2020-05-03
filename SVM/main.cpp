#include <iostream>
#include <fstream>

#include "debug.hpp"
#include "object_type.hpp"
#include "object_type_traits.hpp"
#include "vm_code_gen.hpp"

#include "object.hpp"

#include "allocator.hpp"

#include "opcode.hpp"

#include "chunk.hpp"

int main(int argc, char* argv[])
{
	{
		Object hi("Goodbye");
		Object place(" cruel world!\n");
		Object hi_place = hi + place;
		hi_place = place + hi;
		std::cout << hi_place.str();
	}

	return 0;
}