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
		"LSHIFT", "RSHIFT" , "ARGUMENTLIST", "FUNCTIONDEFINITION", "PARAMLIST" };
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

FunctionDefinition::FunctionDefinition(STNode* identifier, STNode* paramList, STNode* expList) :
	STNode(FUNCTIONDEFINITION) {
	AddChild(identifier);
	AddChild(paramList);
	AddChild(expList);
	identifier->setParent(this);
	paramList->setParent(this);
	expList->setParent(this);
}

FunctionDefinition::FunctionDefinition(STNode* identifier, STNode* expList) :
	STNode(FUNCTIONDEFINITION) {
	AddChild(identifier);
	AddChild(expList);
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



