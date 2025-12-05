#pragma once
#include <map>
#include <string>
#include "STNode.h"
using namespace std;

class SymbolTable {
private :
	static SymbolTable* m_instance;
	std::map<string, STNode*> *m_table;
	SymbolTable();

public:	
	~SymbolTable();
	static SymbolTable* GetInstance();
	STNode* Insert(string name, STNode* node);
	STNode* Lookup(string name);

};
