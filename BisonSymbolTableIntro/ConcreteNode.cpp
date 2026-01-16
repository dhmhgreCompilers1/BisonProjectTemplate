#include "ConcreteNode.h"

#include "Visitor.h"

string g_nodetypesstr[] = { "NA","NUMBER","IDENTIFIER",
	"ADDITION", "EXPRESSIONLIST" ,"ASSIGNMENT",

	"SUBTRACTION", "MULTIPLICATION", "DIVISION", "MODULUS", "EXPONENTIATION",
	"UNARYMINUS","UNARYPLUS", "FLOORDIVISION", "LOGICALAND", "LOGICALOR",
	"LOGICALNOT", "LESSTHAN", "GREATERTHAN","LESSTHANOREQUAL", "GREATERTHANOREQUAL",
	"EQUAL", "NOTEQUAL", "INCREMENT", "DECREMENT", "USERDEFINEDFUNCTIONCALL",
	"BUILTINFUNCTIONCALL",
	   "BITWISEAND","BITWISEOR","BITWISEXOR", "BITWISENOT",
		"LSHIFT", "RSHIFT" , "ARGUMENTLIST", "FUNCTIONDEFINITION", "PARAMLIST",
	"STATEMENT", "STATEMENTLIST", "COMPILATION_UNIT", "DECLARATION", "VARIABLEDECLARATION",
	"TYPESPECIFIER", "DECLARATORS", "DIRECTDECLARATOR","ARRAYDIRECTDECLARATOR", "EXPRESSIONSTATEMENT",
	"COMMPOUNDSTATEMENT", "FORLOOP", "WHILELOOP", "DOWHILELOOP", "IFSTATEMENT",
	"RETURNSTATEMENT", "BREAKSTATEMENT", "CONTINUESTATEMENT", "DECLARATIONS", "EMPTYSTATEMENT",
	"IFELSESTATEMENT"
};
STNode* STNode::mg_root = nullptr;


NUMBER::NUMBER(char* text) :STNode(nodetypeid::NUMBER_) {
	m_number = text;
	m_value = atoi(text);
	m_graphvizID += "_value_=" + to_string(m_value);
}

NUMBER::~NUMBER() {
}


string NUMBER::GetNumberText() {
	return m_number;
}

int NUMBER::GetValue() {
	return m_value;
}

IDENTIFIER::IDENTIFIER(char* text) : STNode(IDENTIFIER_) {
	m_identifier = text;
	m_graphvizID += "_name_=" + m_identifier;
}

int IDENTIFIER::SetValue(int v) {
	return (m_value = v);
}

int IDENTIFIER::GetValue() {
	return m_value;
}

void IDENTIFIER::Accept(CVisitor* visitor) {
	visitor->VisitIdentifier(this);
}

IDENTIFIER::~IDENTIFIER() {
}

string IDENTIFIER::GetIdentifierText() {
	return m_identifier;
}

CompilationUnit::CompilationUnit(STNode* c1) : STNode(COMPILATION_UNIT) {
	AddChild(c1);
	c1->setParent(this);
}
CompilationUnit::CompilationUnit(STNode* c1, STNode* c2) : STNode(COMPILATION_UNIT) {
	AddChild(c1);
	AddChild(c2);
	c1->setParent(this);
	c2->setParent(this);
}

void CompilationUnit::Accept(CVisitor* visitor) {
	visitor->VisitCompilationUnit(this);
}

void Declaration::Accept(CVisitor* visitor) {
	visitor->VisitDeclaration(this);
}
Declaration::Declaration(STNode* node) : STNode(DECLARATION) {
	AddChild(node);
	node->setParent(this);
}

Declarations::Declarations(STNode* declaration) : STNode(DECLARATIONS) {
	AddChild(declaration);
	declaration->setParent(this);
}
Declarations::Declarations(STNode* declarations, STNode* declaration) : STNode(DECLARATIONS) {
	AddChild(declarations);
	AddChild(declaration);
	declarations->setParent(this);
	declaration->setParent(this);
}
void Declarations::Accept(CVisitor* visitor) {
	visitor->VisitDeclarations(this);
}


