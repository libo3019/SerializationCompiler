#pragma once
#include <string>
#include <list>
#include <cstdint>
#include "const_value.h"
namespace Serialization
{
	class type;
	struct field_def
	{
		bool optional;
		type* field_type;
		std::string field_name;
		uint32_t seq;
		const_value *a_const_value;
		static std::list<field_def*> all_field_def;
		field_def()
		{
			all_field_def.push_back(this);
			a_const_value = NULL;
		}
		virtual ~field_def()
		{
			if (a_const_value != NULL)
			{
				delete a_const_value;
			}
		}
		static void free_all_field_def()
		{
			std::list<field_def*>::iterator it;
			for (it = all_field_def.begin(); it != all_field_def.end(); ++it)
			{
				delete (*it);
			}
			all_field_def.clear();
		}
	};
}
