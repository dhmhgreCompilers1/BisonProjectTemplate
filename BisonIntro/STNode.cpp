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






