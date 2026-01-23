#pragma once
#include <map>
#include <string>
#include "Scope.h"
using namespace std;

// Singleton class that manages all scopes in the program. 
// It maintains a mapping of scope names to CScope objects.
class CScopeSystem {
	static CScopeSystem* m_instance;
private:
	std::map<string, CScope*>* m_scopetable;
	CScope* m_currentScope;
	CScopeSystem();

public:
	// A constant string representing the name of the global scope.
	const static string GLOBAL_SCOPE_NAME;
	// Creates a scope with the given name and sets it as the current scope.
	void EnterScope(string name="");
	// Exits the current scope and reverts to the parent scope.
	void ExitScope();
	// Returns the scope with the given name.
	CScope* GetScope(string name);
	// Returns the current scope.
	CScope* GetCurrentScope();
	// Inserts a symbol into the current scope's symbol table.
	// Forwards to the current scope's Insert method.
	Symbol* Insert(string name, Symbol* node);
	// Looks up a symbol in the current scope's symbol table.
	// Forwards to the current scope's Lookup method.
	Symbol* Lookup(string name, Symbol::SYMBOLTYPE t);
	Symbol* Lookup(string name, string scopename, Symbol::SYMBOLTYPE t);

	// Returns the singleton instance of CScopeSystem.
	static CScopeSystem* GetInstance();

	// Polymorphic-style hook (even though class isn't derived, this keeps style consistent)
	void Print(std::ostream& os) const {
		os << "CScopeSystem{";

		os << "instance=" << static_cast<const void*>(m_instance) << ", ";

		os << "currentScope=" << static_cast<const void*>(m_currentScope) << ", ";

		if (m_scopetable == nullptr) {
			os << "scopeTable=null";
		}
		else {
			os << "scopeCount=" << m_scopetable->size();

			// Print a short listing of scopes (name -> pointer)
			os << ", scopes=[";
			bool first = true;

			for (const auto& kv : *m_scopetable) {
				const std::string& name = kv.first;
				CScope* scopePtr = kv.second;

				if (!first) os << ", ";
				first = false;
				os << "{\"" << name << "\":" << static_cast<const void*>(scopePtr) << "}";
			}

			os << "]";

		}

		os << "}";
	}
};

std::ostream& operator<<(std::ostream& os, const CScopeSystem& sys);