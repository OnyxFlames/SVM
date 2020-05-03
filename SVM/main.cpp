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
		Object hi("Hello,");
		Object place(" World!\n");
		Object hi_place = hi + place;
		Object hello_place = Object("Goodbye world!\n");

		std::cout << hi_place.str();
	}

	{
		Object hi("Hello,");
		Object place(" World!\n");
		Object hi_place = hi + place;
		Object hello_place = Object("Goodbye world!\n");

		std::cout << hi_place.str();
	}

	return 0;
}