VariableDeclaration::VariableDeclaration(STNode* typeSpecifier, STNode* declarators) : STNode(VARIABLEDECLARATION) {
	AddChild(typeSpecifier);
	AddChild(declarators);
	typeSpecifier->setParent(this);
	declarators->setParent(this);
}
void VariableDeclaration::Accept(CVisitor* visitor) {
	visitor->VisitVariableDeclaration(this);
}

TypeSpecifier::TypeSpecifier(string type) : STNode(TYPESPECIFIER) {
	m_graphvizID += "_type_=" + type;
}
void TypeSpecifier::Accept(CVisitor* visitor) {
	visitor->VisitTypeSpecifier(this);
}
Declarators::Declarators(STNode* node) : STNode(DECLARATORS) {
	AddChild(node);
	node->setParent(this);
}
Declarators::Declarators(STNode* declarators, STNode* directDeclarator) : STNode(DECLARATORS) {
	AddChild(declarators);
	AddChild(directDeclarator);
	declarators->setParent(this);
	directDeclarator->setParent(this);
}
Declarators::Declarators(STNode* declarators, STNode* directDeclarator, STNode* expression) : STNode(DECLARATORS) {
	AddChild(declarators);
	AddChild(directDeclarator);
	AddChild(expression);
	declarators->setParent(this);
	directDeclarator->setParent(this);
	expression->setParent(this);
}

void Declarators::Accept(CVisitor* visitor) {
	visitor->VisitDeclarators(this);
}


DirectDeclarator::DirectDeclarator(STNode* directDeclarator) : STNode(DIRECTDECLARATOR) {
	AddChild(directDeclarator);
	directDeclarator->setParent(this);
}
DirectDeclarator::DirectDeclarator(string identifier) : STNode(DIRECTDECLARATOR) {
	m_graphvizID += "_identifier_=" + identifier;
}
void DirectDeclarator::Accept(CVisitor* visitor) {
	visitor->VisitDirectDeclarator(this);
}


/*

statement : expression_statement
		  | compound_statement
		  | iteration_statement
		  | selection_statement
		  | jump_statement
		  ;
expression_statement : expression SEMICOLON
						| SEMICOLON
						;

compound_statement : '{' statements '}'
						| '{' '}'
						;

iteration_statement : WHILE '(' expression ')' statement
					| FOR '(' expression_statement expression_statement  expression ')' statement
					| FOR '(' expression_statement expression_statement ')' statement
					| DO statement WHILE '(' expression ')' SEMICOLON
					;

selection_statement : IF '(' expression ')' statement ELSE statement
					| IF '(' expression ')' statement		%prec LOWIF
					;
jump_statement : RETURN expression SEMICOLON
			   | RETURN SEMICOLON
			   | BREAK SEMICOLON
			   | CONTINUE SEMICOLON
 *
 */





Addition::Addition(STNode* number) :STNode(ADDITION) {
	AddChild(number);
	number->setParent(this);
}

Addition::Addition(STNode* addition, STNode* number) : STNode(ADDITION) {
	AddChild(addition);
	AddChild(number);
	addition->setParent(this);
	number->setParent(this);
}

Assignment::Assignment(STNode* identifier, STNode* addition) :
	STNode(ASSIGNMENT) {
	AddChild(identifier);
	AddChild(addition);
	addition->setParent(this);
	identifier->setParent(this);
}

Subtraction::Subtraction(STNode* lexpression, STNode* rexpression) :STNode(SUBTRACTION) {
	AddChild(lexpression);
	AddChild(rexpression);
	lexpression->setParent(this);
	rexpression->setParent(this);
}

Multiplication::Multiplication(STNode* lexpression, STNode* rexpression) : STNode(MULTIPLICATION) {
	AddChild(lexpression);
	AddChild(rexpression);
	lexpression->setParent(this);
	rexpression->setParent(this);
}

