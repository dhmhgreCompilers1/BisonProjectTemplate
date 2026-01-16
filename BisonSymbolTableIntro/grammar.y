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

%start compilation_unit
%token <node> NUMBER IDENTIFIER
%token SEMICOLON FLOAT INT VOID CHAR IF ELSE WHILE RETURN FOR DO
%token BREAK CONTINUE LOR LAND BITOR BITXOR BITAND EQ NEQ LT LTE GT GTE LSHIFT RSHIFT FDIV INCREMENT DECREMENT LNOT BNOT
%type <node> expression compilation_unit param_list args declarations
statements declaration function_definition variable_declaration 
type_specifier declarators direct_declarator statement expression_statement
compound_statement iteration_statement
%nonassoc LOWIF
%nonassoc ELSE
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

compilation_unit: declarations statements
			| statements
			| declarations
			;

declarations: declaration
			| declarations declaration
			;

statements: statement
			| statements statement
			;

declaration: function_definition
			| variable_declaration
			;
function_definition
	: type_specifier IDENTIFIER '(' param_list ')' compound_statement	
	| type_specifier IDENTIFIER '(' ')' compound_statement  
	;

param_list : IDENTIFIER	{ $$ = new ParamList($1); }						
			| param_list ',' IDENTIFIER	{ $$ = new ParamList($1,$3); }	
	;


variable_declaration : type_specifier declarators SEMICOLON	

type_specifier : INT	
	| FLOAT	
	| VOID	
	| CHAR
	;

declarators
	: direct_declarator				
	| direct_declarator '=' expression	
	| declarators ',' direct_declarator		
	;

direct_declarator : IDENTIFIER						
				  | direct_declarator '[' ']'	
	;

statement : expression_statement				
		  | compound_statement
		  | iteration_statement
		  | selection_statement
		  | jump_statement
		  ;
expression_statement : expression SEMICOLON	
						| SEMICOLON				
						;

compound_statement : '{' statements '}'	
						| '{' '}'				
						;

iteration_statement : WHILE '(' expression ')' statement	
					| FOR '(' expression_statement expression_statement  expression ')' statement	
					| FOR '(' expression_statement expression_statement ')' statement	
					| DO statement WHILE '(' expression ')' SEMICOLON	
					;

selection_statement : IF '(' expression ')' statement ELSE statement
					| IF '(' expression ')' statement		%prec LOWIF			 
					;
jump_statement : RETURN expression SEMICOLON	
			   | RETURN SEMICOLON
			   | BREAK SEMICOLON
			   | CONTINUE SEMICOLON
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
