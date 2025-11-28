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
%verbose

%start addition_list
%token <node> NUMBER IDENTIFIER
%token SEMICOLON
%type <node> addition addition_list
%right '='
%left '+' 

%%

addition_list
	: addition SEMICOLON				{ STNode::mg_root= $$ = new AdditionList($1);}
	| addition_list  addition SEMICOLON { STNode::mg_root= $$ = new AdditionList($1,$2);}
	;

addition : NUMBER						{ $$ = $1; }
		|  IDENTIFIER					{ $$ = $1; }
		|  addition '+' addition		{ $$ = new Addition($1,$3);}
		|  IDENTIFIER '=' addition		{ $$ = new Addition($1,$3);}
		;



%%

void yy::parser::error(const std::string& msg) {
	fprintf(stderr, "Error: %s\n", msg.c_str());
}
