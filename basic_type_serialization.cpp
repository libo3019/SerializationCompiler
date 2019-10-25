#include "basic_type_serialization.h"
#include <stdint.h>
namespace Serialization
{
	class probe_endian_mode
	{
	public:
		static bool is_little_endian;
		probe_endian_mode()
		{
			uint32_t data = 0x12345678;
			unsigned char *ptr = (unsigned char*)(&data);
			if (*ptr == 0x78)
			{
				is_little_endian = true;
			}
			else
			{
				is_little_endian = false;
			}
		}
	};
	bool probe_endian_mode::is_little_endian;

	probe_endian_mode auto_running_instance;

	bool basic_type::is_number_type(uint32_t type)
	{
		if (type >= ESerializeType_INT8_TYPE  && type <= ESerializeType_FLOAT64_TYPE)
			return true;
		else
			return false;
	}

	uint32_t basic_type::get_number_type_size(uint32_t type)
	{
		switch (type)
		{
		case ESerializeType_INT8_TYPE:
			return 1;
		case ESerializeType_UINT8_TYPE:
			return 1;
		case ESerializeType_INT16_TYPE:
			return 2;
		case ESerializeType_UINT16_TYPE:
			return 2;
		case ESerializeType_INT32_TYPE:
			return 4;
		case ESerializeType_UINT32_TYPE:
			return 4;
		case ESerializeType_INT64_TYPE:
			return 8;
		case ESerializeType_UINT64_TYPE:
			return 8;
		case ESerializeType_FLOAT32_TYPE:
			return 4;
		case ESerializeType_FLOAT64_TYPE:
			return 8;
		default:
			return -1;
		}
	}
	void basic_type::serialize(int8_t f, std::basic_string<unsigned char>& buf)
	{		
		buf.push_back((unsigned char)f);
	}

	void basic_type::serialize(int16_t f, std::basic_string<unsigned char>& buf)
	{
		const unsigned char *mem = (const unsigned char*)(&f);
		size_t idx;
		if (probe_endian_mode::is_little_endian)
		{
			for (idx = 0; idx < sizeof(f); ++idx)
			{

				buf.push_back(mem[idx]);
			}
		}
		else
		{
			for (idx = sizeof(f) - 1; idx >= 0; --idx)
			{

				buf.push_back(mem[idx]);
			}
		}
	}
	void basic_type::serialize(int32_t f, std::basic_string<unsigned char>& buf)
	{
		const unsigned char *mem = (const unsigned char*)(&f);
		size_t idx;
		if (probe_endian_mode::is_little_endian)
		{
			for (idx = 0; idx < sizeof(f); ++idx)
			{

				buf.push_back(mem[idx]);
			}
		}
		else
		{
			for (idx = sizeof(f) - 1; idx >= 0; --idx)
			{

				buf.push_back(mem[idx]);
			}
		}
	}
	void basic_type::serialize(int64_t f, std::basic_string<unsigned char>& buf)
	{
		const unsigned char *mem = (const unsigned char*)(&f);
		size_t idx;
		if (probe_endian_mode::is_little_endian)
		{
			for (idx = 0; idx < sizeof(f); ++idx)
			{

				buf.push_back(mem[idx]);
			}
			}
		else
		{
			for (idx = sizeof(f) - 1; idx >= 0; --idx)
			{

				buf.push_back(mem[idx]);
			}
		}
	}
	void basic_type::serialize(uint8_t f, std::basic_string<unsigned char>& buf)
	{
		buf.push_back((unsigned char)f);		
	}

