#ifndef __SCANNER_HPP__
#define __SCANNER_HPP__

#if ! defined(yyFlexLexerOnce)
#include "FlexLexer.h"
#endif

#include "serialization.grammar.hh"
#include "location.hh"

namespace Serialization {

class Scanner : public yyFlexLexer {
public:

	explicit Scanner(std::istream *in) : yyFlexLexer(in) {
	};

	~Scanner() override = default;

	//get rid of override virtual function warning
	using FlexLexer::yylex;

	virtual int yylex(Serialization::Parser::semantic_type *const lval, Serialization::Parser::location_type *location);
	// YY_DECL defined in scanner.ll
	// Method body created by flex in lexer.yy.cc

private:
	Serialization::Parser::semantic_type *yylval = nullptr;
};

}

#endif /* END __SCANNER_HPP__ */
