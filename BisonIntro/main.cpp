#include <stdio.h>
#include <stdlib.h>
#include <fstream>

#include "grammar.flex.h"
#include "grammar.tab.h"
using namespace yy;
using namespace std;
ofstream outfile("output.dot");

void PrintTree(STNode* current, STNode* parent);

void main(int argc, char** argv) {
	parser parser;
	STNode* root;
	if (argc > 1) {
		fopen_s(&yyin, argv[1], "r");
		if (!yyin) {
			perror("Could not open file");
			return;
		}
	}
	parser.parse();

	root = STNode::mg_root;

	PrintTree(root, nullptr);
	system("dot -Tgif output.dot -o output.gif");

}

void PrintTree(STNode* current, STNode* parent) {

	// Preorder actions ( Action before we visit children )

	// 1. Print edge from parent to current
	if (parent != nullptr) {
		outfile << "\"" << parent->GetName() << "\"" << " -> " << "\"" << current->GetName() << "\"" << ";" << endl;
	}

	// 2. print graphviz header for root node
	if (parent == nullptr) {
		outfile << "digraph G {" << endl;
	}

	// Visit children
	for (auto child : *(current->m_children)) {
		PrintTree(child, current);
	}

	// Postorder action ( Action after we have visited node children )
	// 1. print graphviz footer for root node
	if (parent == nullptr) {
		outfile << "}" << endl;
		outfile.close();
	}


}
