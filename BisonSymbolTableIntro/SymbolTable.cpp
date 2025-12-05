#include "SymbolTable.h"

SymbolTable* SymbolTable::m_instance = nullptr;
SymbolTable::SymbolTable() {
	m_table = new map<string, STNode*>();
}

SymbolTable::~SymbolTable() {
	delete m_table;
}

STNode* SymbolTable::Insert(string name, STNode* node) {
	STNode* existingNode = Lookup(name);
	if (existingNode != nullptr) {
		return existingNode; // Symbol already exists
	}
	(*m_table)[name] = node;
	return node;
}

STNode* SymbolTable::Lookup(string name) {
	map<string, STNode*>::iterator it = m_table->find(name);
	if (it != m_table->end()) {
		return it->second;
	}
	return nullptr;
}

SymbolTable* SymbolTable::GetInstance() {
	if (m_instance == nullptr) {
		m_instance = new SymbolTable();
	}
	return m_instance;
}
