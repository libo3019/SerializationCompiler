#pragma once
#include "non_terminal_node.h"
#include "terminal_node.h"
namespace Serialization {
	class Compiler;
	class optional_default_value_node : public non_terminal_node
	{
	public:				
		optional_default_value_node(Compiler *compiler, int lineno, NodeType type, parser_node* node)
			:non_terminal_node(compiler, lineno, type, node)
		{
		}
		optional_default_value_node(Compiler *compiler, int lineno, NodeType type)
			:non_terminal_node(compiler, lineno, type)
		{
		}
		virtual void walk1();
		virtual void walk2();
	};
};