#include "argument_handler.hpp"

#include "common.hpp"
#include "file_util.hpp"

#if defined(SVM_DEVELOPER_FEATURES)
#include "vm_code_gen.hpp"
#endif
ArgumentHandler::ArgumentHandler(int _argc, char* _argv[])
{
	mArgs.resize(_argc);

	for (int i = 1; i < _argc; ++i)
		mArgs[i] = _argv[i];
}

void ArgumentHandler::eval()
{
#define curr(str) (mArgs[i] == str)
#define get_curr() (mArgs[i])
#define prev(str) (i > 1 ? mArgs[i - 1] == str : "" == str)
#define next(str) (i + 1 < mArgs.size() ? mArgs[i + 1] == str : "" == str)
#define get_next() (i + 1 < mArgs.size() ? mArgs[i + 1]  : "")
#define has_next() (i + 1 < mArgs.size())


	for (size_t i = 0; i < mArgs.size(); ++i)
	{
		if (curr("-h") || curr("--help"))
		{
			mFlags.clear();
			mFlags.print_usage = true;
			return;
		}
		else if (curr("-v") || curr("--version"))
		{
			mFlags.clear();
			mFlags.print_version = true;
			return;
		}
		else if (curr("-a") && has_next())
		{
			mFlags.run_assembler = true;
			// TODO: implement assembler
		}
		else if (curr("-d") && has_next())
		{
			mFlags.run_disassembler = true;
			// TODO: implement disassembler
		}
		else if (curr("-D") && has_next())
		{
			mFlags.run_debugger = true;
			// TODO: implement debugger
		}
#if defined(SVM_DEVELOPER_FEATURES)
		else if (curr("--generate-vm-code"))
		{
			// generate inline
			if (!has_next())
				generate_object_arith("vm_code.inl");
			else
				generate_object_arith(get_next());
		}
#endif
		else if (get_extension(get_curr()) == ".svmc")
		{
			mFlags.run_prog = true;
			mFlags.file_args.push_back(get_curr());
		}
		else if (curr("--test"))
		{
			mFlags.run_builtin_test = true;
		}
	}
}

ArgumentFlags& ArgumentHandler::flags()
{
	return mFlags;
}
