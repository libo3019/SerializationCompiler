#ifndef __Compiler_h__
#define __Compiler_h__

#include <stdint.h>
#include <string>
#include <cstddef>
#include <istream>
#include "DLL.h"
#include "common_enum.h"
#include <map>
#include <fstream>
#include <istream>
#include <ostream>
#include <stack>
#define DEFAULT_HEAP_SIZE 1024*1024*300

#ifdef WIN32
#define PATH_SEPARATOR '\\'
#else
#define PATH_SEPARATOR '/'
#endif

namespace Serialization {
	class parser_node;
	class Parser;
	class Scanner;
	class CompilerContext;
	struct thing_def;
	struct enum_def;
	struct message_def;
	struct field_def;
	class type;
	class DLL_EXPORT_IMPORT Compiler {

	public:
		parser_node * syntax_tree;
		std::string *pkg_name;
		std::vector<std::string>* pkg_name_vec;		
		std::string* def_file_path;
		uint32_t msg_id;
		uint32_t it_seq;		
		uint32_t first_second_seq;
		uint32_t buf_idx;
		uint32_t result_idx;
		uint32_t pos_start_idx;
		uint32_t it_deep;
		int negative_result;		
	public:
class DLL_EXPORT_IMPORT Builder {
		private:
			std::istream* in;
			std::ostream* out;
			std::ostream* deb;
			const char * def_file_path;
			int heapSize = DEFAULT_HEAP_SIZE;

		public:
			Builder();

			Compiler::Builder input(std::istream& is, const char* filename);

			Compiler::Builder input(const char* filename);

			Compiler::Builder output(std::ostream& os);

			Compiler::Builder output(std::string filename);

			Compiler::Builder debug(std::ostream& os);

			Compiler::Builder debug(std::string filename);

			Compiler::Builder heap(int heapSize);

			Compiler build();

		};
		int parse(); //successful: 0, otherwise: failed

		int walk1();

		int walk2();

		int get_negative_result();

		virtual ~Compiler();
	private:
		int hh_tab;
		std::stack<int> *hh_space_stack;
		FILE *hh_file, *cc_file;
		std::string* relative_file_name;
		int cc_tab = 0;
		std::stack<int>* cc_space_stack;
		int namespce_num;		
	private:
		Compiler(const char *def_file_path,
				std::istream* in,
			   std::ostream* out,
			   std::ostream* deb,				
			   int heapSize);
		std::istream* in;
		std::ostream* out;
		std::ostream* deb;
		int heapSize;

		Parser* parser = nullptr;
		Scanner* scanner = nullptr;
	public:
		CompilerContext* ctx;
		void generate_namespace_name();		
		int generate_includes_in_hh_file();
		int generate_includes_in_cc_file();
		int generate_hh_cc_files();
		void generate_id_type_tab();
		int generate_namespace_start_in_hh_file();
		int generate_namespace_end_in_hh_file();
		int generate_class_declaration_forward();
		int generate_subclass_or_enum_declaration_forward(message_def* the_def);
		int generate_class_or_enum_declaration(thing_def* a_messsage_def);
		int generate_class_declaration(message_def* a_messsage_def);
		int generate_enum_declaration(enum_def* a_messsage_def);
		int generate_namespace_start_in_cc_file();
		int generate_namespace_end_in_cc_file();
		int generate_any_type_serialization(bool is_field_name, const char *name, const type* a_type);
		int generate_any_type_deserialization(bool is_field_name, const char *name, const type* a_type, bool optional);
		int generate_constructor_code(const message_def* a_messsage_def);
		int generate_destroyor_code(const message_def* a_messsage_def);
		int generate_set_method(const message_def* a_messsage_def, size_t idx);
		int generate_get_method(const message_def* a_messsage_def, size_t idx);
		int generate_exist_method(const message_def* a_messsage_def, size_t idx);
		int generate_serialize_method(const message_def* a_messsage_def);
		int generate_deserialize_method(const message_def* a_messsage_def);
		int jump_to_corrent_seq(const char *field_name, uint32_t seq, bool optional);		
		int generate_a_class_code(const message_def* the_msg);
		int generate_code();
		static void print_tab(FILE *fp, int count);
	public:		
		static void error(const char *fmt, ...);
	

		static void FreeAllNodes();
	};

} /* end namespace MC */

#endif /* END _compiler_h__ */
