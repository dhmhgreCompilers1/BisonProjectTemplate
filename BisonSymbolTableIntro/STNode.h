#ifndef STNODE
#define STNODE
#include <stdlib.h>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

enum nodetypeid;
string g_nodetypesstr[];

class STNode {
public:
	STNode(nodetypeid nodeType);
	~STNode();
	void setParent(STNode* parent);
	nodetypeid GetNodeType();
	void AddChild(STNode* node);	
	string GetName();



public:
	
	void virtual PrintTree(ofstream *file, STNode *parent);
	virtual int Evaluate();
	
protected:

	STNode* m_parent;	
	string m_graphvizID;
	int m_serialNumber;
	nodetypeid m_nodetype;
	static int m_graphvizCount;

public:
	static STNode* mg_root;
	list<STNode*>* m_children;
};


#endif
