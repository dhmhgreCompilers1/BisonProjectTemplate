%option noyywrap

%{
#include "grammar.tab.h"
#define YY_DECL int yylex(yy::parser::semantic_type *yylval)
%}



%%



%%