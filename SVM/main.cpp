
#include "argument_handler.hpp"

#include "file_util.hpp"

#include "svm_version.hpp"
#include "platform.hpp"

#include "object.hpp"
#include "code_buffer.hpp"
#include "opcode.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	ArgumentHandler args(argc, argv);

	args.eval();

	auto& f = args.flags();

	if (f.run_builtin_test)
	{
		CodeBuffer cbuff;

		cbuff.write(
		{
			LoadConstant, 0x00, 0x01,
			Add,
			Sub,
			Mul,
			Halt,
		});

		uint8_t* code = cbuff.get();
		for (size_t i = 0; i < cbuff.size(); i += width(static_cast<Opcode>(*code)))
		{
			code = cbuff.get() + i;
			std::cout << format(code) << '\n';
		}
	}
	else if (f.print_version)
	{
		printf("Sapphire Virtual Machine:\n\t%s\n\t%s\n", SVM_FULL_VERSION, SVM_PLATFORM_FULL);
	}

	return 0;
}