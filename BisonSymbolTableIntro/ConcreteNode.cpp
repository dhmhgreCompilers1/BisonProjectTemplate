#include "ConcreteNode.h"

string g_nodetypesstr[] = { "NA","NUMBER","IDENTIFIER",
	"ADDITION", "EXPRESSIONLIST" ,"ASSIGNMENT",

	"SUBTRACTION", "MULTIPLICATION", "DIVISION", "MODULUS", "EXPONENTIATION",
	"UNARYMINUS","UNARYPLUS", "FLOORDIVISION", "LOGICALAND", "LOGICALOR",
	"LOGICALNOT", "LESSTHAN", "GREATERTHAN","LESSTHANOREQUAL", "GREATERTHANOREQUAL",
	"EQUAL", "NOTEQUAL", "INCREMENT", "DECREMENT", "FUNCTIONCALL"
	   "BITWISEAND","BITWISEOR","BITWISEXOR", "BITWISENOT",
		"LSHIFT", "RSHIFT" , "ARGUMENTLIST"};
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

void IDENTIFIER::SetValue(int v) {
	m_value = v;
}

int IDENTIFIER::GetValue() {
	return m_value;
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

FunctionCall::FunctionCall(STNode* identifier, STNode* args) :
	STNode(FUNCTIONCALL) {
	AddChild(identifier);
	AddChild(args);
	identifier->setParent(this);
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

RSHIFT::RSHIFT(STNode* lhs, STNode* rhs):STNode(RSHFT){
	AddChild(lhs);
	AddChild(rhs);
	lhs->setParent(this);
	rhs->setParent(this);
}

ArgumentList::ArgumentList(STNode* identifier): STNode(ARGUMENTLIST)  {
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


