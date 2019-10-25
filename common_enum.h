#pragma once
#include <vector>
#include <string>
#include <stdarg.h>

namespace Serialization {		
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
		ESerializeType_NAME, //16
		ESerializeType_ENUM,
		ESerializeType_MESSAGE,
		ESerializeType_MSG_START_ID, //17
	};

	enum type_category
	{
		TYPE_CATEGORY_UNKOWN = -1,
		TYPE_CATEGORY_NULL,
		TYPE_CATEGORY_BASIC,
		TYPE_CATEGORY_LIST,
		TYPE_CATEGORY_VECTOR,
		TYPE_CATEGORY_SET,
		TYPE_CATEGORY_MAP,
		TYPE_CATEGORY_NAME,
		TYPE_CATEGORY_MESSAGE,
		TYPE_CATEGORY_ENUM,
	};

	enum EMessageType
	{
		UNKNOWN_MESSAGE_TYPE,
		STRUCT_MESSAGE_TYPE,
	};
	enum DataType
	{
		NULL_TYPE = 0,
		BYTE_TYPE,
		CHAR_TYPE,
		SHORT_TYPE,
		INT_TYPE,
		BOOL_TYPE,
		LONG_TYPE,
		FLOAT_TYPE,
		DOUBLE_TYPE,
		STRING_TYPE,
		PRIMARY_TYPE,
		COMPLEX_TYPE,
		CLASS_OR_INTERFACE_TYPE,
		CLASS_TYPE,
		INTERFACE_TYPE,
		ARRAY_TYPE,
		GENERIC_TYPE, //32bit system: 4 bytes address, 64bit system: 8 bytes address
		AUTO_TYPE,
		VOID_TYPE,
		UNKNOWN_TYPE,

	};
	enum NodeType
	{
		message_list_enum_product_node,
		message_list_msg_product_node,
		message_def_product_node,	
		def_list_field_product_node,
		field_def_product_node,
		type_basic_type_product_node,		
		list_type_product_node,
		set_type_product_node,
		map_type_product_node,		
		pkg_def_product_node,
		msg_or_enum_type_product_node,
		start_symbol_product_node,
		vector_type_product_node,
		def_list_msg_product_node,
		type_container_type_product_node,
		type_message_type_product_node,
		enum_value_pair_product_node,
		enum_value_list_no_comma_product_node,
		enum_def_product_node,
		def_list_enum_product_node,
		optional_default_value_literal_product_node,
		optional_default_value_noliteral_product_node,
	};

}