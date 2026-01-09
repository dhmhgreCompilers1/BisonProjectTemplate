%language "C++"

%{
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ConcreteNode.h"
#include "grammar.tab.h"
extern int yylex(yy::parser::semantic_type *yylval);
void yyerror(const char *s);
%}

%code requires{ 
#include "STNode.h"
#include "ScopeSystem.h"
}

%union {
	STNode *node;	
}

%error-verbose
%verbose

%start expression_list
%token <node> NUMBER IDENTIFIER
%token SEMICOLON FUNCTION
%type <node> expression expression_list param_list args
%right '='
%left LOR 
%left LAND
%left BITOR
%left BITXOR
%left BITAND
%nonassoc EQ NEQ 
%nonassoc LT LTE GT GTE
%left LSHIFT RSHIFT
%left '+' '-'
%left '*' '/' '%' FDIV
%right '^'
%left LNOT BNOT 
%right INCREMENT DECREMENT

%%

expression_list
	: expression SEMICOLON				{ STNode::mg_root= $$ = new ExpressionList($1);}
	| expression_list  expression SEMICOLON { STNode::mg_root= $$ = new ExpressionList($1,$2);}
	| expression_list FUNCTION IDENTIFIER '(' param_list ')' '{'  expression_list  '}'	{   STNode::mg_root= $$ = new FunctionDefinition($3, $5, $8);}
	| expression_list FUNCTION IDENTIFIER '(' ')' '{' expression_list '}'  {   STNode::mg_root= $$ = new FunctionDefinition($3, $7);}
	| FUNCTION IDENTIFIER '(' param_list ')' '{'  expression_list  '}'	{   STNode::mg_root= $$ = new FunctionDefinition($2, $4, $7);}
	| FUNCTION IDENTIFIER '(' ')' '{' expression_list '}'  {   STNode::mg_root= $$ = new FunctionDefinition($2, $6);}
	;

param_list: IDENTIFIER	{ $$ = new ParamList($1); }
						
			| param_list ',' IDENTIFIER	{ $$ = new ParamList($1,$3); }	
	;

expression : NUMBER						{ $$ = $1; }
		|  IDENTIFIER					{ $$ = $1; }
		| '(' expression ')'			{ $$ = $2; }
		|  IDENTIFIER '(' ')'			{ $$ = new BuiltInFunctionCall($1,nullptr); }										
		|  IDENTIFIER '(' args ')'		{ $$ = new BuiltInFunctionCall($1,$3); }
		|  expression '+' expression		{ $$ = new Addition($1,$3);}
		|  expression '-' expression		{ $$ = new Subtraction($1,$3);}
		|  expression '*' expression		{ $$ = new Multiplication($1,$3);}
		|  expression '/' expression		{ $$ = new Division($1,$3);}
		|  expression '%' expression		{ $$ = new Modulo($1,$3);}
		|  '-' expression					{ $$ = new UnaryMinus($2);}
		|  '+' expression					{ $$ = new UnaryMinus($2);}
		|  expression FDIV expression		{ $$ = new FloorDivision($1,$3);}
		|  expression INCREMENT				{ $$ = new Increment($1);}
		|  expression DECREMENT				{ $$ = new Decrement($1);}
		|  expression '^' expression		{ $$ = new Exponentiation($1,$3);}
		|  expression LAND expression		{ $$ = new LogicalAnd($1,$3);}
		|  expression LOR expression		{ $$ = new LogicalOr($1,$3);}
		|  LNOT expression					{ $$ = new LogicalNot($2);}
		|  expression EQ expression			{ $$ = new Equal($1,$3);}
		|  expression NEQ expression		{ $$ = new NotEqual($1,$3);}
		|  expression LT expression			{ $$ = new LessThan($1,$3);}
		|  expression LTE expression		{ $$ = new LessThanOrEqual($1,$3);}
		|  expression GT expression			{ $$ = new GreaterThan($1,$3);}
		|  expression GTE expression		{ $$ = new GreaterThanOrEqual($1,$3);}
		|  expression BITAND expression		{ $$ = new BITWISEAND($1,$3);}
		|  expression BITOR expression		{ $$ = new BITWISEOR($1,$3);}
		|  expression BITXOR expression		{ $$ = new BITWISEXOR($1,$3);}
		|  expression LSHIFT expression		{ $$ = new LSHIFT($1,$3);}
		|  expression RSHIFT expression		{ $$ = new RSHIFT($1,$3);}
		|  BNOT expression					{ $$ = new BITWISENOT($2);}
		|  IDENTIFIER '=' expression		{ $$ = new Assignment($1,$3);}
		;

args : expression						{ $$ = new ArgumentList($1); }
	| args ',' expression				{ $$ = new ArgumentList($1,$3); }
	;

%%

void yy::parser::error(const std::string& msg) {
	fprintf(stderr, "Error: %s\n", msg.c_str());
}
