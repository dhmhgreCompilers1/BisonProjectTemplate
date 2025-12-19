#include "STNode.h"

int STNode::m_graphvizCount = 0;


STNode::STNode(nodetypeid nodetype) {
	m_parent = nullptr;
	m_serialNumber = m_graphvizCount++;
	m_nodetype = nodetype;
	m_children = new list<STNode*>();
	m_graphvizID = g_nodetypesstr[m_nodetype] + to_string(m_serialNumber);
}


STNode::~STNode() {
	delete m_children;
}

string STNode::GetName() {
	return m_graphvizID;
}

void STNode::AddChild(STNode* node) {
	m_children->push_back(node);
}

void STNode::setParent(STNode* parent) {
	m_parent = parent;
}

nodetypeid STNode::GetNodeType() {
	return m_nodetype;
}

void STNode::PrintTree(ofstream *outfile,STNode *parent) {

	// Preorder actions ( Action before we visit children )

	// 1. Print edge from parent to current
	if (parent != nullptr) {
		(*outfile) << "\"" << parent->GetName() << "\"" <<
			" -> " << "\"" << GetName() << "\"" << ";" << endl;
	}

	// 2. print graphviz header for root node
	if (m_parent == nullptr) {
		outfile = new ofstream("output.dot");
		*outfile << "digraph G {" << endl;
	}

	// Visit children
	for (auto child : *(m_children)) {
		child->PrintTree(outfile,this);
	}
	// Postorder action ( Action after we have visited node children )
	// 1. print graphviz footer for root node
	if (m_parent == nullptr) {
		*outfile << "}" << endl;
		outfile->close();	
		delete outfile;
	}
}




