#include "ScopeSystemVisitor.h"

#include "ScopeSystem.h"

void CScopeSystemVisitor::VisitIdentifier(IDENTIFIER* id) {

	STNode* parent = id->GetParent();

	if (parent->GetNodeType() == FUNCTIONDEFINITION) {
		// 1. Create FunctionSymbol with parent as FunctionDefinition node 
		Symbol* funcSymbol = new FunctionSymbol(parent,
			FunctionSymbol::FT_USERDEFINEDFUNCTION,
			id->GetIdentifierText());

		// 2. Insert FunctionSymbol into Global Scope
		CScopeSystem::GetInstance()->Insert(id->GetIdentifierText(),
			funcSymbol);

		// 2. Enter Function Scope if parent is FunctionDefinition
		CScopeSystem::GetInstance()->EnterScope(id->GetIdentifierText());
	}
	else if (parent->GetNodeType() == PARAMLIST) {
		// 1. Create VariableSymbol with parent as PARAMLIST node
		VariableSymbol* sym = new VariableSymbol(id, id->GetIdentifierText());

		// 2. Insert VariableSymbol into Current Scope (Function Scope)
		CScopeSystem::GetInstance()->Insert(id->GetIdentifierText(), sym);
	}
	else if (parent->GetNodeType() == ASSIGNMENT) {
		// 1. Lookup VariableSymbol in Current Scope
		Symbol* sym = CScopeSystem::GetInstance()->Lookup(id->GetIdentifierText(),
			Symbol::ST_VARIABLE);
		// 2. If not found, create new VariableSymbol and insert into Current Scope
		if (sym == nullptr) {
			VariableSymbol* newSym = new VariableSymbol(id, id->GetIdentifierText());
			CScopeSystem::GetInstance()->Insert(id->GetIdentifierText(), newSym);
		}
		else {
			VariableSymbol* varSym = dynamic_cast<VariableSymbol*>(sym);
			IDENTIFIER* varNode = dynamic_cast<IDENTIFIER*>(varSym->m_node);
			auto temp = parent->m_children->front();
			parent->m_children->front() = varNode;
			delete temp;
		}
	}
	else if (parent->GetNodeType() == USERDEFINEDFUNCTIONCALL ||
		parent->GetNodeType() == BUILTINFUNCTIONCALL) {
		// 1. Lookup FunctionSymbol in Global Scope
		Symbol* sym = CScopeSystem::GetInstance()->Lookup(id->GetIdentifierText(),
			Symbol::ST_FUNCTION);
		if (sym == nullptr) {
			throw std::runtime_error("Function not defined: " + id->GetIdentifierText());
		}
		FunctionSymbol* funcSym = dynamic_cast<FunctionSymbol*>(sym);
		STNode* funcNode = dynamic_cast<IDENTIFIER *>(funcSym->m_node->m_children->front());
		auto temp = parent->m_children->front();
		parent->m_children->front() = funcNode;
		delete temp;
	}
	else {
		Symbol* sym = CScopeSystem::GetInstance()->Lookup(id->GetIdentifierText(),
			Symbol::ST_VARIABLE);
		if (sym == nullptr) {
			throw std::runtime_error("Variable not defined: " + id->GetIdentifierText());
		}
		VariableSymbol* varSym = dynamic_cast<VariableSymbol*>(sym);
		IDENTIFIER* varNode = dynamic_cast<IDENTIFIER*>(varSym->m_node);
		auto temp = parent->m_children->front();
		parent->m_children->front() = varNode;
		delete temp;
	}
}

void CScopeSystemVisitor::VisitExpressionList(ExpressionList* exprList) {
	CVisitor::VisitExpressionList(exprList);
	if (exprList->GetParent() != nullptr &&
		exprList->GetParent()->GetNodeType() == FUNCTIONDEFINITION) {
		// Exit Function Scope after processing all parameters
		CScopeSystem::GetInstance()->ExitScope();
	}
}
