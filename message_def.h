#pragma once
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include "field_def.h"
#include "thing_def.h"
namespace Serialization
{
	class type;
	class Compiler;
	struct enum_def;
	struct message_def: public thing_def
	{	
	public:
		std::vector<thing_def*> children_thing_def_vector;
		std::map<std::string, thing_def*> children_thing_def_map;

	public:
		uint32_t msg_id;					
		std::vector<field_def*> def_list;
		std::map<std::string, field_def*> def_map;		
		std::map<uint32_t, field_def*> seq_def_map;
		message_def(Compiler *compiler, const std::string& name, message_def* parent_msg_def);
		void add_child(thing_def* child_def);
		virtual ~message_def();
		field_def* get_a_field(uint32_t seq);
		void free_all_children_def();

		void gen_id();		
	};
}
