%option noyywrap yylineno

%{
#include "grammar.tab.h"
#include "ConcreteNode.h"
#include "SymbolTable.h"
#define YY_DECL int yylex(yy::parser::value_type *yylval, yy::parser::location_type* loc)
#define YY_USER_ACTION loc->columns(yyleng);
%}



/* Single-line comment: token definitions */
%%
%{
// start where previous token ended
loc->step ();
%}

"int" { return yy::parser::token::INT; }
"float" { return yy::parser::token::FLOAT; }
"void" { return yy::parser::token::VOID; }
"char" { return yy::parser::token::CHAR; }
"if"  { return yy::parser::token::IF; }
"else"  { return yy::parser::token::ELSE; }
"while"  { return yy::parser::token::WHILE; }
"return"  { return yy::parser::token::RETURN; }
"for"  { return yy::parser::token::FOR; }
"do"  { return yy::parser::token::DO; }
"break"  { return yy::parser::token::BREAK; }
"continue"  { return yy::parser::token::CONTINUE; }
"||"  { return yy::parser::token::LOR; }
"&&"  { return yy::parser::token::LAND; }
"|"   { return yy::parser::token::BITOR; }
"^^"   { return yy::parser::token::BITXOR; }
"&"   { return yy::parser::token::BITAND; }
"=="  { return yy::parser::token::EQ; }
"!="  { return yy::parser::token::NEQ; }
"<"   { return yy::parser::token::LT; }
"<="  { return yy::parser::token::LTE; }
">"   { return yy::parser::token::GT; }
">="  { return yy::parser::token::GTE; }
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
			/* Multi-line comment example:
			 * Create IDENTIFIER node and attach it
			 * to the semantic value.
			 */
			yylval->node = new IDENTIFIER(yytext);
			return yy::parser::token::IDENTIFIER;
		}
[0-9]+ {
			/* Multi-line comment:
			 * 1. Create NUMBER node
			 * 2. Attach node to semantic value
			 */
			STNode* numberNode = new NUMBER(yytext);
			yylval->node = numberNode;
			return yy::parser::token::NUMBER;
		}

 /* Single-line comments (C/C++ style) */
"//".*                { /* skip single-line comments */ }

 /* Multi-line comments (C/C++ style) */
"/*"([^*]|\*+[^*/])*"*"+"/"   { /* skip multi-line comments */ }

[ \t]  { loc->step(); }
[\r\n]  { loc->lines(1); loc->step(); }




%%