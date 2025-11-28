%language "C++"

%{
#include <stdio.h>
#include <stdlib.h>
#include "ConcreteNode.h"
#include "grammar.tab.h"
extern int yylex(yy::parser::semantic_type *yylval);
void yyerror(const char *s);
%}

%code requires{ 
#include "STNode.h"
}

%union {
	STNode *node;	
}

%error-verbose

%start addition_list
%token <node> NUMBER
%token SEMICOLON
%type <node> addition addition_list

%%

addition_list
	: addition SEMICOLON				{ STNode::mg_root= $$ = new AdditionList($1);}
	| addition_list  addition SEMICOLON { STNode::mg_root= $$ = new AdditionList($1,$2);}
	;

addition : NUMBER						{ $$ = new Addition($1); }
		|  addition '+' NUMBER			{ $$ = new Addition($1,$3);}
		;


%%

void yy::parser::error(const std::string& msg) {
	fprintf(stderr, "Error: %s\n", msg.c_str());
}
