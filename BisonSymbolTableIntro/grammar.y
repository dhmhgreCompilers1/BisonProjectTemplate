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

%start expression_list
%token <node> NUMBER IDENTIFIER
%token SEMICOLON
%type <node> expression expression_list
%right '='
%left '+' 

%%

expression_list
	: expression SEMICOLON				{ STNode::mg_root= $$ = new ExpressionList($1);}
	| expression_list  expression SEMICOLON { STNode::mg_root= $$ = new ExpressionList($1,$2);}
	;

expression : NUMBER						{ $$ = $1; }
		|  IDENTIFIER					{ $$ = $1; }
		|  expression '+' expression		{ $$ = new Addition($1,$3);}
		|  IDENTIFIER '=' expression		{ $$ = new Assignment($1,$3);}
		;



%%

void yy::parser::error(const std::string& msg) {
	fprintf(stderr, "Error: %s\n", msg.c_str());
}
