#include <math.h>

#include "ConcreteNode.h"
#include "SymbolTable.h"

int STNode::Evaluate() {
	std::list<STNode*>::iterator it;
	for (it = m_children->begin(); it != m_children->end(); ++it) {
		STNode* child = *it;
		child->Evaluate();
	}
	return 0;
}

int NUMBER::Evaluate() {
	return GetValue();
}

int IDENTIFIER::Evaluate() {
	return GetValue();
}

int Addition::Evaluate() {
	std::list<STNode*>::iterator it;
	STNode* left;
	STNode* right;
	it = m_children->begin();
	left = *it;
	it++;
	right = *it;
	return left->Evaluate() + right->Evaluate();
}

int ExpressionList::Evaluate() {
	std::list<STNode*>::iterator it;
	int nchildren;
	int result;
	nchildren = m_children->size();
	it = m_children->begin();
	if (nchildren == 1) {
		result = (*it)->Evaluate();
		if ((*it)->GetNodeType() != ASSIGNMENT) {
			// Do nothing, assignment already prints result
			cout << "Expression Result: " << result << endl;
		}
	}
	else {
		result = (*it)->Evaluate();
		it++;
		result = (*it)->Evaluate();
		if ((*it)->GetNodeType() != ASSIGNMENT) {
			cout << "Expression Result: " << result << endl;
		}
	}
	return result;
}

int Assignment::Evaluate() {
	std::list<STNode*>::iterator it;
	int result;
	// 1. Get identifier from symbol table
	SymbolTable* symtab = SymbolTable::GetInstance();

	// 2. Get identifier node
	it = m_children->begin();
	IDENTIFIER* idnode = dynamic_cast<IDENTIFIER*>((*it));

	// 2. Evaluate expression
	it++;
	result = (*it)->Evaluate();

	// 3. Set identifier value
	idnode->SetValue(result);
	// 4. Report assignment to console
	cout << idnode->GetIdentifierText() << " = " << result << endl;

	return result;
}

int Increment::Evaluate() {
	auto it = m_children->begin();
	IDENTIFIER* idnode = dynamic_cast<IDENTIFIER*>((*it));
	// 1. Evaluate expression
	int result = (*it)->Evaluate();
	// 2. Assign value to IDENTIFIER
	return idnode->SetValue(result + 1);
}

int Decrement::Evaluate() {
	auto it = m_children->begin();
	IDENTIFIER* idnode = dynamic_cast<IDENTIFIER*>((*it));
	// 1. Evaluate expression
	int result = (*it)->Evaluate();
	// 2. Assign value to IDENTIFIER
	return idnode->SetValue(result - 1);
}

int Subtraction::Evaluate() {	
	list<STNode*>::iterator it = m_children->begin();
	return (*it)->Evaluate() - (*(++it))->Evaluate();
}

int Multiplication::Evaluate() {
	auto it = m_children->begin();
	return (*it)->Evaluate() * (*(++it))->Evaluate();
}
int Division::Evaluate() {
	auto it = m_children->begin();
	int left = (*it)->Evaluate();
	int right = (*(++it))->Evaluate();
	if (right == 0) {
		throw std::runtime_error("Division by zero");
	}
	return left / right;
}
int Modulo::Evaluate() {
	auto it = m_children->begin();
	int left = (*it)->Evaluate();
	int right = (*(++it))->Evaluate();
	if (right == 0) {
		throw std::runtime_error("Modulo by zero");
	}
	return left % right;
}
int Exponentiation::Evaluate() {
	auto it = m_children->begin();
	int left = (*it)->Evaluate();
	int right = (*(++it))->Evaluate();

	return pow(left, right);
}
int UnaryMinus::Evaluate() {
	return 0;
}
int UnaryPlus::Evaluate() {
	return 0;
}
int FloorDivision::Evaluate() {
	return 0;
}
int LogicalAnd::Evaluate() {
	return 0;
}
int LogicalOr::Evaluate() {
	return 0;
}
int LogicalNot::Evaluate() {
	return 0;
}
int LessThan::Evaluate() {
	return 0;
}
int GreaterThan::Evaluate() {
	return 0;
}
int LessThanOrEqual::Evaluate() {
	return 0;
}
int GreaterThanOrEqual::Evaluate() {
	return 0;
}
int Equal::Evaluate() {
	return 0;
}
int NotEqual::Evaluate() {
	return 0;
}
int UserDefinedFunctionCall::Evaluate() {
	return 0;
}
int BITWISEAND::Evaluate() {
	return 0;
}
int BITWISEOR::Evaluate() {
	return 0;
}
int BITWISEXOR::Evaluate() {
	return 0;
}
int BITWISENOT::Evaluate() {
	return 0;
}
int LSHIFT::Evaluate() {
	return 0;
}
int RSHIFT::Evaluate() {
	return 0;
}
int ArgumentList::Evaluate() {
	return 0;
}

int BuiltInFunctionCall::Evaluate()
{
	return 0;
}

int FunctionDefinition::Evaluate()
{
	return 0;
}

int ParamList::Evaluate()
{
	return 0;
}




