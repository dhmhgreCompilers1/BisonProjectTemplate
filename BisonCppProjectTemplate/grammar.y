%language "C++"

%{
#include <stdio.h>
#include <stdlib.h>
#include "grammar.tab.h"
extern int yylex(yy::parser::semantic_type *yylval);
void yyerror(const char *s);
%}



%start root_symbol

%%

root_symbol
	: /* empty */
	;


%%

void yy::parser::error(const std::string& msg) {
	fprintf(stderr, "Error: %s\n", msg.c_str());
}