	void basic_type::serialize(uint16_t f, std::basic_string<unsigned char>& buf)
	{
		const unsigned char *mem = (const unsigned char*)(&f);
		size_t idx;
		if (probe_endian_mode::is_little_endian)
		{
			for (idx = 0; idx < sizeof(f); ++idx)
			{

				buf.push_back(mem[idx]);
			}
			}
		else
		{
			for (idx = sizeof(f) - 1; idx >= 0; --idx)
			{

				buf.push_back(mem[idx]);
			}
		}
	}
	void basic_type::serialize(uint32_t f, std::basic_string<unsigned char>& buf)
	{
		const unsigned char *mem = (const unsigned char*)(&f);
		size_t idx;
		if (probe_endian_mode::is_little_endian)
		{
			for (idx = 0; idx < sizeof(f); ++idx)
			{

				buf.push_back(mem[idx]);
			}
			}
		else
		{
			for (idx = sizeof(f) - 1; idx >= 0; --idx)
			{

				buf.push_back(mem[idx]);
			}
		}
	}
	void basic_type::serialize(uint64_t f, std::basic_string<unsigned char>& buf)
	{
		const unsigned char *mem = (const unsigned char*)(&f);
		size_t idx;
		if (probe_endian_mode::is_little_endian)
		{
			for (idx = 0; idx < sizeof(f); ++idx)
			{

				buf.push_back(mem[idx]);
			}
		}
		else
		{
			for (idx = sizeof(f) - 1; idx >= 0; --idx)
			{

				buf.push_back(mem[idx]);
			}
		}
	}
	void basic_type::serialize(float f, std::basic_string<unsigned char>& buf)
	{
		const unsigned char *mem = (const unsigned char*)(&f);
		size_t idx;
		for (idx = 0; idx < sizeof(float); ++idx)
		{
			buf.push_back(mem[idx]);
		}
	}
	void basic_type::serialize(double f, std::basic_string<unsigned char>& buf)
	{
		const unsigned char *mem = (const unsigned char*)(&f);
		size_t idx;
		for (idx = 0; idx < sizeof(double); ++idx)
		{
			buf.push_back(mem[idx]);
		}
	}
	void basic_type::serialize(const std::string& f, std::basic_string<unsigned char>& buf)
	{
		size_t size = f.size();
		for (size_t idx = 0; idx < f.size(); ++idx)
		{
			buf.push_back((unsigned char)(f[idx]));
		}
	}
	int basic_type::deserialize(int8_t &f, const void *buf, size_t &pos, size_t size)
	{
		if (size - pos < sizeof(f))
		{
			return -1;
		}
		else
		{
			int idx;
			f = 0;
			if (probe_endian_mode::is_little_endian)
			{
				for (idx = (int)sizeof(f) - 1; idx >= 0; --idx)
				{
					f = (f << 8) + ((unsigned char *)buf)[pos + idx];
				}
			}
			else
			{
				for (idx = 0; idx < sizeof(f); ++idx)
				{
					f = (f << 8) + ((unsigned char *)buf)[pos + idx];
				}
			}

			pos += sizeof(f);

			return 0;
		}
	}
	int basic_type::deserialize(int16_t &f, const void *buf, size_t &pos, size_t size)
	{
		if (size - pos < sizeof(f))
		{
			return -1;
		}
		else
		{
			int idx;
			f = 0;
			if (probe_endian_mode::is_little_endian)
			{
				for (idx = (int)sizeof(f) - 1; idx >= 0; --idx)
				{
					f = (f << 8) + ((unsigned char *)buf)[pos + idx];
				}
			}
			else
			{
				for (idx = 0; idx < sizeof(f); ++idx)
				{
					f = (f << 8) + ((unsigned char *)buf)[pos + idx];
				}
			}

			pos += sizeof(f);
			return 0;
		}
	}
	int basic_type::deserialize(int32_t &f, const void *buf, size_t &pos, size_t size)
	{
		if (size - pos < sizeof(f))
		{
			return -1;
		}
		else
		{
			int idx;
			f = 0;
			if (probe_endian_mode::is_little_endian)
			{
				for (idx = (int)sizeof(f) - 1; idx >= 0; --idx)
				{
					f = (f << 8) + ((unsigned char *)buf)[pos + idx];
				}
			}
			else
			{
				for (idx = 0; idx < sizeof(f); ++idx)
				{
					f = (f << 8) + ((unsigned char *)buf)[pos + idx];
				}
			}

			pos += sizeof(f);
			return 0;
		}
	}
	int basic_type::deserialize(int64_t &f, const void *buf, size_t &pos, size_t size)
	{
		if (size - pos < sizeof(f))
		{
			return -1;
		}
		else
		{
			int idx;
			f = 0;
			if (probe_endian_mode::is_little_endian)
			{
				for (idx = (int)sizeof(f) - 1; idx >= 0; --idx)
				{
					f = (f << 8) + ((unsigned char *)buf)[pos + idx];
				}
			}
			else
			{
				for (idx = 0; idx < sizeof(f); ++idx)
				{
					f = (f << 8) + ((unsigned char *)buf)[pos + idx];
				}
			}

			pos += sizeof(f);
			return 0;
		}
	}
	int basic_type::deserialize(uint8_t &f, const void *buf, size_t &pos, size_t size)
	{
		if (size - pos < sizeof(f))
		{
			return -1;
		}
		else
		{
			int idx;
			f = 0;
			if (probe_endian_mode::is_little_endian)
			{
				for (idx = (int)sizeof(f) - 1; idx >= 0; --idx)
				{
					f = (f << 8) + ((unsigned char *)buf)[pos + idx];
				}
			}
			else
			{
				for (idx = 0; idx < sizeof(f); ++idx)
				{
					f = (f << 8) + ((unsigned char *)buf)[pos + idx];
				}
			}

			pos += sizeof(f);
			return 0;
		}
	}
	int basic_type::deserialize(uint16_t &f, const void *buf, size_t &pos, size_t size)
	{
		if (size - pos < sizeof(f))
		{
			return -1;
		}
		else
		{
			int idx;
			f = 0;
			if (probe_endian_mode::is_little_endian)
			{
				for (idx = (int)sizeof(f) - 1; idx >= 0; --idx)
				{
					f = (f << 8) + ((unsigned char *)buf)[pos + idx];
				}
			}
			else
			{
				for (idx = 0; idx < sizeof(f); ++idx)
				{
					f = (f << 8) + ((unsigned char *)buf)[pos + idx];
				}
			}

			pos += sizeof(f);
			return 0;
		}
	}
	int basic_type::deserialize(uint32_t &f, const void *buf, size_t &pos, size_t size)
	{
		if (size - pos < sizeof(f))
		{
			return -1;
		}
		else
		{
			int idx;
			f = 0;
			if (probe_endian_mode::is_little_endian)
			{
				for (idx = (int)sizeof(f) - 1; idx >= 0; --idx)
				{
					f = (f << 8) + ((unsigned char *)buf)[pos + idx];
				}
			}
			else
			{
				for (idx = 0; idx < sizeof(f); ++idx)
				{
					f = (f << 8) + ((unsigned char *)buf)[pos + idx];
				}
			}
			pos += sizeof(f);
			return 0;
		}
	}
	int basic_type::deserialize(uint64_t &f, const void *buf, size_t &pos, size_t size)
	{
		if (size - pos < sizeof(f))
		{
			return -1;
		}
		else
		{
			int idx;
			f = 0;
			if (probe_endian_mode::is_little_endian)
			{
				for (idx = (int)sizeof(f) - 1; idx >= 0; --idx)
				{
					f = (f << 8) + ((unsigned char *)buf)[pos + idx];
				}
			}
			else
			{
				for (idx = 0; idx < sizeof(f); ++idx)
				{
					f = (f << 8) + ((unsigned char *)buf)[pos + idx];
				}
			}
			pos += sizeof(f);
			return 0;
		}
	}
	int basic_type::deserialize(float &f, const void *buf, size_t &pos, size_t size)
	{
		if (size - pos < sizeof(f))
		{
			return -1;
		}
		else
		{
			f = *((float *)((unsigned char *)buf + pos));
			pos += sizeof(f);
			return 0;
		}
	}
	int basic_type::deserialize(double &f, const void *buf, size_t &pos, size_t size)
	{
		if (size - pos < sizeof(f))
		{
			return -1;
		}
		else
		{
			f = *((float *)((unsigned char *)buf + pos));
			pos += sizeof(f);
			return 0;
		}
	}
	int basic_type::deserialize(std::string &f, const void *buf, size_t &pos, size_t size, size_t string_size)
	{		
		if (size - pos < sizeof(uint32_t))
		{
			return -1;
		}
		else
		{			
			if (pos + string_size > size)
			{
				return -3;
			}
			uint32_t idx;
			for (idx = 0; idx < string_size; ++idx)
			{
				unsigned char ch = *(((unsigned char *)buf) + pos + idx);
				f.push_back(ch);
			}
			pos += string_size;
			return 0;
		}
	}
	field_null_exception::field_null_exception(const char *field_name)
	{
		this->field_name = new std::string(field_name);
	}
	field_null_exception::field_null_exception(const std::string& field_name)
	{
		this->field_name = new std::string(field_name);
	}
	const std::string& field_null_exception::get_field_name() const
	{
		return *field_name;
	}
	field_null_exception::~field_null_exception()
	{
		delete field_name;
	}
}