Division::Division(STNode* lexpression, STNode* rexpression) : STNode(DIVISION) {
	AddChild(lexpression);
	AddChild(rexpression);
	lexpression->setParent(this);
	rexpression->setParent(this);
}

Modulo::Modulo(STNode* lexpression, STNode* rexpression) : STNode(MODULUS) {
	AddChild(lexpression);
	AddChild(rexpression);
	lexpression->setParent(this);
	rexpression->setParent(this);
}

Exponentiation::Exponentiation(STNode* lexpression, STNode* rexpression) : STNode(EXPONENTIATION) {
	AddChild(lexpression);
	AddChild(rexpression);
	lexpression->setParent(this);
	rexpression->setParent(this);
}

FloorDivision::FloorDivision(STNode* lexpression, STNode* rexpression) : STNode(FLOORDIVISION) {
	AddChild(lexpression);
	AddChild(rexpression);
	lexpression->setParent(this);
	rexpression->setParent(this);
}

UnaryMinus::UnaryMinus(STNode* expression) : STNode(UNARYMINUS) {
	AddChild(expression);
	expression->setParent(this);
}

UnaryPlus::UnaryPlus(STNode* expression) : STNode(UNARYPLUS) {
	AddChild(expression);
	expression->setParent(this);
}

LogicalAnd::LogicalAnd(STNode* lhs, STNode* rhs) : STNode(LOGICALAND) {
	AddChild(lhs);
	AddChild(rhs);
	lhs->setParent(this);
	rhs->setParent(this);
}

LogicalOr::LogicalOr(STNode* lhs, STNode* rhs) : STNode(LOGICALOR) {
	AddChild(lhs);
	AddChild(rhs);
	lhs->setParent(this);
	rhs->setParent(this);
}

LogicalNot::LogicalNot(STNode* expr) : STNode(LOGICALNOT) {
	AddChild(expr);
	expr->setParent(this);
}

Increment::Increment(STNode* identifier) : STNode(INCREMENT) {
	AddChild(identifier);
	identifier->setParent(this);
}

Decrement::Decrement(STNode* identifier) : STNode(DECREMENT) {
	AddChild(identifier);
	identifier->setParent(this);
}

Equal::Equal(STNode* lhs, STNode* rhs) : STNode(EQUAL) {
	AddChild(lhs);
	AddChild(rhs);
	lhs->setParent(this);
	rhs->setParent(this);
}

NotEqual::NotEqual(STNode* lhs, STNode* rhs) : STNode(NOTEQUAL) {
	AddChild(lhs);
	AddChild(rhs);
	lhs->setParent(this);
	rhs->setParent(this);
}

LessThan::LessThan(STNode* lhs, STNode* rhs) : STNode(LESSTHAN) {
	AddChild(lhs);
	AddChild(rhs);
	lhs->setParent(this);
	rhs->setParent(this);
}
GreaterThan::GreaterThan(STNode* lhs, STNode* rhs) : STNode(GREATERTHAN) {
	AddChild(lhs);
	AddChild(rhs);
	lhs->setParent(this);
	rhs->setParent(this);
}
LessThanOrEqual::LessThanOrEqual(STNode* lhs, STNode* rhs) : STNode(LESSTHANOREQUAL) {
	AddChild(lhs);
	AddChild(rhs);
	lhs->setParent(this);
	rhs->setParent(this);
}
GreaterThanOrEqual::GreaterThanOrEqual(STNode* lhs, STNode* rhs) : STNode(GREATERTHANOREQUAL) {
	AddChild(lhs);
	AddChild(rhs);
	lhs->setParent(this);
	rhs->setParent(this);
}

BITWISEAND::BITWISEAND(STNode* lhs, STNode* rhs) : STNode(BITAND) {
	AddChild(lhs);
	AddChild(rhs);
	lhs->setParent(this);
	rhs->setParent(this);
}

BITWISEOR::BITWISEOR(STNode* lhs, STNode* rhs) : STNode(BITOR) {
	AddChild(lhs);
	AddChild(rhs);
	lhs->setParent(this);
	rhs->setParent(this);
}

