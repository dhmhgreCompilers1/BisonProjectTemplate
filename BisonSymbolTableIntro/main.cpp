#include <stdio.h>
#include <stdlib.h>
#include <fstream>

#include "grammar.flex.h"
#include "grammar.tab.h"
using namespace std;
ofstream outfile("output.dot");


int Evaluate(STNode* current, STNode* parent);

int main(int argc, char** argv) {
	yy::parser parser;
	STNode* root;
	if (argc == 2) {
		fopen_s(&yyin, argv[1], "r");
		if (!yyin) {
			perror("Could not open file");
			return 1;
		}
	}
	parser.parse();

	root = STNode::mg_root;

	root->PrintTree(nullptr,nullptr);
	

	root->Evaluate();
	return 0;

}




