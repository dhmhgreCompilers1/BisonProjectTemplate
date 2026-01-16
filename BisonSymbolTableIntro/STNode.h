#ifndef STNODE
#define STNODE
#include <stdlib.h>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

enum nodetypeid;
string g_nodetypesstr[];

class CVisitor;

class STNode {
public:
	STNode(nodetypeid nodeType);
	~STNode();
	void setParent(STNode* parent);
	nodetypeid GetNodeType();
	void AddChild(STNode* node);

	string GetName();
	STNode* GetParent() { return m_parent; }



public:
	
	void virtual PrintTree(ofstream *file, STNode *parent);
	virtual int Evaluate();

	virtual void Accept(CVisitor* visitor) = 0;
	
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
