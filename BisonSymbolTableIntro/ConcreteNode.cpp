#include "ConcreteNode.h"

string g_nodetypesstr[] = { "NA","NUMBER","IDENTIFIER","ADDITION", "ADDITIONLIST" };
STNode* STNode::mg_root = nullptr;


NUMBER::NUMBER(char* text) :STNode(nodetypeid::NUMBER_) {
	m_number = text;
	m_value = atoi(text);
	m_graphvizID += "_value_=" + to_string(m_value);
}

NUMBER::~NUMBER() {
}


string NUMBER::GetNumberText() {
	return m_number;
}

int NUMBER::GetValue() {
	return m_value;
}

IDENTIFIER::IDENTIFIER(char* text) : STNode(IDENTIFIER_) {
	m_identifier = text;
	m_graphvizID += "_name_=" + m_identifier;
}

IDENTIFIER::~IDENTIFIER() {
}

string IDENTIFIER::GetIdentifierText() {
	return m_identifier;
}

Addition::Addition(STNode* number) :STNode(ADDITION) {
	AddChild(number);
	number->setParent(this);
}

Addition::Addition(STNode* addition, STNode* number) : STNode(ADDITION) {
	AddChild(addition);
	AddChild(number);
	addition->setParent(this);
	number->setParent(this);
}





AdditionList::AdditionList(STNode* addition):STNode(ADDITIONLIST) {
	AddChild(addition);
	addition->setParent(this);
}

AdditionList::AdditionList(STNode* additionlist, STNode* addition) : STNode(ADDITIONLIST) {
	AddChild(additionlist);
	AddChild(addition);
	additionlist->setParent(this);
	addition->setParent(this);
}



