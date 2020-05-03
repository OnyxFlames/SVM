#include "Opcode.hpp"

#include <sstream>
#include <iomanip>

#define opcode_str_case(op) case Opcode::op: return #op

std::string to_string(Opcode opcode)
{
	switch (opcode)
	{
		opcode_str_case(Halt);
		opcode_str_case(Yield);

		opcode_str_case(LoadConstant);
		opcode_str_case(LoadWideConstant);

		opcode_str_case(Pop);
		opcode_str_case(Swap);

		opcode_str_case(Add);
		opcode_str_case(Sub);
		opcode_str_case(Mul);
		opcode_str_case(Div);
		opcode_str_case(Mod);
		opcode_str_case(LShift);
		opcode_str_case(RShift);

		opcode_str_case(LoadIndex);
		opcode_str_case(StoreIndex);

		opcode_str_case(Compare);
		opcode_str_case(IfLT_Jump);
		opcode_str_case(IfLTE_Jump);
		opcode_str_case(IfNEQ_Jump);
		opcode_str_case(IfEQ_Jump);
		opcode_str_case(IfGTE_Jump);
		opcode_str_case(IfGT_Jump);

		opcode_str_case(Call);
		opcode_str_case(Return);

	default: return "Unknown Opcode";
	}
}

int8_t width(Opcode opcode)
{

	switch (opcode)
	{
	case Halt: return 1;
	case Yield: return 1;

	case LoadConstant: return 3;
	case LoadWideConstant: return 4;

	case Pop: return 1;
	case Swap: return 1;

	case Add: return 1;
	case Sub: return 1;
	case Mul: return 1;
	case Div: return 1;
	case Mod: return 1;
	case LShift: return 1;
	case RShift: return 1;

	case LoadIndex: return 1;
	case StoreIndex: return 1;

	case Compare: return 1;
	case IfLT_Jump: return 4;
	case IfLTE_Jump: return 4;
	case IfNEQ_Jump: return 4;
	case IfEQ_Jump: return 4;
	case IfGTE_Jump: return 4;
	case IfGT_Jump: return 4;

	case Call: return 4;
	case Return: return 1;


	default: return -1;
	}

}

const OpcodeFormat _opcode_format[Opcode::OPCODE_COUNT]
{
	NoFormat,
	NoFormat,

	ConstantOffset,
	WideConstantOffset,

	NoFormat,
	NoFormat,

	NoFormat,
	NoFormat,
	NoFormat,
	NoFormat,
	NoFormat,
	NoFormat,

	NoFormat,
	NoFormat,

	NoFormat,

	CodeOffset,
	CodeOffset,
	CodeOffset,
	CodeOffset,
	CodeOffset,
	CodeOffset,

	CodeOffset,

	NoFormat,

};

#include "chunk.hpp"

std::string format(const uint8_t* code, Chunk* chunk)
{
	assert(code != nullptr && "invalid opcode stream");
	Opcode op = static_cast<Opcode>(*code);

	OpcodeFormat format = _opcode_format[static_cast<uint8_t>(op)];

	std::stringstream ss;

	ss << to_string(op);

	switch (format)
	{
	case NoFormat: break;
	case ConstantOffset:
		ss << " 0x";
		ss << std::hex << std::setfill('0') 
			<< std::setw(2) << (int16_t)code[1]
			<< std::setw(2) << (int16_t)code[2];
		if (chunk)
		{
			uint32_t offset = (code[1] << 8 | code[2] << 0);
			ss << " (" << chunk->getConstant(offset).str() 
				<< " : [" << to_string(chunk->getConstant(offset).getType()) << "])";
		}
		break;
	case WideConstantOffset:
		ss << " 0x";
		ss << std::hex << std::setfill('0')
			<< std::setw(2) << (int16_t)code[1]
			<< std::setw(2) << (int16_t)code[2]
			<< std::setw(2) << (int16_t)code[3];
		if (chunk)
		{
			uint32_t offset = (code[1] << 16 | code[2] << 8 | code[3] << 0);
			ss << " (" << chunk->getConstant(offset).str() 
				<< " : [" << to_string(chunk->getConstant(offset).getType()) << "])";
		}
		break;
	case CodeOffset:

		break;
	case SingleByte:
		ss << " 0x";
		ss << std::hex << std::setfill('0')
			<< std::setw(2) << (int16_t)code[1];
		break;
	case DoubleByte:
		ss << " 0x";
		ss << std::hex << std::setfill('0')
			<< std::setw(2) << (int16_t)code[1]
			<< std::setw(2) << (int16_t)code[2];
		break;
	case TripleByte:
		ss << " 0x";
		ss << std::hex << std::setfill('0')
			<< std::setw(2) << (int16_t)code[1]
			<< std::setw(2) << (int16_t)code[2]
			<< std::setw(2) << (int16_t)code[3];
		break;
	}

	return ss.str();

}
