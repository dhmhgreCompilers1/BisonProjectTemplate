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

public:
	int Evaluate() override; 

private:
	string m_number;
	int m_value;

};
class IDENTIFIER : public STNode {
public:
	IDENTIFIER(char* text);
	~IDENTIFIER();
	string GetIdentifierText();
	void SetValue(int v);
	int GetValue();

public:
	int Evaluate() override;
private:
	string m_identifier;
	int m_value;
};

class Addition : public STNode {
public:
	Addition(STNode* number);
	Addition(STNode* addition, STNode* number);	

public:
	int Evaluate() override;
};

class Assignment : public STNode {
public:
	Assignment(STNode* identifier, STNode* addition);

public:
	int Evaluate() override;
};

class ExpressionList : public STNode {
public:
	ExpressionList(STNode* addition);
	ExpressionList(STNode* additionList, STNode* addition);	
public:
	int Evaluate() override;
};