
#include "argument_handler.hpp"

#include "file_util.hpp"

int main(int argc, char* argv[])
{
	ArgumentHandler args(argc, argv);

	args.eval();

	auto& f = args.flags();

	if (f.run_builtin_test)
	{
		printf("Extension of %s: %s\n", "test.svm", get_extension("test.svm").c_str());
	}

	return 0;
}