#pragma once

#include <string>
#include <vector>

struct ArgumentFlags
{

	bool run_prog : 1;
	bool run_assembler : 1;
	bool run_disassembler : 1;
	bool run_debugger : 1;
	bool print_usage : 1;
	bool print_version : 1;
	bool run_builtin_test : 1;

	std::vector<std::string> file_args;

	ArgumentFlags()
		:	run_prog(0)
		,	run_assembler(0)
		,	run_disassembler(0)
		,	run_debugger(0)
		,	print_usage(0)
		,	print_version(0)
		,	run_builtin_test(0)
	{

	}

	void clear()
	{
		*this = ArgumentFlags();
	}
};

class ArgumentHandler
{
private:
	std::vector<std::string> mArgs;

	ArgumentFlags mFlags;
public:
	ArgumentHandler(int _argc, char* _argv[]);

	void eval();

	ArgumentFlags& flags();
};