#include "ScopeSystem.h"

CScopeSystem* CScopeSystem::m_instance = nullptr;
const string CScopeSystem::GLOBAL_SCOPE_NAME = "global";
CScopeSystem::CScopeSystem() {
	m_scopetable = new map<string, CScope*>();

	// Create global scope
	CScope* globalScope = new CGlobalScope();
	(*m_scopetable)[GLOBAL_SCOPE_NAME] = globalScope;
	m_currentScope = globalScope;

	// Initialize built-in functions
	Insert("pow", 
		new FunctionSymbol(nullptr, FunctionSymbol::FT_BUILTINFUNCTION, "pow"));
}
void CScopeSystem::EnterScope(string name) {
	CScope* newScope = new CFunctionScope(m_currentScope);
	(*m_scopetable)[name] = newScope;
	m_currentScope = newScope;
}
void CScopeSystem::ExitScope() {
	if (m_currentScope->GetParent() != nullptr) {
		m_currentScope = m_currentScope->GetParent();
	}
}
CScope* CScopeSystem::GetScope(string name) {
	map<string, CScope*>::iterator it = m_scopetable->find(name);
	if (it != m_scopetable->end()) {
		return it->second;
	}
	else {
		throw std::runtime_error ("Scope not found: " + name);
	}
	return nullptr;
}
CScope* CScopeSystem::GetCurrentScope() {
	return m_currentScope;
}
Symbol* CScopeSystem::Insert(string name, Symbol* node) {
	return m_currentScope->Insert(name, node);
}
Symbol* CScopeSystem::Lookup(string name, Symbol::SYMBOLTYPE t) {
	return m_currentScope->Lookup(name, t);
}
CScopeSystem* CScopeSystem::GetInstance() {
	if (m_instance == nullptr) {
		m_instance = new CScopeSystem();
	}
	return m_instance;
}
