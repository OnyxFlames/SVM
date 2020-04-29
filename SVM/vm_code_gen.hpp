#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <initializer_list>

#include "object_type.hpp"

/*
	Generates code for the VM to compile with

*/

std::string generate_macro_header(
	const std::string name,
	const std::vector<std::string> args);

std::string generate_switch_header(const std::string pred);

std::string generate_switch_case(const uint16_t value);
std::string generate_break();

std::string generate_switch_footer();

std::string get_type_accessor(ObjectType type);
uint16_t get_type_pair(ObjectType type1, ObjectType type2);

void generate_object_arith(const std::string output);