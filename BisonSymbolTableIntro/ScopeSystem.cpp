#include "ScopeSystem.h"

CScopeSystem* CScopeSystem::m_instance = nullptr;
const string CScopeSystem::GLOBAL_SCOPE_NAME = "global";
CScopeSystem::CScopeSystem() {
	m_scopetable = new map<string, CScope*>();	
}
void CScopeSystem::EnterScope(string name) {
	if ( name.empty() )
	{
		// Create global scope
		CScope* globalScope = new CGlobalScope();
		(*m_scopetable)[GLOBAL_SCOPE_NAME] = globalScope;
		m_currentScope = globalScope;
		// Initialize built-in functions
		Insert("pow",
			new FunctionSymbol(nullptr, FunctionSymbol::FT_BUILTINFUNCTION, "pow"));
	}
	else {
		CScope* newScope = new CFunctionScope(m_currentScope,name);
		(*m_scopetable)[name] = newScope;
		m_currentScope = newScope;
	}
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
Symbol *CScopeSystem::Lookup(string name, string scopename, Symbol::SYMBOLTYPE t) {
	if (scopename.empty())
	{
		string s = GLOBAL_SCOPE_NAME;
		return (*m_scopetable)[s]->Lookup(name, Symbol::ST_VARIABLE);
	}
	return (*m_scopetable)[scopename]->Lookup(name, Symbol::ST_VARIABLE);
}

CScopeSystem* CScopeSystem::GetInstance() {
	if (m_instance == nullptr) {
		m_instance = new CScopeSystem();
	}
	return m_instance;
}

// Single operator<< in terms of Print
std::ostream& operator<<(std::ostream& os, const CScopeSystem& sys) {
	sys.Print(os);
	return os;
}