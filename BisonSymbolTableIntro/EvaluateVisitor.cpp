#include <math.h>

#include "ConcreteNode.h"
#include "ScopeSystem.h"
#include "EvaluateVisitor.h"

void EvaluateVisitor::VisitNumber(NUMBER* num) {
	m_result = num->GetValue();
}
void EvaluateVisitor::VisitIdentifier(IDENTIFIER* id) {
	// FInd ID in Symbol table
	Symbol* symbol = CScopeSystem::GetInstance()->Lookup(id->GetIdentifierText(), Symbol::ST_VARIABLE);
	if (symbol != nullptr) {
		m_result = symbol->GetValue();
	}
	else {
		throw std::runtime_error("Undefined variable: " + id->GetIdentifierText());
	}
}
void EvaluateVisitor::VisitAddition(Addition* add) {
	int l_result, r_result;
	list<STNode*>::iterator it = add->m_children->begin();
	/* Evaluate left operand */
	Visit(*it);
	l_result = m_result;
	it++;
	Visit(*it);
	r_result = m_result;
	m_result = l_result + r_result;
}

void EvaluateVisitor::VisitAssignment(Assignment* assignment) {
	int r_result = 0;
	list<STNode*>::iterator it = assignment->m_children->begin();
	IDENTIFIER* id = dynamic_cast<IDENTIFIER*>(*it);
	Symbol* s = CScopeSystem::GetInstance()->Lookup(id->GetIdentifierText(), Symbol::ST_VARIABLE);
	if (s == nullptr) {
		throw std::runtime_error("Undefined variable in assignment: " + id->GetIdentifierText());
	}
	it++;
	Visit(*it);
	r_result = m_result;
	s->m_value = r_result;
	cout << id->GetIdentifierText() << " = " << r_result << '\n';
}
void EvaluateVisitor::VisitSubtraction(Subtraction* sub) {
	int l_result, r_result;
	list<STNode*>::iterator it = sub->m_children->begin();
	/* Evaluate left operand */
	Visit(*it);
	l_result = m_result;
	it++;
	Visit(*it);
	r_result = m_result;
	m_result = l_result - r_result;
}
void EvaluateVisitor::VisitMultiplication(Multiplication* mul) {
	int l_result, r_result;
	list<STNode*>::iterator it = mul->m_children->begin();
	/* Evaluate left operand */
	Visit(*it);
	l_result = m_result;
	it++;
	Visit(*it);
	r_result = m_result;
	m_result = l_result * r_result;
}
void EvaluateVisitor::VisitDivision(Division* div) {
	int l_result, r_result;
	list<STNode*>::iterator it = div->m_children->begin();
	/* Evaluate left operand */
	Visit(*it);
	l_result = m_result;
	it++;
	Visit(*it);
	r_result = m_result;
	if (r_result == 0) {
		throw std::runtime_error("Division by zero.");
	}

	m_result = l_result / r_result;
}
void EvaluateVisitor::VisitModulo(Modulo* mod) {
	int l_result, r_result;
	list<STNode*>::iterator it = mod->m_children->begin();
	/* Evaluate left operand */
	Visit(*it);
	l_result = m_result;
	it++;
	Visit(*it);
	r_result = m_result;
	if (r_result == 0) {
		throw std::runtime_error("Division by zero in modulo operation.");
	}

	m_result = l_result % r_result;
}
void EvaluateVisitor::VisitExponentiation(Exponentiation* expon) {
	int l_result, r_result;
	list<STNode*>::iterator it = expon->m_children->begin();
	/* Evaluate left operand */
	Visit(*it);
	l_result = m_result;
	it++;
	Visit(*it);
	r_result = m_result;
	m_result = pow(l_result, r_result);
}
void EvaluateVisitor::VisitUnaryMinus(UnaryMinus* unMinus) {
	list<STNode*>::iterator it = unMinus->m_children->begin();
	Visit(*it);
	m_result = -m_result;
}
void EvaluateVisitor::VisitUnaryPlus(UnaryPlus* unPlus) {
	list<STNode*>::iterator it = unPlus->m_children->begin();
	Visit(*it);
	m_result = +m_result;
}
void EvaluateVisitor::VisitFloorDivision(FloorDivision* fdiv) {
	int l_result, r_result;
	list<STNode*>::iterator it = fdiv->m_children->begin();
	/* Evaluate left operand */
	Visit(*it);
	l_result = m_result;
	it++;
	Visit(*it);
	r_result = m_result;
	if (r_result) {
		m_result = floor(l_result / r_result);
	}
	else {
		throw std::runtime_error("Division by zero in floor division.");
	}
}
void EvaluateVisitor::VisitLogicalAnd(LogicalAnd* logicalAnd) {
	int l_result, r_result;
	list<STNode*>::iterator it = logicalAnd->m_children->begin();
	/* Evaluate left operand */
	Visit(*it);
	l_result = m_result;
	it++;
	Visit(*it);
	r_result = m_result;
	m_result = l_result && r_result;
}
void EvaluateVisitor::VisitLogicalOr(LogicalOr* logicalOr) {
	int l_result, r_result;
	list<STNode*>::iterator it = logicalOr->m_children->begin();
	/* Evaluate left operand */
	Visit(*it);
	l_result = m_result;
	it++;
	Visit(*it);
	r_result = m_result;
	m_result = l_result || r_result;
}
void EvaluateVisitor::VisitLogicalNot(LogicalNot* logicalNot) {
	list<STNode*>::iterator it = logicalNot->m_children->begin();
	Visit(*it);
	m_result = !m_result;
}
void EvaluateVisitor::VisitLessThan(LessThan* lessThan) {
	int l_result, r_result;
	list<STNode*>::iterator it = lessThan->m_children->begin();
	/* Evaluate left operand */
	Visit(*it);
	l_result = m_result;
	it++;
	Visit(*it);
	r_result = m_result;
	m_result = l_result < r_result;
}
void EvaluateVisitor::VisitGreaterThan(GreaterThan* greaterThan) {
	int l_result, r_result;
	list<STNode*>::iterator it = greaterThan->m_children->begin();
	/* Evaluate left operand */
	Visit(*it);
	l_result = m_result;
	it++;
	Visit(*it);
	r_result = m_result;
	m_result = l_result > r_result;
}
void EvaluateVisitor::VisitLessThanOrEqual(LessThanOrEqual* lessThanOrEqual) {
	int l_result, r_result;
	list<STNode*>::iterator it = lessThanOrEqual->m_children->begin();
	/* Evaluate left operand */
	Visit(*it);
	l_result = m_result;
	it++;
	Visit(*it);
	r_result = m_result;
	m_result = l_result <= r_result;
}
void EvaluateVisitor::VisitGreaterThanOrEqual(GreaterThanOrEqual* greaterThanOrEqual) {
	int l_result, r_result;
	list<STNode*>::iterator it = greaterThanOrEqual->m_children->begin();
	/* Evaluate left operand */
	Visit(*it);
	l_result = m_result;
	it++;
	Visit(*it);
	r_result = m_result;
	m_result = l_result >= r_result;
}
void EvaluateVisitor::VisitEqual(Equal* equalExpr) {
	int l_result, r_result;
	list<STNode*>::iterator it = equalExpr->m_children->begin();
	/* Evaluate left operand */
	Visit(*it);
	l_result = m_result;
	it++;
	Visit(*it);
	r_result = m_result;
	m_result = l_result == r_result;
}
void EvaluateVisitor::VisitNotEqual(NotEqual* notEqual) {
	int l_result, r_result;
	list<STNode*>::iterator it = notEqual->m_children->begin();
	/* Evaluate left operand */
	Visit(*it);
	l_result = m_result;
	it++;
	Visit(*it);
	r_result = m_result;
	m_result = l_result != r_result;
}
void EvaluateVisitor::VisitIncrement(Increment* increment) {
	list<STNode*>::iterator it = increment->m_children->begin();
	Visit(*it);
	m_result++;
}
void EvaluateVisitor::VisitDecrement(Decrement* decrement) {
	list<STNode*>::iterator it = decrement->m_children->begin();
	Visit(*it);
	m_result--;
}

