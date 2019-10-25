#pragma once
#include <vector>
#include <string>
#include <stdlib.h>
#include "parser_tree.h"
#include "common_enum.h"
namespace Serialization {
	class Compiler;
	class terminal_node : public parser_node
	{
	public:
		DataType type_;
		std::string string_value_;
		bool use_str_;
		union
		{
			uint8_t byte_value_;
			int16_t short_value_;
			int32_t int_value_;
			bool bool_value_;
			long long long_value_;
			float float_value_;
			double double_value_;
			
			void *null_value_;
		};


		terminal_node(Compiler *compiler, int lineno, DataType type, const std::string& str)
			:parser_node(compiler, lineno)			
			, type_(type)
			, string_value_(str)
			, use_str_(true)
		{
			switch (type_)
			{
			case BYTE_TYPE:				
				byte_value_ = atoi(string_value_.c_str());
				break;
			case SHORT_TYPE:
				short_value_ = atoi(string_value_.c_str());
				break;
			case INT_TYPE:
				int_value_ = atoi(string_value_.c_str());
				break;
			case LONG_TYPE:
				long_value_ = atoll(string_value_.c_str());
				break;
			case FLOAT_TYPE:
				float_value_ = (float)(atof(string_value_.c_str()));
				break;
			case DOUBLE_TYPE:
				double_value_ = atof(string_value_.c_str());
				break;
			}
		}
		terminal_node(Compiler *compiler, int lineno, uint8_t byte_value)
			:parser_node(compiler, lineno)
			, byte_value_(byte_value)
			, type_(BYTE_TYPE)
			, use_str_ (false)
		{
		}

		terminal_node(Compiler *compiler, int lineno, int16_t short_value)
			:parser_node(compiler, lineno) 
			, short_value_(short_value)
			, type_(SHORT_TYPE)
			, use_str_(false)
		{
		}

		terminal_node(Compiler *compiler, int lineno, int32_t int_value)
			:parser_node(compiler, lineno) 
			, int_value_(int_value)
			, type_(INT_TYPE)
			, use_str_(false)
		{
		}
		terminal_node(Compiler *compiler, int lineno, bool bool_value)
			:parser_node(compiler, lineno) 
			, bool_value_(bool_value)
			, type_(BOOL_TYPE)
			, use_str_(false)
		{
		}

		terminal_node(Compiler *compiler, int lineno, long long long_value)
			:parser_node(compiler, lineno)
			, long_value_(long_value)
			, type_(LONG_TYPE)
			, use_str_(false)
		{
		}

		terminal_node(Compiler *compiler, int lineno, float float_value)
			:parser_node(compiler, lineno)
			, float_value_(float_value)
			, type_(FLOAT_TYPE)
			, use_str_(false)
		{
		}

		terminal_node(Compiler *compiler, int lineno, double double_value)
			:parser_node(compiler, lineno)
			, double_value_(double_value)
			, type_(DOUBLE_TYPE)
			, use_str_(false)
		{
		}

		terminal_node(Compiler *compiler, int lineno, std::string string_value)
			:parser_node(compiler, lineno)
			, string_value_(string_value)
			, type_(STRING_TYPE)
			, use_str_(true)
		{
		}

		terminal_node(Compiler *compiler, int lineno, void *null_value)
			:parser_node(compiler, lineno)
			, null_value_(null_value)
			, type_(NULL_TYPE)
			, use_str_(false)
		{
		}

		terminal_node& operator = (uint8_t byte_value)
		{
			byte_value_ = byte_value;
			type_ = BYTE_TYPE;
			use_str_ = false;
			return *this;
		}

		terminal_node& operator = (int16_t short_value)
		{
			short_value_ = short_value;
			type_ = SHORT_TYPE;
			use_str_ = false;
			return *this;

		}

		terminal_node& operator = (int32_t int_value)
		{
			int_value_ = int_value_;
			type_ = INT_TYPE;
			use_str_ = false;
			return *this;
		}
		terminal_node& operator = (bool bool_value)
		{
			bool_value_ = bool_value;
			type_ = BOOL_TYPE;
			use_str_ = false;
			return *this;
		}

		terminal_node& operator = (long long long_value)
		{
			long_value_ = long_value;
			type_ = LONG_TYPE;
			use_str_ = false;
			return *this;
		}

		terminal_node& operator = (float float_value)
		{
			float_value_ = float_value;
			type_ = FLOAT_TYPE;
			use_str_ = false;
			return *this;

		}

		terminal_node& operator = (double double_value)
		{
			double_value_ = double_value;
			type_ = DOUBLE_TYPE;
			use_str_ = false;
			return *this;
		}

		terminal_node& operator = (std::string string_value)
		{
			new(&string_value_) std::string(); //reconstruct the string because of bad memory caused by other union members.
			string_value_ = string_value;
			type_ = STRING_TYPE;
			use_str_ = true;
			return *this;

		}

		terminal_node& operator = (void *null_value)
		{
			null_value_ = null_value;
			type_ = NULL_TYPE;
			use_str_ = false;
			return *this;
		}
		
		virtual void walk1() {}

		virtual ~terminal_node() {}
	};
}