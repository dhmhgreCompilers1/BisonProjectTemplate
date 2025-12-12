#pragma once
#include "STNode.h"
#include <string>
using namespace std;

typedef enum nodetypeid {
	NA = 0, NUMBER_ = 1, IDENTIFIER_, ADDITION, EXPRESSIONLIST, ASSIGNMENT,
	SUBTRACTION, MULTIPLICATION, DIVISION, MODULUS, EXPONENTIATION, UNARYMINUS
	, UNARYPLUS, FLOORDIVISION, LOGICALAND, LOGICALOR, LOGICALNOT, LESSTHAN, GREATERTHAN,
	LESSTHANOREQUAL, GREATERTHANOREQUAL, EQUAL, NOTEQUAL, INCREMENT, DECREMENT, FUNCTIONCALL,
	BITAND, BITOR, BITXOR,BITNOT,
	LSHFT, RSHFT, ARGUMENTLIST
	

}NODETYPE;

class NUMBER : public STNode {
public:

	NUMBER(char* text);
	~NUMBER();

	string GetNumberText();
	int GetValue();

public:
	int Evaluate() override;

private:
	string m_number;
	int m_value;

};
class IDENTIFIER : public STNode {
public:
	IDENTIFIER(char* text);
	~IDENTIFIER();
	string GetIdentifierText();
	void SetValue(int v);
	int GetValue();

public:
	int Evaluate() override;
private:
	string m_identifier;
	int m_value;
};

class Addition : public STNode {
public:
	Addition(STNode* number);
	Addition(STNode* addition, STNode* number);

public:
	int Evaluate() override;
};

class Subtraction : public STNode {
public:
	Subtraction(STNode* number);
	Subtraction(STNode* addition, STNode* number);
public:
	int Evaluate() override;
};

class Multiplication : public STNode {
public:
	Multiplication(STNode* number);
	Multiplication(STNode* addition, STNode* number);
public:
	int Evaluate() override;
};



class Assignment : public STNode {
public:
	Assignment(STNode* identifier, STNode* addition);

public:
	int Evaluate() override;
};

class ExpressionList : public STNode {
public:
	ExpressionList(STNode* addition);
	ExpressionList(STNode* additionList, STNode* addition);
public:
	int Evaluate() override;
};
class Division : public STNode {
public:
	Division(STNode* number);
	Division(STNode* division, STNode* number);

public:
	int Evaluate() override;
};

class Modulo : public STNode {
public:
	Modulo(STNode* number);
	Modulo(STNode* modulus, STNode* number);

public:
	int Evaluate() override;
};

class Exponentiation : public STNode {
public:
	Exponentiation(STNode* number);
	Exponentiation(STNode* base, STNode* exponent);

public:
	int Evaluate() override;
};

class UnaryMinus : public STNode {
public:
	UnaryMinus(STNode* expression);

public:
	int Evaluate() override;
};

class UnaryPlus : public STNode {
public:
	UnaryPlus(STNode* expression);

public:
	int Evaluate() override;
};

class FloorDivision : public STNode {
public:
	FloorDivision(STNode* number);
	FloorDivision(STNode* floordiv, STNode* number);

public:
	int Evaluate() override;
};

class LogicalAnd : public STNode {
public:
	LogicalAnd(STNode* lhs, STNode* rhs);

public:
	int Evaluate() override;
};

class LogicalOr : public STNode {
public:
	LogicalOr(STNode* lhs, STNode* rhs);

public:
	int Evaluate() override;
};

class LogicalNot : public STNode {
public:
	LogicalNot(STNode* expr);

public:
	int Evaluate() override;
};

class LessThan : public STNode {
public:
	LessThan(STNode* lhs, STNode* rhs);

public:
	int Evaluate() override;
};

class GreaterThan : public STNode {
public:
	GreaterThan(STNode* lhs, STNode* rhs);

public:
	int Evaluate() override;
};

class LessThanOrEqual : public STNode {
public:
	LessThanOrEqual(STNode* lhs, STNode* rhs);

public:
	int Evaluate() override;
};

class GreaterThanOrEqual : public STNode {
public:
	GreaterThanOrEqual(STNode* lhs, STNode* rhs);

public:
	int Evaluate() override;
};

class Equal : public STNode {
public:
	Equal(STNode* lhs, STNode* rhs);

public:
	int Evaluate() override;
};

class NotEqual : public STNode {
public:
	NotEqual(STNode* lhs, STNode* rhs);

public:
	int Evaluate() override;
};

class Increment : public STNode {
public:
	Increment(STNode* identifier);

public:
	int Evaluate() override;
};

class Decrement : public STNode {
public:
	Decrement(STNode* identifier);

public:
	int Evaluate() override;
};

class FunctionCall : public STNode {
public:
	FunctionCall(STNode* identifier, STNode* args);

public:
	int Evaluate() override;
};

class BITWISEAND : public STNode {
public:
	BITWISEAND(STNode* lhs, STNode* rhs);
public:
	int Evaluate() override;
};
class BITWISEOR : public STNode {
public:
	BITWISEOR(STNode* lhs, STNode* rhs);
public:
	int Evaluate() override;
};
class BITWISEXOR : public STNode {
public:
	BITWISEXOR(STNode* lhs, STNode* rhs);
public:
	int Evaluate() override;
};

class BITWISENOT : public STNode {
	public:
		BITWISENOT(STNode* expr);
public:
	int Evaluate() override;
};
class LSHIFT : public STNode {
	public:
		LSHIFT(STNode* lhs, STNode* rhs);
public:	
	int Evaluate() override;
};
class RSHIFT : public STNode {
	public:
		RSHIFT(STNode* lhs, STNode* rhs);
public:
	int Evaluate() override;
};

class ArgumentList : public STNode {
	public:
	ArgumentList(STNode* identifier);
	ArgumentList(STNode* identifierList, STNode* identifier);
public:
	int Evaluate() override;
};

