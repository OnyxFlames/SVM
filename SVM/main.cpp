
#include "argument_handler.hpp"

#include "file_util.hpp"

#include "svm_version.hpp"
#include "platform.hpp"

#include "object.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
	ArgumentHandler args(argc, argv);

	args.eval();

	auto& f = args.flags();

	if (f.run_builtin_test)
	{
		Object obj(0xdeadbeef);
		
		for (auto c : Object::to_bytes(obj))
			printf("%02X", c);

	}
	else if (f.print_version)
	{
		printf("Sapphire Virtual Machine:\n\t%s\n\t%s\n", SVM_FULL_VERSION, SVM_PLATFORM_FULL);
	}

	return 0;
}