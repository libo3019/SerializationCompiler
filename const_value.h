#pragma once
#include <vector>
#include <string>
#include "common_enum.h"
namespace Serialization {
	class const_value
	{
	public:
		DataType type_;
		std::string string_value_;
		bool use_str_;
		union
		{
			uint8_t byte_value_;
			int16_t short_value_;
			int32_t int_value_;
			bool bool_value_;
			long long long_value_;
			float float_value_;
			double double_value_;				
			void *null_value_;
		};
	
		
		const_value operator ~()
		{
			const_value value;
			if (type_ == BYTE_TYPE)
			{
				value.type_ = BYTE_TYPE;				
				value.byte_value_ = ~byte_value_;
			}
			else if (type_ == SHORT_TYPE)
			{
				value.type_ = SHORT_TYPE;
				value.short_value_ = ~short_value_;
			}
			else if (type_ == CHAR_TYPE)
			{
				value.type_ = CHAR_TYPE;
				value.int_value_ = ~int_value_;
			}
			
			else if (type_ == INT_TYPE)
			{
				value.type_ = INT_TYPE;
				value.int_value_ = ~int_value_;
			}
			
			else if (type_ == LONG_TYPE)
			{
				value.type_ = LONG_TYPE;
				value.long_value_ = ~long_value_;
			}
			else
			{
				value.type_ = NULL_TYPE;
				value.null_value_ = NULL;
			}
			return value;
		}
		const_value operator !()
		{
			const_value value;
			if (type_ == BYTE_TYPE)
			{
				value.type_ = BYTE_TYPE;
				value.byte_value_ = !byte_value_;
			}
			else if (type_ == SHORT_TYPE)
			{
				value.type_ = SHORT_TYPE;
				value.short_value_ = !short_value_;
			}
			else if (type_ == CHAR_TYPE)
			{
				value.type_ = CHAR_TYPE;
				value.int_value_ = !int_value_;
			}
			else if (type_ == INT_TYPE)
			{
				value.type_ = INT_TYPE;
				value.int_value_ = !int_value_;
			}
			else if (type_ == BOOL_TYPE)
			{
				value.type_ = BOOL_TYPE;
				value.bool_value_ = !bool_value_;
			}			
			else if (type_ == LONG_TYPE)
			{
				value.type_ = LONG_TYPE;
				value.long_value_ = !long_value_;
			}
			else
			{
				value.type_ = NULL_TYPE;
				value.null_value_ = NULL;
			}
			return value;
		}
		const_value operator +()
		{
			const_value value;
			if (type_ == BYTE_TYPE)
			{
				value.type_ = BYTE_TYPE;
				value.byte_value_ = byte_value_;
			}
			else if (type_ == SHORT_TYPE)
			{
				value.type_ = SHORT_TYPE;
				value.short_value_ = short_value_;
			}
			else if (type_ == INT_TYPE)
			{
				value.type_ = INT_TYPE;
				value.int_value_ = int_value_;
			}
			else if (type_ == CHAR_TYPE)
			{
				value.type_ = CHAR_TYPE;
				value.int_value_ = int_value_;
			}
			else if (type_ == BOOL_TYPE)
			{
				value.type_ = BOOL_TYPE;
				value.bool_value_ = bool_value_;
			}			
			else if (type_ == LONG_TYPE)
			{
				value.type_ = LONG_TYPE;
				value.long_value_ = long_value_;
			}
			else
			{
				value.type_ = NULL_TYPE;
				value.null_value_ = NULL;
			}
		}
		const_value operator -()
		{
			const_value value;
			if (type_ == BYTE_TYPE)
			{
				value.type_ = BYTE_TYPE;
				value.byte_value_ = -byte_value_;
			}
			else if (type_ == SHORT_TYPE)
			{
				value.type_ = SHORT_TYPE;
				value.short_value_ = -short_value_;
			}
			else if (type_ == INT_TYPE)
			{
				value.type_ = INT_TYPE;
				value.int_value_ = -int_value_;
			}	
			else if (type_ == CHAR_TYPE)
			{
				value.type_ = CHAR_TYPE;
				value.int_value_ = -int_value_;
			}				
			else if (type_ == LONG_TYPE)
			{
				value.type_ = LONG_TYPE;
				value.long_value_ = -long_value_;
			}
			else
			{
				value.type_ = NULL_TYPE;
				value.null_value_ = NULL;
			}
			return value;
		}
		operator unsigned long()
		{
			const_value value;
			if (type_ == BYTE_TYPE)
			{				
				return (unsigned long)byte_value_;
			}
			else if (type_ == SHORT_TYPE)
			{
				return (unsigned long)short_value_;
			}
			else if (type_ == INT_TYPE)
			{
				return (unsigned long)int_value_;
			}	
			else if (type_ == CHAR_TYPE)
			{
				return (unsigned long)int_value_;
			}				
			else if (type_ == LONG_TYPE)
			{
				return (unsigned long)long_value_;
			}
			else
			{
				return (unsigned long)0;
			}
			return value;
		}		
		const_value operator *(const const_value& right)
		{
			const_value value;
			if (type_ == BYTE_TYPE && right.type_ == BYTE_TYPE)
			{
				value.type_ = LONG_TYPE;
				value.long_value_ = byte_value_ * right.byte_value_;
			}
			else if (type_ == SHORT_TYPE && right.type_ == SHORT_TYPE)
			{			
				value.type_ = LONG_TYPE;
				value.long_value_ = short_value_ * right.short_value_;
			}
			else if (type_ == CHAR_TYPE && right.type_ == CHAR_TYPE)
			{			
				value.type_ = LONG_TYPE;
				value.long_value_ = int_value_ * right.int_value_;
			}			
			else if (type_ == LONG_TYPE && right.type_ == LONG_TYPE)
			{			
				value.type_ = LONG_TYPE;
				value.long_value_ = long_value_ * right.long_value_;
			}
			else
			{
				value.type_ = NULL_TYPE;
				value.null_value_ = NULL;
			}
			return value;
		}
		const_value operator /(const const_value& right)
		{
			const_value value;
			if (type_ == BYTE_TYPE && right.type_ == BYTE_TYPE)
			{							
				if (right.byte_value_ == 0)
				{
					value.type_ = NULL_TYPE;
					value.null_value_ = NULL;
				}
				else
				{
					value.type_ = LONG_TYPE;
					value.long_value_ = byte_value_ / right.byte_value_;
				}
			}
			else if (type_ == SHORT_TYPE && right.type_ == SHORT_TYPE)
			{							
				if (right.short_value_ == 0)
				{
					value.type_ = NULL_TYPE;
					value.null_value_ = NULL;
				}
				else
				{
					value.type_ = LONG_TYPE;
					value.long_value_ = short_value_ / right.short_value_;
				}
			}
			else if (type_ == CHAR_TYPE && right.type_ == CHAR_TYPE)
			{			
				if (right.int_value_ == 0)
				{
					value.type_ = NULL_TYPE;
					value.null_value_ = NULL;
				}
				else
				{
					value.type_ = LONG_TYPE;
					value.long_value_ = int_value_ / right.int_value_;
				}
			}			
			else if (type_ == LONG_TYPE && right.type_ == LONG_TYPE)
			{			
				if (right.long_value_ == 0)
				{
					value.type_ = NULL_TYPE;
					value.null_value_ = NULL;
				}
				else
				{
					value.type_ = LONG_TYPE;
					value.long_value_ = long_value_ / right.long_value_;
				}
			}
			else
			{				
				value.type_ = NULL_TYPE;
				value.null_value_ = NULL;
			}
			return value;
		}
		
