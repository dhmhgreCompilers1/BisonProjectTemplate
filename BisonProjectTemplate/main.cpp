#include <stdio.h>
#include <stdlib.h>

#include "grammar.tab.h"


void main(int argc, char**argv)
{
	if (argc > 1) {
		FILE *file = fopen(argv[1], "r");
		if (!file) {
			perror("Could not open file");
			return;
		}
		extern FILE *yyin;
		yyin = file;
	}
	yyparse();	
}
