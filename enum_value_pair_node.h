#pragma once
#include "non_terminal_node.h"
#include "terminal_node.h"
namespace Serialization {
	class Compiler;
	class enum_value_pair_node : public non_terminal_node
	{
	public:				
		enum_value_pair_node(Compiler *compiler, int lineno, NodeType type, const std::string& value)
			:non_terminal_node(compiler, lineno, type, value)
		{
		}
		virtual void walk1();
	};
};