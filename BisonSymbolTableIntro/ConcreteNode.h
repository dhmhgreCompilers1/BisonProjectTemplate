#pragma once
#include "STNode.h"
#include <string>
using namespace std;

typedef enum nodetypeid {
	NA = 0, NUMBER_ = 1, IDENTIFIER_, ADDITION, EXPRESSIONLIST, ASSIGNMENT
}NODETYPE;

class NUMBER : public STNode {
public:

	NUMBER(char* text);
	~NUMBER();   
	
	string GetNumberText();
	int GetValue();

private:
	string m_number;
	int m_value;

};
class IDENTIFIER : public STNode {
public:
	IDENTIFIER(char* text);
	~IDENTIFIER();
	string GetIdentifierText();
private:
	string m_identifier;
};

class Addition : public STNode {
public:
	Addition(STNode* number);
	Addition(STNode* addition, STNode* number);	
};

class Assignment : public STNode {
public:
	Assignment(STNode* identifier, STNode* addition);
};

class ExpressionList : public STNode {
public:
	ExpressionList(STNode* addition);
	ExpressionList(STNode* additionList, STNode* addition);	
};