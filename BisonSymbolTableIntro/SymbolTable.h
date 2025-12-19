#pragma once
#include <map>
#include <string>

#include "ConcreteNode.h"
#include "STNode.h"
using namespace std;

class Symbol
{
public:
	STNode* m_node;
	bool isFunction;
	string m_name;
};


class SymbolTable {
private:
	static SymbolTable* m_instance;
	std::map<string, Symbol*>* m_vtable;
	std::map<string, Symbol*>* m_ftable;
	SymbolTable();

public:
	~SymbolTable();
	static SymbolTable* GetInstance();
	Symbol* Insert(string name, Symbol* node, bool isFunction);
	Symbol* Lookup(string name, bool findFunction);

};
