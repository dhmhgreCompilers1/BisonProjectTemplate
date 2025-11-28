%option noyywrap

%{
#include "grammar.tab.h"
#include "ConcreteNode.h"
#define YY_DECL int yylex(yy::parser::semantic_type *yylval)
%}



%%

"+"   { return '+'; }
";"   { return  yy::parser::token::SEMICOLON; }
[0-9]+ {
			// 1. Create NUMBER node
			STNode* numberNode = new NUMBER(yytext);
			// 2. Attach node to semantic value
			yylval->node = numberNode;
			return yy::parser::token::NUMBER;
		}
[ \t\n]  { /* skip whitespace */ }




%%