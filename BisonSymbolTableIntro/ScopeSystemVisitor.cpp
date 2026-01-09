#include "ScopeSystemVisitor.h"

#include "ScopeSystem.h"

void CScopeSystemVisitor::VisitFunctionDefinition(FunctionDefinition* funcDef) {

	// 0. Get the IDENTIFIER child node
	IDENTIFIER* id = dynamic_cast<IDENTIFIER*>(funcDef->m_children->front());

	// 1. Create FunctionSymbol with parent as FunctionDefinition node 
	Symbol* funcSymbol = new FunctionSymbol(funcDef,
		FunctionSymbol::FT_USERDEFINEDFUNCTION,
		id->GetIdentifierText());

	// 2. Insert FunctionSymbol into Global Scope
	CScopeSystem::GetInstance()->Insert(id->GetIdentifierText(),
		funcSymbol);

	// 3. Enter Function Scope if parent is FunctionDefinition
	CScopeSystem::GetInstance()->EnterScope(id->GetIdentifierText());
	
	for (	auto it = std::next(funcDef->m_children->begin()); 
			it != funcDef->m_children->end(); 
			++it) {
		Visit((*it));
	}
}

void CScopeSystemVisitor::VisitParameterList(ParamList* paramList) {

	if (paramList->m_children->size() == 2) // ParamList and ID
	{
		auto it = paramList->m_children->begin();
		Visit((*it));
		CVisitor::Visit(*it);
		it++;

	}

	// 0. Get the IDENTIFIER child node
	IDENTIFIER* id = dynamic_cast<IDENTIFIER*>(paramList->m_children->front());

	// 1. Create VariableSymbol with parent as PARAMLIST node
	VariableSymbol* sym = new VariableSymbol(id, id->GetIdentifierText());

	// 2. Insert VariableSymbol into Current Scope (Function Scope)
	CScopeSystem::GetInstance()->Insert(id->GetIdentifierText(), sym);

}

void CScopeSystemVisitor::VisitAssignment(Assignment* assignment) {
	// 0. Get the IDENTIFIER child node
	IDENTIFIER* id = dynamic_cast<IDENTIFIER*>(assignment->m_children->front());

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
		auto temp = assignment->m_children->front();
		assignment->m_children->front() = varNode;
		delete temp;
	}

	auto it = assignment->m_children->begin();
	it++;
	Visit((*it));
}

void CScopeSystemVisitor::VisitBuiltinFunctionCall(BuiltInFunctionCall* builtinFuncCall) {

	// 0. Get the IDENTIFIER child node
	IDENTIFIER* id = dynamic_cast<IDENTIFIER*>(builtinFuncCall->m_children->front());

	// 1. Lookup FunctionSymbol in Global Scope
	Symbol* sym = CScopeSystem::GetInstance()->Lookup(id->GetIdentifierText(),
		Symbol::ST_FUNCTION);
	if (sym == nullptr) {
		throw std::runtime_error("Function not defined: " + id->GetIdentifierText());
	}
	FunctionSymbol* funcSym = dynamic_cast<FunctionSymbol*>(sym);
	STNode* funcNode = dynamic_cast<IDENTIFIER*>(funcSym->m_node->m_children->front());
	auto temp = builtinFuncCall->m_children->front();
	builtinFuncCall->m_children->front() = funcNode;
	delete temp;

	for (auto it = std::next(builtinFuncCall->m_children->begin());
		it != builtinFuncCall->m_children->end();
		++it) {
		Visit((*it));
	}
}

void CScopeSystemVisitor::VisitUserDefinedFunctionCall(UserDefinedFunctionCall* userFuncCall) {
	// 0. Get the IDENTIFIER child node
	IDENTIFIER* id = dynamic_cast<IDENTIFIER*>(userFuncCall->m_children->front());

	// 1. Lookup FunctionSymbol in Global Scope
	Symbol* sym = CScopeSystem::GetInstance()->Lookup(id->GetIdentifierText(),
		Symbol::ST_FUNCTION);
	if (sym == nullptr) {
		throw std::runtime_error("Function not defined: " + id->GetIdentifierText());
	}
	FunctionSymbol* funcSym = dynamic_cast<FunctionSymbol*>(sym);
	STNode* funcNode = dynamic_cast<IDENTIFIER*>(funcSym->m_node->m_children->front());
	auto temp = userFuncCall->m_children->front();
	userFuncCall->m_children->front() = funcNode;
	delete temp;

	for (auto it = std::next(userFuncCall->m_children->begin());
		it != userFuncCall->m_children->end();
		++it) {
		Visit((*it));
	}
}

void CScopeSystemVisitor::VisitIdentifier(IDENTIFIER* id) {

	STNode* parent = id->GetParent();

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

void CScopeSystemVisitor::VisitExpressionList(ExpressionList* exprList) {
	CVisitor::VisitExpressionList(exprList);
	if (exprList->GetParent() != nullptr &&
		exprList->GetParent()->GetNodeType() == FUNCTIONDEFINITION) {
		// Exit Function Scope after processing all parameters
		CScopeSystem::GetInstance()->ExitScope();
	}
}
