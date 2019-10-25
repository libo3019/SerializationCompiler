#pragma once
#include "non_terminal_node.h"
#include "terminal_node.h"
namespace Serialization {
	class Compiler;
	class msg_enum_list_node : public non_terminal_node
	{
	public:				
		msg_enum_list_node(Compiler *compiler, int lineno, NodeType type, parser_node* node)
			:non_terminal_node(compiler, lineno, type, node)
		{
		}
		virtual void walk1();
	};
};