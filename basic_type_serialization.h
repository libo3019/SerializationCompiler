#pragma once
#include <stdint.h>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <map>
#include "DLL.h"

namespace Serialization
{	
	enum ESerializeType
	{
		ESerializeType_NULL_TYPE = 0,
		ESerializeType_INT8_TYPE, //1
		ESerializeType_UINT8_TYPE, //2
		ESerializeType_INT16_TYPE, //3
		ESerializeType_UINT16_TYPE, //4
		ESerializeType_INT32_TYPE, //5
		ESerializeType_UINT32_TYPE, //6
		ESerializeType_INT64_TYPE, //7
		ESerializeType_UINT64_TYPE, //8
		ESerializeType_FLOAT32_TYPE, //9
		ESerializeType_FLOAT64_TYPE, //10
		ESerializeType_STRING_TYPE,	//11
		ESerializeType_MAX_BASIC_TYPE = ESerializeType_STRING_TYPE, //11				
		ESerializeType_LIST, //12
		ESerializeType_VECTOR, //13
		ESerializeType_SET, //14
		ESerializeType_MAP, //15		
		ESerializeType_MSG, //16
		ESerializeType_MSG_START_ID, //17
	};
	class DLL_EXPORT_IMPORT field_null_exception
	{
		std::string *field_name;
	public:
		field_null_exception(const char *field_name);
		field_null_exception(const std::string& field_name);
		const std::string& get_field_name() const;
		~field_null_exception();
	};
	class DLL_EXPORT_IMPORT basic_type
	{
	public:
		static bool is_number_type(uint32_t type);
		static uint32_t get_number_type_size(uint32_t type);
		static void serialize(int8_t f, std::basic_string<unsigned char>& buf);
		static void serialize(int16_t f, std::basic_string<unsigned char>& buf);
		static void serialize(int32_t f, std::basic_string<unsigned char>& buf);
		static void serialize(int64_t f, std::basic_string<unsigned char>& buf);
		static void serialize(uint8_t f, std::basic_string<unsigned char>& buf);
		static void serialize(uint16_t f, std::basic_string<unsigned char>& buf);
		static void serialize(uint32_t f, std::basic_string<unsigned char>& buf);
		static void serialize(uint64_t f, std::basic_string<unsigned char>& buf);
		static void serialize(float f, std::basic_string<unsigned char>& buf);
		static void serialize(double f, std::basic_string<unsigned char>& buf);
		static void serialize(const std::string& f, std::basic_string<unsigned char>& buf);
		static int deserialize(int8_t &f, const void *buf, size_t &pos, size_t size);
		static int deserialize(int16_t &f, const void *buf, size_t &pos, size_t size);
		static int deserialize(int32_t &f, const void *buf, size_t &pos, size_t size);
		static int deserialize(int64_t &f, const void *buf, size_t &pos, size_t size);
		static int deserialize(uint8_t &f, const void *buf, size_t &pos, size_t size);
		static int deserialize(uint16_t &f, const void *buf, size_t &pos, size_t size);
		static int deserialize(uint32_t &f, const void *buf, size_t &pos, size_t size);
		static int deserialize(uint64_t &f, const void *buf, size_t &pos, size_t size);
		static int deserialize(float &f, const void *buf, size_t &pos, size_t size);
		static int deserialize(double &f, const void *buf, size_t &pos, size_t size);
		static int deserialize(std::string &f, const void *buf, size_t &pos, size_t size, size_t string_size);
	};	
}

