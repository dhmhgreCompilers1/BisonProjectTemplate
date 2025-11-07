

%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
void yyerror(const char *s);
%}


%start root_symbol

%%

root_symbol
	: /* empty */
	;


%%

void yyerror(const char *s) {
	fprintf(stderr, "Error: %s\n", s);
}
