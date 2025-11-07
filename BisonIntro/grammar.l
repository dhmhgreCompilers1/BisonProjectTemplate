%option noyywrap

%{
#include "grammar.tab.h"
#define YY_DECL int yylex(yy::parser::semantic_type *yylval)
%}



%%

"+"   { return '+'; }
";"   { return  yy::parser::token::SEMICOLON; }
[0-9]+ {
			*yylval = atoi(yytext);
			return yy::parser::token::NUMBER;
		}
[ \t\n]  { /* skip whitespace */ }




%%