#include "SymbolTable.h"

SymbolTable* SymbolTable::m_instance = nullptr;
SymbolTable::SymbolTable() {
	m_vtable = new map<string, Symbol*>();
	m_ftable = new map<string, Symbol*>();
	// Create records for built-in functions if any

	// Initialize built-in function: pow(double, double) -> double
	Symbol* powSymbol = new Symbol();
	powSymbol->m_name = "pow";
	powSymbol->isFunction = true;
	(*m_ftable)[powSymbol->m_name] = powSymbol;
}

SymbolTable::~SymbolTable() {
	delete m_vtable;
	delete m_ftable;
}

Symbol* SymbolTable::Insert(string name, Symbol* node, bool isFunction) {
	if (isFunction) {
		(*m_ftable)[name] = node;
	}
	else {
		(*m_vtable)[name] = node;
	}
	return node;
}

Symbol* SymbolTable::Lookup(string name, bool findFunction) {

	if (findFunction) {
		map<string, Symbol*>::iterator it = m_ftable->find(name);
		if (it != m_ftable->end()) {
			return it->second;
		}
		return nullptr;
	}else {	
		map<string, Symbol*>::iterator it = m_vtable->find(name);
		if (it != m_vtable->end()) {
			return it->second;
		}
		return nullptr;
	}
}

SymbolTable* SymbolTable::GetInstance() {
	if (m_instance == nullptr) {
		m_instance = new SymbolTable();
	}
	return m_instance;
}