void EvaluateVisitor::GetActualArguments(STNode *arguments_root)
{
	// Evaluate and store
	list<STNode*>::iterator fit = arguments_root->m_children->begin();
	list<STNode*>::iterator sit;
	if (arguments_root->m_children->size() == 1)
	{
		Visit(*fit);
		m_argValues.push_back(m_result);
	}
	else
	{
		sit = fit++;
		Visit(*sit);
		m_argValues.push_back(m_result);
		GetActualArguments(*fit);
	}
}

void EvaluateVisitor::GetFormalArguments(STNode* f_arguments_root) {
	// Evaluate and store
	list<STNode*>::iterator fit = f_arguments_root->m_children->begin();
	list<STNode*>::iterator sit;
	IDENTIFIER* id;
	if (f_arguments_root->m_children->size() == 1) {
		id = dynamic_cast<IDENTIFIER*>(*fit);
		m_formalParams.push_back(id->GetIdentifierText());
	}
	else {
		sit = fit++;
		id = dynamic_cast<IDENTIFIER*>(*sit);
		m_formalParams.push_back(id->GetIdentifierText());
		GetFormalArguments(*fit);
	}
}

void EvaluateVisitor::VisitUserDefinedFunctionCall(
	UserDefinedFunctionCall* userFuncCall) {

	// 1. Get function name
	IDENTIFIER* id = dynamic_cast<IDENTIFIER*>(
		*(userFuncCall->m_children->begin()));

	// 2. Lookup function in symbol table
	Symbol* funcSymbol = CScopeSystem::GetInstance()->Lookup(
		id->GetIdentifierText(), Symbol::ST_FUNCTION);

	// 3. Map arguments to parameters
	if (userFuncCall->m_children->size() == 2)
	{
		STNode* arguments_root = *(++(userFuncCall->m_children->begin()));
		GetActualArguments(arguments_root);
	}

	STNode* f_arguments_root;
	FunctionDefinition* funcDef = dynamic_cast<FunctionDefinition*>(funcSymbol->m_node);
	if (funcDef->m_children->size() == 4) {
		// FunctionDefinition has ParamList
		f_arguments_root = *(++(++(funcDef->m_children->begin())));
		GetFormalArguments(f_arguments_root);
	}
	else {
		// FunctionDefinition has no ParamList
		f_arguments_root = nullptr;
	}

	// Map actual arguments to formal parameters in new scope by mapping the contents 
	// of m_argValues to m_formalParams	
	if (f_arguments_root != nullptr) {
		auto fit = m_formalParams.begin();
		auto sit = m_argValues.begin();
		while (fit != m_formalParams.end() && sit != m_argValues.end()) {
			// Create VariableSymbol for each formal parameter
			VariableSymbol* paramSymbol =
			 dynamic_cast<VariableSymbol*>(CScopeSystem::GetInstance()->
				 Lookup(*fit,funcSymbol->m_name, Symbol::ST_VARIABLE));
			if (paramSymbol == nullptr) {
				throw std::runtime_error("Undefined parameter in function call: " + *fit);
			}
			paramSymbol->m_value = *sit;
			++fit;
			++sit;

		}

	}
	// 4. Execute function body
	Visit(funcSymbol->m_node);

}
void EvaluateVisitor::VisitBuiltinFunctionCall(BuiltInFunctionCall* builtinFuncCall) {}
void EvaluateVisitor::VisitBitAnd(BITWISEAND* bitAnd) {
	int l_result, r_result;
	list<STNode*>::iterator it = bitAnd->m_children->begin();
	/* Evaluate left operand */
	Visit(*it);
	l_result = m_result;
	it++;
	Visit(*it);
	r_result = m_result;
	m_result = l_result & r_result;
}
void EvaluateVisitor::VisitBitOr(BITWISEOR* bitOr) {
	int l_result, r_result;
	list<STNode*>::iterator it = bitOr->m_children->begin();
	/* Evaluate left operand */
	Visit(*it);
	l_result = m_result;
	it++;
	Visit(*it);
	r_result = m_result;
	m_result = l_result | r_result;
}
void EvaluateVisitor::VisitBitXor(BITWISEXOR* bitXor) {
	int l_result, r_result;
	list<STNode*>::iterator it = bitXor->m_children->begin();
	/* Evaluate left operand */
	Visit(*it);
	l_result = m_result;
	it++;
	Visit(*it);
	r_result = m_result;
	m_result = l_result ^ r_result;
}
void EvaluateVisitor::VisitBitNot(BITWISENOT* bitNot) {
	list<STNode*>::iterator it = bitNot->m_children->begin();
	Visit(*it);
	m_result = ~m_result;
}
void EvaluateVisitor::VisitLeftShift(LSHIFT* lshift) {
	int l_result, r_result;
	list<STNode*>::iterator it = lshift->m_children->begin();
	/* Evaluate left operand */
	Visit(*it);
	l_result = m_result;
	it++;
	Visit(*it);
	r_result = m_result;
	m_result = l_result << r_result;
}
void EvaluateVisitor::VisitRightShift(RSHIFT* rshift) {
	int l_result, r_result;
	list<STNode*>::iterator it = rshift->m_children->begin();
	/* Evaluate left operand */
	Visit(*it);
	l_result = m_result;
	it++;
	Visit(*it);
	r_result = m_result;
	m_result = l_result >> r_result;
}
void EvaluateVisitor::VisitArgumentList(ArgumentList* argList) {}
void EvaluateVisitor::VisitFunctionDefinition(FunctionDefinition* funcDef)
{
	CScopeSystem::GetInstance()->EnterScope(funcDef->GetName());
	// Assuming it runs after Function Call
	// Visit only the body
	auto it = funcDef->m_children->begin();
	if (funcDef->m_children->size() == 4) {
		// FunctionDefinition has ParamList
		it++; // Skip TypeSpecifier
		it++; // Skip Identifier
		it++; // Skip ParamList
		STNode* funcBody = *it;
		Visit(funcBody);
	}
	else {
		// FunctionDefinition has no ParamList
		it++; // Skip TypeSpecifier
		it++; // Skip Identifier
		STNode* funcBody = *it;
		Visit(funcBody);
	}
	CScopeSystem::GetInstance()->ExitScope();
}
void EvaluateVisitor::VisitParameterList(ParamList* paramList) {}
/*void EvaluateVisitor::VisitCompilationUnit(CompilationUnit* compUnit) {}
void EvaluateVisitor::VisitStatement(Statement* statement) {}
void EvaluateVisitor::VisitStatements(Statements* stmts) {}*/
void EvaluateVisitor::VisitDeclaration(Declaration* decl) {}
/*void EvaluateVisitor::VisitDeclarations(Declarations* decls) {}*/
void EvaluateVisitor::VisitVariableDeclaration(VariableDeclaration* varDecl) {}
void EvaluateVisitor::VisitTypeSpecifier(TypeSpecifier* typeSpec) {}
void EvaluateVisitor::VisitDeclarators(Declarators* decls) {}
void EvaluateVisitor::VisitDirectDeclarator(DirectDeclarator* directDecl) {}
void EvaluateVisitor::VisitExpressionStatement(ExpressionStatement* exprStmt) {}
void EvaluateVisitor::VisitCompoundStatement(CompoundStatement* compStmt) {}
void EvaluateVisitor::VisitForLoop(ForLoop* forLoop) {
	if (forLoop->m_children->size() == 4) {
		// for (init; condition; increment) body
		auto it = forLoop->m_children->begin();
		// init
		Visit(*it);    /*for (i=0; i<100*/
		it++;
		// condition
		STNode* conditionNode = *it;
		it++;
		// increment
		STNode* incrementNode = *it;
		it++;
		// body
		STNode* bodyNode = *it;
		while (true) {
			Visit(conditionNode);
			if (m_result == 0) {
				break;
			}
			Visit(bodyNode);
			Visit(incrementNode);
		}
	}
	else if (forLoop->m_children->size() == 3) {
		// for (init; condition) body
		auto it = forLoop->m_children->begin();
		// init
		Visit(*it);
		it++;
		// condition
		STNode* conditionNode = *it;
		it++;
		// body
		STNode* bodyNode = *it;
		while (true) {
			Visit(conditionNode);
			if (m_result == 0) {
				break;
			}
			Visit(bodyNode);
		}
	}
}
void EvaluateVisitor::VisitWhileLoop(WhileLoop* whileLoop) {
	auto it = whileLoop->m_children->begin();
	// condition
	STNode* conditionNode = *it;
	it++;
	// body
	STNode* bodyNode = *it;
	while (true) {
		Visit(conditionNode);
		if (m_result == 0) {
			break;
		}
		Visit(bodyNode);
	}
}
void EvaluateVisitor::VisitDoWhileLoop(DoWhileLoop* doWhileLoop) {
	auto it = doWhileLoop->m_children->begin();
	// body
	STNode* bodyNode = *it;
	it++;
	// condition
	STNode* conditionNode = *it;
	do {
		Visit(bodyNode);
		Visit(conditionNode);
	} while (m_result != 0);
}
void EvaluateVisitor::VisitIfStatement(IfStatement* ifStmt) {
	auto it = ifStmt->m_children->begin();
	// condition
	STNode* conditionNode = *it;
	it++;
	// then branch
	STNode* thenBranchNode = *it;
	Visit(conditionNode);
	if (m_result != 0) {
		Visit(thenBranchNode);
	}
}
void EvaluateVisitor::VisitReturnStatement(ReturnStatement* returnStmt) {}
void EvaluateVisitor::VisitBreakStatement(BreakStatement* breakStmt) {}
void EvaluateVisitor::VisitContinueStatement(ContinueStatement* continueStmt) {

}
void EvaluateVisitor::VisitEmptyStatement(EmptyStatement* emptyStmt) {
	// Do nothing
}
void EvaluateVisitor::VisitIfElseStatement(IfElseStatement* ifElseStmt) {
	auto it = ifElseStmt->m_children->begin();
	// condition
	STNode* conditionNode = *it;
	it++;
	// then branch
	STNode* thenBranchNode = *it;
	it++;
	// else branch
	STNode* elseBranchNode = *it;
	Visit(conditionNode);
	if (m_result != 0) {
		Visit(thenBranchNode);
	}
	else {
		Visit(elseBranchNode);
	}
}