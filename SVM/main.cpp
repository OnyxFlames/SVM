
#include "argument_handler.hpp"

#include "file_util.hpp"

#include "svm_version.hpp"

int main(int argc, char* argv[])
{
	ArgumentHandler args(argc, argv);

	args.eval();

	auto& f = args.flags();

	if (f.run_builtin_test)
	{
		printf("Filesize: %lld\n", get_filesize("output.inl"));
	}

	return 0;
}