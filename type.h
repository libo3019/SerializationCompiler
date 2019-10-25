#pragma once
#include "common_enum.h"
#include <string>
#include <list>
#include "compiling_time_exception.h"
#include <assert.h>
namespace Serialization
{	
	struct thing_def;
	struct message_def;
	class type
	{
	public:
		ESerializeType serialize_type;
		type* first_elem_type;
		type* second_elem_type;
		thing_def* the_thing_def;
		std::string type_name;
		EMessageType msg_type;
		static std::list<type*> all_type;
	public:
		uint32_t get_basic_type_size() const;
		ESerializeType get_serial_type() const;
		type(ESerializeType serialize_type);
		type(ESerializeType serialize_type, type* first_elem_type);
		type(ESerializeType serialize_type, type* first_elem_type, type* second_elem_type);
		type(ESerializeType serialize_type, const std::string& type_name);
		type_category get_category() const;
		static void free_all_type();
		void set_thing_def(message_def *current_message_def);

		std::string get_c_name() const;
		std::string get_relative_c_name(const std::vector<std::string> &klass_stack) const;
		uint32_t get_type_id() const;
		bool is_container() const;
		bool is_right_enum_value(const std::string& value) const;
	};
}
