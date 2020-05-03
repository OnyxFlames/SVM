#include "vm_code_gen.hpp"

#include <fstream>
#include <sstream>

#include "object_type.hpp"
#include "object_type_traits.hpp"

std::string generate_macro_header(const std::string name, const std::vector<std::string> args)
{
	std::stringstream ss;

	ss << "#define " << name << '(';

	for (size_t i = 0; i < args.size(); ++i)
		ss << args[i] << (i + 1 == args.size() ? ")\\\n" : ", ");

	return ss.str();
}

std::string generate_switch_header(const std::string pred)
{
	std::stringstream ss;

	ss << "switch (" << pred << ")\\\n{\\\n";

	return ss.str();
}

std::string generate_switch_case(const uint16_t value)
{
	std::stringstream ss;

	ss << "case " << value << ": ";

	return ss.str();
}

std::string generate_break()
{
	std::stringstream ss;

	ss << "break;\\\n";

	return ss.str();
}

std::string generate_switch_footer()
{
	std::stringstream ss;

	ss << "default: assert(false && \"Reached end of switch\"); break;\\\n}\\\n";

	return ss.str();
}

std::string get_type_accessor(ObjectType type)
{
	switch (type)
	{
	case ObjectType::Nil: return "";
	case ObjectType::Int8: return ".i8";
	case ObjectType::UInt8: return ".u8";
	case ObjectType::Int16: return ".i16";
	case ObjectType::UInt16: return ".u16";
	case ObjectType::Int32: return ".i32";
	case ObjectType::UInt32: return ".u32";
	case ObjectType::Int64: return ".i64";
	case ObjectType::UInt64: return ".u64";
	case ObjectType::Float32: return ".f32";
	case ObjectType::Float64: return ".f64";
	case ObjectType::String: return ".cstr";
	case ObjectType::SVMObject: return ".obj";
	default: return "";
	}
}

uint16_t get_type_pair(ObjectType type1, ObjectType type2)
{
	return static_cast<uint8_t>(type1) + (static_cast<uint8_t>(type2) << 8);
}

// TODO: Add special cases for 64 bit objects on 32 bit archs

void generate_object_arith(const std::string output)
{
	std::ofstream output_file(output);

	output_file
		<< generate_numeric32_binary_arith()
		<< generate_integral32_binary_arith()
		<< generate_numeric64_binary_arith()
		<< generate_integral64_binary_arith();

}

std::string generate_numeric32_binary_arith()
{
	std::stringstream output_file;

	output_file
		<< generate_macro_header("OBJECT_NUMERIC_ARITH32", { "ret", "obj1", "obj2", "op" })
		<< generate_switch_header("get_type_pair(obj1.getType(), obj2.getType())");

	for (uint8_t x = 0; x < ObjectType::TypeCount; ++x)
	{
		for (uint8_t y = 0; y < ObjectType::TypeCount; ++y)
		{
			const ObjectType type1 = static_cast<ObjectType>(x), type2 = static_cast<ObjectType>(y);
			if (
				is_numeric(type1)
				&&
				is_numeric(type2)
				&& (width(type1) < 8 && width(type2) < 8))
			{
				output_file
					<< generate_switch_case(get_type_pair(type1, type2))
					<< "ret = Object(obj1.getData()" << get_type_accessor(type1) << " op " << "obj2.getData()" << get_type_accessor(type2) << ");"
					<< generate_break();
			}
		}
	}

	output_file << generate_switch_footer() << '\n';

	return output_file.str();
}

std::string generate_integral32_binary_arith()
{
	std::stringstream output_file;

	output_file
		<< generate_macro_header("OBJECT_INTEGRAL_ARITH32", { "ret", "obj1", "obj2", "op" })
		<< generate_switch_header("get_type_pair(obj1.getType(), obj2.getType())");

	for (uint8_t x = 0; x < ObjectType::TypeCount; ++x)
	{
		for (uint8_t y = 0; y < ObjectType::TypeCount; ++y)
		{
			const ObjectType type1 = static_cast<ObjectType>(x), type2 = static_cast<ObjectType>(y);
			if (
				is_integral(type1)
				&&
				is_integral(type2)
				&& (width(type1) < 8 && width(type2) < 8))
			{
				output_file
					<< generate_switch_case(get_type_pair(type1, type2))
					<< "ret = Object(obj1.getData()" << get_type_accessor(type1) << " op " << "obj2.getData()" << get_type_accessor(type2) << ");"
					<< generate_break();
			}
		}
	}

	output_file << generate_switch_footer() << '\n';

	return output_file.str();
}

std::string generate_numeric64_binary_arith()
{

	std::stringstream output_file;

	output_file
		<< generate_macro_header("OBJECT_NUMERIC_ARITH64", { "ret", "obj1", "obj2", "op" })
		<< generate_switch_header("get_type_pair(obj1.getType(), obj2.getType())");

	for (uint8_t x = 0; x < ObjectType::TypeCount; ++x)
	{
		for (uint8_t y = 0; y < ObjectType::TypeCount; ++y)
		{
			const ObjectType type1 = static_cast<ObjectType>(x), type2 = static_cast<ObjectType>(y);
			if (
				is_numeric(type1)
				&&
				is_numeric(type2))
			{
				output_file
					<< generate_switch_case(get_type_pair(type1, type2))
					<< "ret = Object(obj1.getData()" << get_type_accessor(type1) << " op " << "obj2.getData()" << get_type_accessor(type2) << ");"
					<< generate_break();
			}
		}
	}

	output_file << generate_switch_footer() << '\n';

	return output_file.str();
}

std::string generate_integral64_binary_arith()
{

	std::stringstream output_file;

	output_file
		<< generate_macro_header("OBJECT_INTEGRAL_ARITH64", { "ret", "obj1", "obj2", "op" })
		<< generate_switch_header("get_type_pair(obj1.getType(), obj2.getType())");

	for (uint8_t x = 0; x < ObjectType::TypeCount; ++x)
	{
		for (uint8_t y = 0; y < ObjectType::TypeCount; ++y)
		{
			const ObjectType type1 = static_cast<ObjectType>(x), type2 = static_cast<ObjectType>(y);
			if (
				is_integral(type1)
				&&
				is_integral(type2))
			{
				output_file
					<< generate_switch_case(get_type_pair(type1, type2))
					<< "ret = Object(obj1.getData()" << get_type_accessor(type1) << " op " << "obj2.getData()" << get_type_accessor(type2) << ");"
					<< generate_break();
			}
		}
	}

	output_file << generate_switch_footer() << '\n';

	return output_file.str();
}
