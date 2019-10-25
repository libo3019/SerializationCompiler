#pragma once
#include "non_terminal_node.h"
#include "terminal_node.h"
namespace Serialization {
	class Compiler;
	class type_node : public non_terminal_node
	{
	public:		
		type_node(Compiler *compiler, int lineno, NodeType type, int value)
			:non_terminal_node(compiler, lineno, type, value)
		{
		}
		type_node(Compiler *compiler, int lineno, NodeType type, const std::string& value)
			:non_terminal_node(compiler, lineno, type, value)
		{
		}
		type_node(Compiler *compiler, int lineno, NodeType type, parser_node *node)
			:non_terminal_node(compiler, lineno, type, node)
		{
		}
		virtual void walk1();
	};
};