		const_value operator %(const const_value& right)
		{
			const_value value;
			if (type_ == BYTE_TYPE && right.type_ == BYTE_TYPE)
			{							
				if (right.byte_value_ == 0)
				{
					value.type_ = NULL_TYPE;
					value.null_value_ = NULL;
				}
				else
				{
					value.type_ = LONG_TYPE;
					value.long_value_ = byte_value_ % right.byte_value_;
				}
			}
			else if (type_ == SHORT_TYPE && right.type_ == SHORT_TYPE)
			{							
				if (right.short_value_ == 0)
				{
					value.type_ = NULL_TYPE;
					value.null_value_ = NULL;
				}
				else
				{
					value.type_ = LONG_TYPE;
					value.long_value_ = short_value_ % right.short_value_;
				}
			}
			else if (type_ == CHAR_TYPE && right.type_ == CHAR_TYPE)
			{			
				if (right.int_value_ == 0)
				{
					value.type_ = NULL_TYPE;
					value.null_value_ = NULL;
				}
				else
				{
					value.type_ = LONG_TYPE;
					value.long_value_ = int_value_ % right.int_value_;
				}
			}			
			else if (type_ == LONG_TYPE && right.type_ == LONG_TYPE)
			{			
				if (right.long_value_ == 0)
				{
					value.type_ = NULL_TYPE;
					value.null_value_ = NULL;
				}
				else
				{
					value.type_ = LONG_TYPE;
					value.long_value_ = long_value_ % right.long_value_;
				}
			}
			else
			{				
				value.type_ = NULL_TYPE;
				value.null_value_ = NULL;
			}
			return value;
		}
		
