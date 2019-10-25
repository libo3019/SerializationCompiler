#pragma once
#include "non_terminal_node.h"
#include "terminal_node.h"
namespace Serialization {
	class Compiler;
	class msg_or_enum_type_node : public non_terminal_node
	{
	public:				
		msg_or_enum_type_node(Compiler *compiler, int lineno, NodeType type, const std::string& str)
			:non_terminal_node(compiler, lineno, type, str)
		{
		}
		virtual void walk1();
	};
};