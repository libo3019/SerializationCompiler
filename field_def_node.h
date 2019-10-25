#pragma once
#include "non_terminal_node.h"
#include "terminal_node.h"
namespace Serialization {
	class Compiler;
	class field_def_node : public non_terminal_node
	{
	public:				
		field_def_node(Compiler *compiler, int lineno, NodeType type, int value)
			:non_terminal_node(compiler, lineno, type, value)
		{
		}
		virtual void walk1();
		virtual void walk2();
	};
};