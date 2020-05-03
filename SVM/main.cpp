
#include "argument_handler.hpp"

int main(int argc, char* argv[])
{
	ArgumentHandler args(argc, argv);

	args.eval();

	auto& f = args.flags();

	if (f.run_builtin_test)
	{
		printf("No built-in test.\n");
	}

	return 0;
}