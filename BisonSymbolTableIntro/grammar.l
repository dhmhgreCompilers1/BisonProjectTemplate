%option noyywrap

%{
#include "grammar.tab.h"
#include "ConcreteNode.h"
#include "SymbolTable.h"
#define YY_DECL int yylex(yy::parser::semantic_type *yylval)
%}



%%
"function" { return yy::parser::token::FUNCTION; }
","   { return ','; }
"+"   { return '+'; }
"++"  { return yy::parser::token::INCREMENT; }
"--"  { return yy::parser::token::DECREMENT; }
"-"   { return '-'; }
"*"   { return '*'; }
"/"   { return '/'; }
"%"   { return '%'; }
"^"   { return '^'; }
"("   { return '('; }
")"   { return ')'; }
"{"   { return '{'; }
"}"   { return '}'; }
";"   { return  yy::parser::token::SEMICOLON; }
"="   { return  '='; }
[a-zA-Z_][a-zA-Z0-9_]* {
			
			yylval->node = new IDENTIFIER(yytext);			
			return yy::parser::token::IDENTIFIER;
		}
[0-9]+ {
			// 1. Create NUMBER node
			STNode* numberNode = new NUMBER(yytext);
			// 2. Attach node to semantic value
			yylval->node = numberNode;
			return yy::parser::token::NUMBER;
		}
[ \t\n]  { /* skip whitespace */ }




%%