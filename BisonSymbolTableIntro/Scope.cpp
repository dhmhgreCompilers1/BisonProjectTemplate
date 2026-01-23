#pragma once
#include "Scope.h"

CScope::CScope(CScope* parent) {
	m_parent = parent;
}
CScope::~CScope() {
}
CScope* CScope::GetParent() {
	return m_parent;
}

CGlobalScope::CGlobalScope() : CScope(nullptr) {
	m_VTable = new SymbolTable();
	m_FTable = new SymbolTable();
}
CGlobalScope::~CGlobalScope() {
	delete m_VTable;
	delete m_FTable;
}
Symbol* CGlobalScope::Insert(string name, Symbol* node) {
	if (node->m_symbolType == Symbol::ST_VARIABLE) {
		return m_VTable->Insert(name, node);
	}
	else if (node->m_symbolType == Symbol::ST_FUNCTION) {
		return m_FTable->Insert(name, node);
	}
	else {
		throw std::runtime_error("Unknown symbol type for insertion: " + name);
	}
}
Symbol* CGlobalScope::Lookup(string name, Symbol::SYMBOLTYPE t) {
	Symbol* sym = nullptr;
	if (t == Symbol::ST_VARIABLE) {
		sym = m_VTable->Lookup(name);
	}
	else if (t == Symbol::ST_FUNCTION) {
		sym = m_FTable->Lookup(name);
	}
	else {
		throw std::runtime_error("Unknown symbol type for lookup: " + name);
	}
	return sym;
}
CFunctionScope::CFunctionScope(CScope* parent,string name) : CScope(parent) {
	m_VTable = new SymbolTable();
	m_name = name;
}
CFunctionScope::~CFunctionScope() {
	delete m_VTable;
}
Symbol* CFunctionScope::Insert(string name, Symbol* node) {
	if (node->m_symbolType == Symbol::ST_VARIABLE) {
		return m_VTable->Insert(name, node);
	}
	else {
		throw std::runtime_error("Only variable symbols can be inserted in function scope: " + name);
	}
}
Symbol* CFunctionScope::Lookup(string name, Symbol::SYMBOLTYPE t) {
	Symbol* sym = nullptr;
	if (t == Symbol::ST_VARIABLE) {
		sym = m_VTable->Lookup(name);
		if (sym == nullptr && m_parent != nullptr) {
			sym = m_parent->Lookup(name, t);
		}
	}	
	else {
		throw std::runtime_error("Only variable symbols can be looked up in function scope: " + name);
	}
	return sym;
}