BITWISEXOR::BITWISEXOR(STNode* lhs, STNode* rhs) : STNode(BITXOR) {
	AddChild(lhs);
	AddChild(rhs);
	lhs->setParent(this);
	rhs->setParent(this);
}

ExpressionList::ExpressionList(STNode* addition) :STNode(EXPRESSIONLIST) {
	AddChild(addition);
	addition->setParent(this);
}

ExpressionList::ExpressionList(STNode* additionlist, STNode* addition) : STNode(EXPRESSIONLIST) {
	AddChild(additionlist);
	AddChild(addition);
	additionlist->setParent(this);
	addition->setParent(this);
}

UserDefinedFunctionCall::UserDefinedFunctionCall(STNode* identifier, STNode* args) :
	STNode(USERDEFINEDFUNCTIONCALL) {
	AddChild(identifier);
	AddChild(args);
	identifier->setParent(this);
	args->setParent(this);
}

BuiltInFunctionCall::BuiltInFunctionCall(STNode* id, STNode* args) :
	STNode(BUILTINFUNCTIONCALL) {
	AddChild(id);
	AddChild(args);
	id->setParent(this);
	args->setParent(this);
}

BITWISENOT::BITWISENOT(STNode* expr) : STNode(BITNOT) {
	AddChild(expr);
	expr->setParent(this);
}

LSHIFT::LSHIFT(STNode* lhs, STNode* rhs) : STNode(LSHFT) {
	AddChild(lhs);
	AddChild(rhs);
	lhs->setParent(this);
	rhs->setParent(this);

}

RSHIFT::RSHIFT(STNode* lhs, STNode* rhs) :STNode(RSHFT) {
	AddChild(lhs);
	AddChild(rhs);
	lhs->setParent(this);
	rhs->setParent(this);
}

ArgumentList::ArgumentList(STNode* identifier) : STNode(ARGUMENTLIST) {
	AddChild(identifier);
	identifier->setParent(this);
}
ArgumentList::ArgumentList(STNode* identifierList, STNode* identifier) :
	STNode(ARGUMENTLIST) {
	AddChild(identifierList);
	AddChild(identifier);
	identifierList->setParent(this);
	identifier->setParent(this);
}

FunctionDefinition::FunctionDefinition(STNode* typspec, STNode* identifier, STNode* paramList, STNode* expList) : STNode(FUNCTIONDEFINITION) {
	AddChild(typspec);
	AddChild(identifier);
	AddChild(paramList);
	AddChild(expList);
	typspec->setParent(this);
	identifier->setParent(this);
	paramList->setParent(this);
	expList->setParent(this);
}
FunctionDefinition::FunctionDefinition(STNode* typspec, STNode* identifier, STNode* expList) : STNode(FUNCTIONDEFINITION) {
	AddChild(typspec);
	AddChild(identifier);
	AddChild(expList);
	typspec->setParent(this);
	identifier->setParent(this);
	expList->setParent(this);
}


ParamList::ParamList(STNode* paramList, STNode* identifier) :
	STNode(PARAMLIST) {
	AddChild(paramList);
	AddChild(identifier);
	paramList->setParent(this);
	identifier->setParent(this);
}

ParamList::ParamList(STNode* identifier) :
	STNode(PARAMLIST) {
	AddChild(identifier);
	identifier->setParent(this);
}




void NUMBER::Accept(CVisitor* visitor) {
	visitor->VisitNumber(this);
}

void Addition::Accept(CVisitor* visitor) {
	visitor->VisitAddition(this);
}

void Assignment::Accept(CVisitor* visitor) {
	visitor->VisitAssignment(this);
}

void Subtraction::Accept(CVisitor* visitor) {
	visitor->VisitSubtraction(this);
}

void Multiplication::Accept(CVisitor* visitor) {
	visitor->VisitMultiplication(this);
}

void Division::Accept(CVisitor* visitor) {
	visitor->VisitDivision(this);
}

void Modulo::Accept(CVisitor* visitor) {
	visitor->VisitModulo(this);
}

