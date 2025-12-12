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
	return 0;
}

int Decrement::Evaluate() {
	return 0;
}

int Subtraction::Evaluate() {	
	return 0;
}

int Multiplication::Evaluate() {
	return 0;
}
int Division::Evaluate() {
	return 0;
}
int Modulo::Evaluate() {
	return 0;
}
int Exponentiation::Evaluate() {
	return 0;
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
int FunctionCall::Evaluate() {
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







