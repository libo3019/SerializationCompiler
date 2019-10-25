#pragma once
#include <string>
#include "DLL.h"

namespace Serialization
{
	class DLL_EXPORT_IMPORT compiling_time_exception
	{
		char *info;
	public:
		compiling_time_exception();
		compiling_time_exception(const compiling_time_exception &another);
		compiling_time_exception& operator = (const compiling_time_exception &another);
		compiling_time_exception(const std::string& info);
		compiling_time_exception(const char* info);
		virtual ~compiling_time_exception();
		const char* get_info() const;
	};
}
