%option noyywrap

%{
#include "grammar.tab.h"
#include "ConcreteNode.h"
#include "SymbolTable.h"
#define YY_DECL int yylex(yy::parser::semantic_type *yylval)
%}



%%

"+"   { return '+'; }
";"   { return  yy::parser::token::SEMICOLON; }
"="   { return  '='; }
[a-zA-Z_][a-zA-Z0-9_]* {
			// 1. Create IDENTIFIER node
			STNode* identifierNode = new IDENTIFIER(yytext);
			// 2. Store/Lookup node to symboltable			
			// 3. Attach node to semantic value
			yylval->node = SymbolTable::GetInstance()->Insert(yytext, identifierNode);;
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