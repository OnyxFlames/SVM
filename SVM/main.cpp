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

	generate_object_arith("output.inl");

	return 0;
}