		const_value operator + (const const_value& right)
		{
			const_value value;
			if (type_ == BYTE_TYPE && right.type_ == BYTE_TYPE)
			{	
				value.type_ = LONG_TYPE;
				value.long_value_ = byte_value_ + right.byte_value_;
			}
			else if (type_ == SHORT_TYPE && right.type_ == SHORT_TYPE)
			{			
				value.type_ = LONG_TYPE;
				value.long_value_ = short_value_ + right.short_value_;
			}
			else if (type_ == CHAR_TYPE && right.type_ == CHAR_TYPE)
			{			
				value.type_ = LONG_TYPE;
				value.long_value_ = int_value_ + right.int_value_;
			}			
			else if (type_ == LONG_TYPE && right.type_ == LONG_TYPE)
			{			
				value.type_ = LONG_TYPE;
				value.long_value_ = long_value_ + right.long_value_;
			}
			else if (type_ == STRING_TYPE && right.type_ == STRING_TYPE)
			{			
				value.type_ = STRING_TYPE;
				value.long_value_ = long_value_;
				value.long_value_ += right.long_value_;
			}
			else
			{
				value.type_ = NULL_TYPE;
				value.null_value_ = NULL;
			}
			return value;
		}
		
		const_value operator - (const const_value& right)
		{
			const_value value;
			if (type_ == BYTE_TYPE && right.type_ == BYTE_TYPE)
			{			
				value.type_ = LONG_TYPE;
				value.long_value_ = byte_value_ - right.byte_value_;
			}
			else if (type_ == SHORT_TYPE && right.type_ == SHORT_TYPE)
			{			
				value.type_ = LONG_TYPE;
				value.long_value_ = short_value_ - right.short_value_;
			}
			else if (type_ == CHAR_TYPE && right.type_ == CHAR_TYPE)
			{			
				value.type_ = LONG_TYPE;
				value.long_value_ = int_value_ - right.int_value_;
			}			
			else if (type_ == LONG_TYPE && right.type_ == LONG_TYPE)
			{			
				value.type_ = LONG_TYPE;
				value.long_value_ = long_value_ - right.long_value_;
			}			
			else
			{
				value.type_ = NULL_TYPE;
				value.null_value_ = NULL;
			}
			return value;
		}
		
		const_value operator << (const const_value& right)
		{
			const_value value;
			if (type_ == BYTE_TYPE && right.type_ == BYTE_TYPE)
			{			
				value.type_ = LONG_TYPE;
				value.long_value_ = byte_value_ << right.byte_value_;
			}
			else if (type_ == SHORT_TYPE && right.type_ == SHORT_TYPE)
			{			
				value.type_ = LONG_TYPE;
				value.long_value_ = short_value_ << right.short_value_;
			}
			else if (type_ == CHAR_TYPE && right.type_ == CHAR_TYPE)
			{			
				value.type_ = LONG_TYPE;
				value.long_value_ = int_value_ << right.int_value_;
			}			
			else if (type_ == LONG_TYPE && right.type_ == LONG_TYPE)
			{			
				value.type_ = LONG_TYPE;
				value.long_value_ = long_value_ << right.long_value_;
			}			
			else
			{
				value.type_ = NULL_TYPE;
				value.null_value_ = NULL;
			}
			return value;
		}
		
