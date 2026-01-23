%language "C++"

%{
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ConcreteNode.h"
#include "grammar.tab.h"
extern int yylex(yy::parser::semantic_type *yylval, yy::parser::location_type* loc);
void yyerror(const char *s);
%}

%code requires{ 
#include "STNode.h"
#include "ScopeSystem.h"
extern int yylineno;
}

%union {
	STNode *node;	
}

%error-verbose
%define parse.error verbose
%locations


%initial-action {
// Filename for locations here
@$.begin.filename = @$.end.filename = new std::string("test.txt");
}


%start compilation_unit
%token <node> NUMBER IDENTIFIER FLOAT INT VOID CHAR
%token SEMICOLON IF ELSE WHILE RETURN FOR DO
%token BREAK CONTINUE LOR LAND BITOR BITXOR BITAND EQ NEQ LT LTE GT GTE LSHIFT RSHIFT FDIV INCREMENT DECREMENT LNOT BNOT
%type <node> expression compilation_unit param_list args declarations
statements declaration function_definition variable_declaration 
type_specifier declarators direct_declarator statement expression_statement
compound_statement iteration_statement, selection_statement jump_statement
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

compilation_unit: declarations statements { STNode::mg_root= $$ = new CompilationUnit($1,$2); }
			| statements { STNode::mg_root= $$ = new CompilationUnit($1); }	
			| declarations { STNode::mg_root= $$ = new CompilationUnit($1); }
			;

declarations: declaration	{ $$ = new Declarations($1); }
			| declarations declaration { $$ = new Declarations($1,$2); }
			;

statements: statement { $$ = new Statements($1); }
			| statements statement { $$ = new Statements($1,$2); }
			;

declaration: function_definition { $$ = new Declaration($1); }
			| variable_declaration { $$ = new Declaration($1); }
			;

function_definition	: type_specifier IDENTIFIER '(' param_list ')' compound_statement { $$ = new FunctionDefinition($1,$2,$4,$6); }	
	| type_specifier IDENTIFIER '(' ')' compound_statement  { $$ = new FunctionDefinition($1,$2,$5); } 
	;

param_list : IDENTIFIER	{ $$ = new ParamList($1); }						
			| param_list ',' IDENTIFIER	{ $$ = new ParamList($1,$3); }	
	;


variable_declaration : type_specifier declarators SEMICOLON	{ $$ = new VariableDeclaration($1,$2); }
;

type_specifier : INT 	
	| FLOAT	
	| VOID	
	| CHAR
	;

declarators	: direct_declarator	 { $$ = new Declarators($1); }			
	| direct_declarator '=' expression	{ $$ = new Declarators($1,$3); }
	| declarators ',' direct_declarator	 { $$ = new Declarators($1,$3); }	
	| declarators ',' direct_declarator '=' expression	{ $$ = new Declarators($1,$3,$5); }
	;

direct_declarator : IDENTIFIER	{ $$ = new DirectDeclarator($1); }					
				  | direct_declarator '[' ']' { $$ = new DirectDeclarator($1); }	
	;

statement : expression_statement { $$ = new ExpressionStatement($1); }				
		  | compound_statement	{ $$ = new CompoundStatement($1); }
		  | iteration_statement 
		  | selection_statement
		  | jump_statement
		  ;
expression_statement : expression SEMICOLON	{ $$ = new ExpressionStatement($1); }	
						| SEMICOLON			{ $$ = new EmptyStatement(); }	
						;

compound_statement : '{' statements '}'	{ $$ = new CompoundStatement($2); }
						| '{' '}'		{ $$ = new CompoundStatement(); }		
						;

iteration_statement : WHILE '(' expression ')' statement { $$ = new WhileLoop($3,$5); }	
					| FOR '(' expression_statement expression_statement  expression ')' statement { $$ = new ForLoop($3,$4,$5,$7); }	
					| FOR '(' expression_statement expression_statement ')' statement { $$ = new ForLoop($3,$4,$6); }	
					| DO statement WHILE '(' expression ')' SEMICOLON { $$ = new DoWhileLoop($2,$5); }	
					;

selection_statement : IF '(' expression ')' statement ELSE statement 	{ $$ = new IfElseStatement($3,$5,$7); }
					| IF '(' expression ')' statement		%prec LOWIF { $$ = new IfStatement($3,$5); }			 
					;
jump_statement : RETURN expression SEMICOLON { $$ = new ReturnStatement($2); }	
			   | RETURN SEMICOLON { $$ = new ReturnStatement(); }
			   | BREAK SEMICOLON { $$ = new BreakStatement(); }
			   | CONTINUE SEMICOLON { $$ = new ContinueStatement(); }
			   ;


expression : NUMBER						{ $$ = $1; }
		|  IDENTIFIER					{ $$ = $1; }
		| '(' expression ')'			{ $$ = $2; }
		|  IDENTIFIER '(' ')'			{ $$ = new BuiltInFunctionCall($1); }										
		|  IDENTIFIER '(' args ')'		{ $$ = new BuiltInFunctionCall($1,$3); }
		|  expression '+' expression	{ $$ = new Addition($1,$3);}
		|  expression '-' expression	{ $$ = new Subtraction($1,$3);}
		|  expression '*' expression	{ $$ = new Multiplication($1,$3);}
		|  expression '/' expression	{ $$ = new Division($1,$3);}
		|  expression '%' expression	{ $$ = new Modulo($1,$3);}
		|  '-' expression				{ $$ = new UnaryMinus($2);}
		|  '+' expression				{ $$ = new UnaryMinus($2);}
		|  expression FDIV expression	{ $$ = new FloorDivision($1,$3);}
		|  expression INCREMENT			{ $$ = new Increment($1);}
		|  expression DECREMENT			{ $$ = new Decrement($1);}
		|  expression '^' expression	{ $$ = new Exponentiation($1,$3);}
		|  expression LAND expression	{ $$ = new LogicalAnd($1,$3);}
		|  expression LOR expression	{ $$ = new LogicalOr($1,$3);}
		|  LNOT expression				{ $$ = new LogicalNot($2);}
		|  expression EQ expression		{ $$ = new Equal($1,$3);}
		|  expression NEQ expression	{ $$ = new NotEqual($1,$3);}
		|  expression LT expression		{ $$ = new LessThan($1,$3);}
		|  expression LTE expression	{ $$ = new LessThanOrEqual($1,$3);}
		|  expression GT expression		{ $$ = new GreaterThan($1,$3);}
		|  expression GTE expression	{ $$ = new GreaterThanOrEqual($1,$3);}
		|  expression BITAND expression	{ $$ = new BITWISEAND($1,$3);}
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

void yy::parser::error(const location_type& loc, const std::string& msg){
	std::cerr << msg << " at "<< loc <<  std::endl;
}