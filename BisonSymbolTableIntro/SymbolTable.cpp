#include "SymbolTable.h"

SymbolTable::SymbolTable() {
	m_table = new map<string, Symbol*>();
	// Create records for built-in functions if any	
}

SymbolTable::~SymbolTable() {
	delete m_table;
}

Symbol* SymbolTable::Insert(string name, Symbol* node) {
	if (!Lookup(name)) {
		(*m_table)[name] = node;	
	} else {
		// symbol not found when trying to insert/update
		throw std::runtime_error("Symbol already exists: " + name);
	}
	return node;
}

Symbol* SymbolTable::Lookup(string name) {	
	map<string, Symbol*>::iterator it = m_table->find(name);
	if (it != m_table->end()) {
		return it->second;
	}			
	return nullptr;
}

