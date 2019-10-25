#pragma once
#include <map>
#include <vector>
namespace Serialization
{
	class type;
	struct message_def;
	class Compiler;
	struct thing_def
	{
	public:
		Compiler* compiler;
		std::string name;
		message_def * parent_message_def;
		static std::vector<thing_def*> all_top_thing_def_vector;
		static std::map<std::string, thing_def*> all_top_thing_def_map;
		
	public:
		thing_def(Compiler *compiler, const std::string& name, message_def* parent_message_def);
		virtual ~thing_def();
		std::string get_full_name() const;
		static void free_all_thing_def();
		bool is_repeated_definition(const std::string &symbol_name);
		
	};
}
