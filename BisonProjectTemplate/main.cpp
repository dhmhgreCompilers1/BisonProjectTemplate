#include <stdio.h>
#include <stdlib.h>

#include "grammar.flex.h"
#include "grammar.tab.h"


void main(int argc, char**argv)
{
	if (argc > 1) {
		fopen_s(&yyin,argv[1], "r");
		if (!yyin) {
			perror("Could not open file");
			return;
		}			
	}
	yyparse();	
}
