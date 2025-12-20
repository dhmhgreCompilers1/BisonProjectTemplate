#pragma once
#include <map>
#include <string>
#include "SymbolTable.h"
using namespace std;

class STNode;

// Represents a scope for the language. It can be global or function scope.
// Each scope maintains its own symbol table. It also maintains a pointer to its parent scope
// in order to support nested scopes (LEXICAL SCOPING).
class CScope {
protected:
	// Pointer to the parent scope. Null for global scope.
	CScope* m_parent;
public:
	CScope(CScope* parent);
	~CScope();
	CScope* GetParent();
	// Insert a symbol into the current scope's symbol table. The type of symbol (variable or function)
	// is determined by the 'isFunction' flag in the Symbol object.
	virtual Symbol* Insert(string name, Symbol* node) = 0;
	// Lookup a symbol in the current scope's symbol table. If not found, recursively look up in parent scopes.
	// By default, it looks for variable symbols unless 'findFunction' is set to true.
	virtual Symbol* Lookup(string name, Symbol::SYMBOLTYPE t) = 0;
};

// Represents the global scope of the program. It contains separate symbol tables for variables and functions.
// Inherits from CScope. 
class CGlobalScope : public CScope {
	SymbolTable* m_VTable;
	SymbolTable* m_FTable;

public:
	CGlobalScope();
	~CGlobalScope();
	Symbol* Insert(string name, Symbol* node) override; 
 	Symbol* Lookup(string name, Symbol::SYMBOLTYPE t) override;
};

// Represents a function scope within the program. It contains its own symbol table for variables.
// Inherits from CScope.
class CFunctionScope : public CScope {
	SymbolTable* m_VTable;
public:
	CFunctionScope(CScope* parent);
	~CFunctionScope();
	Symbol* Insert(string name, Symbol* node);
	Symbol* Lookup(string name, Symbol::SYMBOLTYPE t) override;
};