#include <math.h>

#include "ConcreteNode.h"
#include "ScopeSystem.h"



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

int CompilationUnit::Evaluate() {
	int result = 0;
	for (auto child : *(this->m_children)) {
		result = child->Evaluate();
	}
	return result;
}

int IfStatement::Evaluate() {
	int result = 0;
	std::list<STNode*>::iterator it = m_children->begin();
	STNode* cond = (it != m_children->end()) ? *it : nullptr;
	// Evaluate condition
	if (cond == nullptr || !cond->Evaluate()) {
		// condition is false: execute else branch if present
		if (m_children->size() >= 3) {
			it = m_children->begin();
			if (it != m_children->end()) ++it; // then
			if (it != m_children->end()) ++it; // else
			if (it != m_children->end() && *it != nullptr) {
				result = (*it)->Evaluate();
			}
		}
	}
	else {
		// condition is true: execute then branch
		if (m_children->size() >= 2) {
			it = m_children->begin();
			if (it != m_children->end()) ++it; // then
			if (it != m_children->end() && *it != nullptr) {
				result = (*it)->Evaluate();
			}
		}
	}
	return result;
}
int ReturnStatement::Evaluate() {
	// If there is an expression, evaluate and return it.
	if (!m_children->empty()) {
		STNode* child = m_children->front();
		if (child != nullptr) {
			return child->Evaluate();
		}
	}
	return 0;
}

int ContinueStatement::Evaluate() {
	// Continue statements typically do not produce a runtime value.
	return 0;
}
int BreakStatement::Evaluate() {
	// Break statements typically do not produce a runtime value.
	return 0;
}
int VariableDeclaration::Evaluate() {
	// Evaluate the declarators node (which is responsible for actual
	// variable creation / initialization in symbol table aware visitors)
	if (m_children->size() >= 2) {
		auto it = m_children->begin();
		++it; // Move to declarators
		STNode* declarators = (it != m_children->end()) ? *it : nullptr;
		if (declarators != nullptr) {
			return declarators->Evaluate();
		}
	}
	return 0;
}
int Declarations::Evaluate() {
	// Evaluate all declarations in order, returning the last value
	int result = 0;
	for (auto child : *(this->m_children)) {
		if (child != nullptr) {
			result = child->Evaluate();
		}
	}
	return result;
}
int Declaration::Evaluate() {
	// Declarations typically don't produce a runtime value,
	// but we forward evaluation to the contained node for consistency.
	if (!m_children->empty()) {
		STNode* child = m_children->front();
		if (child != nullptr) {
			return child->Evaluate();
		}
	}
	return 0;
}
int Statement::Evaluate() {
	// Forward to the wrapped node
	if (!m_children->empty()) {
		STNode* child = m_children->front();
		if (child != nullptr) {
			return child->Evaluate();
		}
	}
	return 0;
}
int ExpressionStatement::Evaluate() {
	// Evaluate expression if present; otherwise it's just a ';'
	if (!m_children->empty()) {
		STNode* child = m_children->front();
		if (child != nullptr) {
			return child->Evaluate();
		}
	}
	return 0;
}
int CompoundStatement::Evaluate() {
	// Execute all statements in the compound block, return last value
	int result = 0;
	for (auto child : *(this->m_children)) {
		if (child != nullptr) {
			result = child->Evaluate();
		}
	}
	return result;
}

int TypeSpecifier::Evaluate() {
	return 0;
}

int Declarators::Evaluate() {
	// Evaluate all contained declarators, return last value
	int result = 0;
	for (std::list<STNode*>::iterator it = m_children->begin(); it != m_children->end(); ++it) {
		STNode* child = *it;
		if (child != nullptr) {
			result = child->Evaluate();
		}
	}
	return result;

}

int DirectDeclarator::Evaluate() {
	// Direct declarator itself is just a name; no runtime value.
	// Any initializer expression would be in another child node and
	// should be handled by the surrounding declarator logic.
	return 0;


}

int DoWhileLoop::Evaluate() {
	return 0;
}

int WhileLoop::Evaluate() {
	return 0;
}

int ForLoop::Evaluate() {
	// For loop evaluation logic would go here.
	// This is a placeholder implementation.

	return 0;
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
	CScopeSystem* scopeSystem = CScopeSystem::GetInstance();

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

int BuiltInFunctionCall::Evaluate() {
	return 0;
}

int FunctionDefinition::Evaluate() {
	return 0;
}

int ParamList::Evaluate() {
	return 0;
}

int Statements::Evaluate() {
	int result = 0;
	for (auto child : *(this->m_children)) {
		if (child != nullptr) {
			result = child->Evaluate();
		}
	}
	return result;
}

int EmptyStatement::Evaluate() {
	return 0;
}

int IfElseStatement::Evaluate() {
	return 0;
}
