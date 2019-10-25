#pragma once
#include <vector>
#include <string>
#include <gc.h>
#include "common_enum.h"
#include "parser_tree.h"
#include "terminal_node.h"
namespace Serialization {
	class Compiler;
	class non_terminal_node : public parser_node
	{
	public:
		NodeType type_;
		non_terminal_node(Compiler *compiler, int lineno)
			:parser_node(compiler, lineno)
			{}
		non_terminal_node(Compiler *compiler, int lineno, NodeType type)
			:parser_node(compiler, lineno)
			,type_(type)
			{}
		virtual ~non_terminal_node() {}
		virtual void non_virtual_def() {}
		non_terminal_node(Compiler *compiler, int lineno, NodeType type, uint8_t byte_value)
			:parser_node(compiler, lineno)
			, type_(type)
		{
			terminal_node *terminal_node_ptr = new terminal_node(compiler, lineno, byte_value);
			add_child(terminal_node_ptr);
		}

		non_terminal_node(Compiler *compiler, int lineno, NodeType type, int16_t short_value)
			:parser_node(compiler, lineno)
			, type_(type)
		{
			terminal_node *terminal_node_ptr = new terminal_node(compiler, lineno, short_value);
			add_child(terminal_node_ptr);
		}

		non_terminal_node(Compiler *compiler, int lineno, NodeType type, int32_t char_value)
			:parser_node(compiler, lineno)
			,type_(type)
		{
			terminal_node *terminal_node_ptr = new terminal_node(compiler, lineno, char_value);
			add_child(terminal_node_ptr);
		}
		non_terminal_node(Compiler *compiler, int lineno, NodeType type, bool bool_value)
			:parser_node(compiler, lineno)
			, type_(type)
		{
			terminal_node *terminal_node_ptr = new terminal_node(compiler, lineno, bool_value);
			add_child(terminal_node_ptr);
		}

		non_terminal_node(Compiler *compiler, int lineno, NodeType type, long long long__value)
			:parser_node(compiler, lineno)
			, type_(type)
		{
			terminal_node *terminal_node_ptr = new terminal_node(compiler, lineno, long__value);
			add_child(terminal_node_ptr);
		}

		non_terminal_node(Compiler *compiler, int lineno, NodeType type, float float_value)
			:parser_node(compiler, lineno)
			, type_(type)
		{
			terminal_node *terminal_node_ptr = new terminal_node(compiler, lineno, float_value);
			add_child(terminal_node_ptr);
		}

		non_terminal_node(Compiler *compiler, int lineno, NodeType type, double double_value)
			:parser_node(compiler, lineno)
			, type_(type)
		{
			terminal_node *terminal_node_ptr = new terminal_node(compiler, lineno, double_value);
			add_child(terminal_node_ptr);
		}

		non_terminal_node(Compiler *compiler, int lineno, NodeType type, std::string string_value)
			:parser_node(compiler, lineno)
			, type_(type)
		{
			terminal_node *terminal_node_ptr = new terminal_node(compiler, lineno, string_value);
			add_child(terminal_node_ptr);
		}

		non_terminal_node(Compiler *compiler, int lineno, NodeType type, void *null_value)
			:parser_node(compiler, lineno)
			, type_(type)
		{
			terminal_node *terminal_node_ptr = new terminal_node(compiler, lineno, null_value);
			add_child(terminal_node_ptr);
		}

		non_terminal_node(Compiler *compiler, int lineno, NodeType type, parser_node *node)
			:parser_node(compiler, lineno)
			, type_(type)
		{
			add_child(node);
		}
	};
}