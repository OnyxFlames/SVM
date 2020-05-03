#pragma once

#include "common.hpp"

#include <string>

enum Opcode : uint8_t
{
	Halt,
	Yield,

	LoadConstant,
	LoadWideConstant,

	Pop,
	Swap,

	Add,
	Sub,
	Mul,
	Div,
	Mod,
	LShift,
	RShift,

	LoadIndex,
	/*
	Stack:
		[index]
		[array]
	->
		[object]
	*/

	StoreIndex,
	/*
	Stack:
		[object]
		[index]
		[array]
	->
		[]
	*/

	Compare,

	IfLT_Jump,
	IfLTE_Jump,
	IfNEQ_Jump,
	IfEQ_Jump,
	IfGTE_Jump,
	IfGT_Jump,

	Call,
	// should Return give the number of values returned? eg Return 2
	Return,


	OPCODE_COUNT,
};

enum OpcodeFormat
{
	NoFormat,
	
	// show constant
	ConstantOffset,
	WideConstantOffset,

	// show section if available
	CodeOffset,
	
	SingleByte,
	DoubleByte,
	TripleByte,
};

std::string to_string(Opcode opcode);

int8_t width(Opcode opcode);

class Chunk;

std::string format(const uint8_t* code, Chunk* chunk = nullptr);