void Exponentiation::Accept(CVisitor* visitor) {
	visitor->VisitExponentiation(this);
}

void FloorDivision::Accept(CVisitor* visitor) {
	visitor->VisitFloorDivision(this);
}

void UnaryMinus::Accept(CVisitor* visitor) {
	visitor->VisitUnaryMinus(this);
}

void UnaryPlus::Accept(CVisitor* visitor) {
	visitor->VisitUnaryPlus(this);
}

void LogicalAnd::Accept(CVisitor* visitor) {
	visitor->VisitLogicalAnd(this);
}

void LogicalOr::Accept(CVisitor* visitor) {
	visitor->VisitLogicalOr(this);
}

void LogicalNot::Accept(CVisitor* visitor) {
	visitor->VisitLogicalNot(this);
}

void Increment::Accept(CVisitor* visitor) {
	visitor->VisitIncrement(this);
}

void Decrement::Accept(CVisitor* visitor) {
	visitor->VisitDecrement(this);
}

void Equal::Accept(CVisitor* visitor) {
	visitor->VisitEqual(this);
}

void NotEqual::Accept(CVisitor* visitor) {
	visitor->VisitNotEqual(this);
}

void LessThan::Accept(CVisitor* visitor) {
	visitor->VisitLessThan(this);
}

void GreaterThan::Accept(CVisitor* visitor) {
	visitor->VisitGreaterThan(this);
}

void LessThanOrEqual::Accept(CVisitor* visitor) {
	visitor->VisitLessThanOrEqual(this);
}

void GreaterThanOrEqual::Accept(CVisitor* visitor) {
	visitor->VisitGreaterThanOrEqual(this);
}

void BITWISEAND::Accept(CVisitor* visitor) {
	visitor->VisitBitAnd(this);
}

void BITWISEOR::Accept(CVisitor* visitor) {
	visitor->VisitBitOr(this);
}

void BITWISEXOR::Accept(CVisitor* visitor) {
	visitor->VisitBitXor(this);
}

void ExpressionList::Accept(CVisitor* visitor) {
	visitor->VisitExpressionList(this);
}

void UserDefinedFunctionCall::Accept(CVisitor* visitor) {
	visitor->VisitUserDefinedFunctionCall(this);
}

void BuiltInFunctionCall::Accept(CVisitor* visitor) {
	visitor->VisitBuiltinFunctionCall(this);
}

void BITWISENOT::Accept(CVisitor* visitor) {
	visitor->VisitBitNot(this);
}

void LSHIFT::Accept(CVisitor* visitor) {
	visitor->VisitLeftShift(this);
}

void RSHIFT::Accept(CVisitor* visitor) {
	visitor->VisitRightShift(this);
}

void ArgumentList::Accept(CVisitor* visitor) {
	visitor->VisitArgumentList(this);
}

void FunctionDefinition::Accept(CVisitor* visitor) {
	visitor->VisitFunctionDefinition(this);
}

void ParamList::Accept(CVisitor* visitor) {
	visitor->VisitParameterList(this);
}

Statement::Statement(STNode* node)
	: STNode(STATEMENT) {
	AddChild(node);
	node->setParent(this);
}

void Statement::Accept(CVisitor* visitor) {
	visitor->VisitStatement(this);
}


ExpressionStatement::ExpressionStatement(STNode* expression)
	: STNode(EXPRESSIONSTATEMENT) {
	AddChild(expression);
	expression->setParent(this);
}

ExpressionStatement::ExpressionStatement()
	: STNode(EXPRESSIONSTATEMENT) {
}

void ExpressionStatement::Accept(CVisitor* visitor) {
	visitor->VisitExpressionStatement(this);
}

CompoundStatement::CompoundStatement(STNode* statements)
	: STNode(COMMPOUNDSTATEMENT) {
	AddChild(statements);
	statements->setParent(this);
}
CompoundStatement::CompoundStatement()
	: STNode(COMMPOUNDSTATEMENT) {
}


void CompoundStatement::Accept(CVisitor* visitor) {
	visitor->VisitCompoundStatement(this);
}

