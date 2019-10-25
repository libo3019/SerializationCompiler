#pragma once
#include <map>
#include <string>
#include <vector>
#include <set>
#include <stack>
namespace Serialization
{
	class type;
	struct field_def;	
	struct message_def;
	struct enum_def;
	class const_value;
	class CompilerContext
	{
	public:	
		std::vector<std::string> klass_stack;
		type * current_type;
		field_def* current_field;
		std::pair<std::string, int> value_pair;
		std::stack<message_def*> current_message_def;
		enum_def *current_enum_def;
		const_value *a_const_value;
		CompilerContext();
		virtual ~CompilerContext();			
	};
}