#pragma once
#include "non_terminal_node.h"
#include "terminal_node.h"
namespace Serialization {
	class Compiler;
	class start_symbol_node : public non_terminal_node
	{
	public:				
		start_symbol_node(Compiler *compiler, int lineno, NodeType type, const std::string& str)
			:non_terminal_node(compiler, lineno, type, str)
		{
		}
		virtual void walk1();
		virtual void walk2();
	};
};