ForLoop::ForLoop(STNode* init, STNode* cond, STNode* iter, STNode* body)
	: STNode(FORLOOP) {
	AddChild(init);
	AddChild(cond);
	AddChild(iter);
	AddChild(body);
	init->setParent(this);
	cond->setParent(this);
	iter->setParent(this);
	body->setParent(this);
}

ForLoop::ForLoop(STNode* init, STNode* cond, STNode* body)
	: STNode(FORLOOP) {
	AddChild(init);
	AddChild(cond);
	AddChild(body);
	init->setParent(this);
	cond->setParent(this);
	body->setParent(this);
}

void ForLoop::Accept(CVisitor* visitor) {
	visitor->VisitForLoop(this);
}

WhileLoop::WhileLoop(STNode* cond, STNode* body)
	: STNode(WHILELOOP) {
	AddChild(cond);
	AddChild(body);
	cond->setParent(this);
	body->setParent(this);
}

void WhileLoop::Accept(CVisitor* visitor) {
	visitor->VisitWhileLoop(this);
}

DoWhileLoop::DoWhileLoop(STNode* body, STNode* cond)
	: STNode(DOWHILELOOP) {
	AddChild(body);
	AddChild(cond);
	body->setParent(this);
	cond->setParent(this);
}

void DoWhileLoop::Accept(CVisitor* visitor) {
	visitor->VisitDoWhileLoop(this);
}

IfStatement::IfStatement(STNode* cond, STNode* thenStmt, STNode* elseStmt)
	: STNode(IFSTATEMENT) {
	AddChild(cond);
	AddChild(thenStmt);
	AddChild(elseStmt);
	cond->setParent(this);
	thenStmt->setParent(this);
	elseStmt->setParent(this);
}

IfStatement::IfStatement(STNode* cond, STNode* thenStmt)
	: STNode(IFSTATEMENT) {
	AddChild(cond);
	AddChild(thenStmt);
	cond->setParent(this);
	thenStmt->setParent(this);
}

void IfStatement::Accept(CVisitor* visitor) {
	visitor->VisitIfStatement(this);
}

ReturnStatement::ReturnStatement(STNode* expression)
	: STNode(RETURNSTATEMENT) {
	AddChild(expression);
	expression->setParent(this);
}

ReturnStatement::ReturnStatement()
	: STNode(RETURNSTATEMENT) {
}

void ReturnStatement::Accept(CVisitor* visitor) {
	visitor->VisitReturnStatement(this);
}

BreakStatement::BreakStatement()
	: STNode(BREAKSTATEMENT) {
}

void BreakStatement::Accept(CVisitor* visitor) {
	visitor->VisitBreakStatement(this);
}

ContinueStatement::ContinueStatement()
	: STNode(CONTINUESTATEMENT) {
}

void ContinueStatement::Accept(CVisitor* visitor) {
	visitor->VisitContinueStatement(this);
}

Statements::Statements(STNode* statement) : STNode(STATEMENTS) {
	AddChild(statement);
	statement->setParent(this);
}
Statements::Statements(STNode* statementList, STNode* statement) : STNode(STATEMENTS) {
	AddChild(statementList);
	AddChild(statement);
	statementList->setParent(this);
	statement->setParent(this);
}
void Statements::Accept(CVisitor* visitor) {
	visitor->VisitStatements(this);
}

EmptyStatement::EmptyStatement() : STNode(EMPTYSTATEMENT) {
}
void EmptyStatement::Accept(CVisitor* visitor) {
	visitor->VisitEmptyStatement(this);
}

IfElseStatement::IfElseStatement(STNode* condition,
	STNode* thenBranch,
	STNode* elseBranch) : STNode(IFELSESTATEMENT) {
	AddChild(condition);
	AddChild(thenBranch);
	AddChild(elseBranch);
	condition->setParent(this);
	thenBranch->setParent(this);
	elseBranch->setParent(this);
}
void IfElseStatement::Accept(CVisitor* visitor) {
	visitor->VisitIfElseStatement(this);
}














