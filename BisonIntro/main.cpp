#include <stdio.h>
#include <stdlib.h>

#include "grammar.flex.h"
#include "grammar.tab.h"
using namespace yy;
using namespace std;


void main(int argc, char**argv)
{
	parser parser;
	if (argc > 1) {
		fopen_s(&yyin,argv[1], "r");
		if (!yyin) {
			perror("Could not open file");
			return;
		}			
	}
	parser.parse();	
}
