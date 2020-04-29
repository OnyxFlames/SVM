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
	uint8_t bytecode[] = 
	{
		LoadConstant, 0x00, 0x00,
		LoadWideConstant, 0x00, 0x00, 0x01,
	};

	Chunk chunk;
	chunk.addConstant(Object("Hello world!"));
	chunk.addConstant(Object("Goodbye, world!"));
	std::cout
		<< format(bytecode, &chunk) << '\n'
		<< format(bytecode + width(LoadConstant), &chunk);


	return 0;
}