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
	struct message_def;
	struct enum_def: public thing_def
	{
		int current_value;
		std::map<std::string, int> def_map;
		std::vector<std::pair<std::string, int>> def_vector;
		enum_def(Compiler *compiler, const std::string& name, message_def* parent_thing_def);
		virtual ~enum_def();
		bool add_an_enum_value(const std::pair<std::string, int>& a_pair);
		bool if_enum_value_conflict(const std::string& enum_value);
	
	};
}