		const_value operator >> (const const_value& right)
		{
			const_value value;
			if (type_ == BYTE_TYPE && right.type_ == BYTE_TYPE)
			{			
				value.type_ = LONG_TYPE;
				value.long_value_ = byte_value_ >> right.byte_value_;
			}
			else if (type_ == SHORT_TYPE && right.type_ == SHORT_TYPE)
			{			
				value.type_ = LONG_TYPE;
				value.long_value_ = short_value_ >> right.short_value_;
			}
			else if (type_ == CHAR_TYPE && right.type_ == CHAR_TYPE)
			{			
				value.type_ = LONG_TYPE;
				value.long_value_ = int_value_ >> right.int_value_;
			}			
			else if (type_ == LONG_TYPE && right.type_ == LONG_TYPE)
			{			
				value.type_ = LONG_TYPE;
				value.long_value_ = long_value_ >> right.long_value_;
			}			
			else
			{
				value.type_ = NULL_TYPE;
				value.null_value_ = NULL;
			}
			return value;
		}
		const_value()		
		{
			type_ = NULL_TYPE;
			long_value_ = 0;
		}
		const_value(const const_value &right)
		{
			type_ = right.type_;
			long_value_ = right.long_value_;
			string_value_ = right.string_value_;
			use_str_ = right.use_str_;
		}
		const_value(DataType type, const std::string& str)
			:string_value_(str)
			, type_(type)
			, use_str_(true)
		{
			switch (type_)
			{
			case BYTE_TYPE:
				byte_value_ = atoi(string_value_.c_str());
				break;
			case SHORT_TYPE:
				short_value_ = atoi(string_value_.c_str());
				break;
			case INT_TYPE:
				int_value_ = atoi(string_value_.c_str());
				break;
			case LONG_TYPE:
				long_value_ = atoll(string_value_.c_str());
				break;
			case FLOAT_TYPE:
				float_value_ = (float)(atof(string_value_.c_str()));
				break;
			case DOUBLE_TYPE:
				double_value_ = atof(string_value_.c_str());
				break;
			}
		}
		const_value(uint8_t byte_value)
			:byte_value_(byte_value)
			, type_(BYTE_TYPE)
			, use_str_(false)
		{
		}

		const_value(int16_t short_value)
			:short_value_(short_value)
			, type_(SHORT_TYPE)
			, use_str_(false)
		{
		}

		const_value(int32_t int_value)
			:int_value_(int_value)
			, type_(INT_TYPE)
			, use_str_(false)
		{
		}
		const_value(bool bool_value)
			:bool_value_(bool_value)
			, type_(BOOL_TYPE)
			, use_str_(false)
		{
		}

		const_value(long long long_value)
			:long_value_(long_value)
			, type_(LONG_TYPE)
			, use_str_(false)
		{
		}

		const_value(float float_value)
			:float_value_(float_value)
			, type_(FLOAT_TYPE)
			, use_str_(false)
		{
		}

		const_value(double double_value)
			:double_value_(double_value)
			, type_(DOUBLE_TYPE)
			, use_str_(false)
		{
		}

		const_value(std::string string_value)
			:string_value_(string_value)
			, type_(STRING_TYPE)
			, use_str_(true)
		{
		}

		const_value(void *null_value)
			:null_value_(null_value)
			, type_(NULL_TYPE)
			, use_str_(false)
		{
		}
		
		const_value& operator = (const const_value& value)
		{
			long_value_ = value.long_value_;
			type_ = value.type_;
			use_str_ = value.use_str_;
			string_value_ = value.string_value_;
			return *this;
		}
		
		const_value& operator = (uint8_t byte_value)
		{
			byte_value_ = byte_value;
			type_ = BYTE_TYPE;
			use_str_ = false;
			return *this;
		}

		const_value& operator = (int16_t short_value)
		{
			short_value_ = short_value;
			type_ = SHORT_TYPE;
			use_str_ = false;
			return *this;

		}

		const_value& operator = (int32_t int_value)
		{
			int_value_ = int_value;
			type_ = CHAR_TYPE;
			use_str_ = false;
			return *this;
		}
		const_value& operator = (bool bool_value)
		{
			bool_value_ = bool_value;
			type_ = BOOL_TYPE;
			use_str_ = false;
			return *this;
		}

		const_value& operator = (long long long_value)
		{
			long_value_ = long_value;
			type_ = LONG_TYPE;
			use_str_ = false;
			return *this;
		}

		const_value& operator = (float float_value)
		{
			float_value_ = float_value;
			type_ = FLOAT_TYPE;
			use_str_ = false;
			return *this;
		}

		const_value& operator = (double double_value)
		{
			double_value_ = double_value;
			type_ = DOUBLE_TYPE;
			use_str_ = false;
			return *this;
		}

		const_value& operator = (const std::string& string_value)
		{			
			string_value_ = string_value;
			type_ = STRING_TYPE;
			use_str_ = true;
			return *this;

		}

		const_value& operator = (void *null_value)
		{
			null_value_ = null_value;
			type_ = NULL_TYPE;
			use_str_ = false;
			return *this;
		}

		virtual ~const_value() {}
	};
}