#pragma once
#include <list>
#include <vector>
#include <string>
namespace Serialization {
	class Compiler;
	class parser_node
	{
	public:
		void *properties;
		parser_node* parent;
		std::vector<parser_node*> children;
		int lineno;
		Compiler* compiler;
		
		static std::list<parser_node*> all_nodes;		
		
		parser_node(Compiler *compiler, int lineno);
		virtual ~parser_node();
		
		void set_properties(void *properties)
		{
			this->properties = properties;
		}
	
		void* get_properties() 
		{
			return properties;
		}
		
		void add_child(parser_node* child);

		void traverse(void (*func)(parser_node *));
		
		virtual void walk1() = 0;

		virtual void walk2();

		static std::string int_to_str(int val);

		static int str_to_int(const std::string& str);

		static void freeAllNodes();
		
	};

	typedef parser_node parser_tree;
}