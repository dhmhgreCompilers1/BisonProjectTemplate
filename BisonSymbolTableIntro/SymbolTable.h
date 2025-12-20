#pragma once
#include <map>
#include <string>

#include "ConcreteNode.h"
#include "STNode.h"
using namespace std;


// Represents a symbol in the symbol table. It can be either a variable or a function.
class Symbol {
public:
	typedef enum SymbolType {
		ST_VARIABLE,
		ST_FUNCTION
	} SYMBOLTYPE;

public:
	// Pointer to the AST node representing this symbol (variable or function).
	STNode* m_node;
	// Type of the symbol (variable or function).
	SYMBOLTYPE m_symbolType;
	// Name of the symbol.
	string m_name;
};

class SymbolTable {
private:
	std::map<string, Symbol*>* m_table;
	
public:
	SymbolTable();
	~SymbolTable();
	Symbol* Insert(	string name, Symbol* node );
	Symbol* Lookup(string name);

};
