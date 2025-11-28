#pragma once
#include "STNode.h"
#include <string>
using namespace std;

typedef enum nodetypeid {
	NA = 0, NUMBER_ = 1, ADDITION, ADDITIONLIST
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

class Addition : public STNode {
public:
	Addition(STNode* number);
	Addition(STNode* addition, STNode* number);	
};

class AdditionList : public STNode {
public:
	AdditionList(STNode* addition);
	AdditionList(STNode* additionList, STNode* addition);	
};