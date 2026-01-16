#pragma once
#include "STNode.h"
#include <string>
using namespace std;

typedef enum nodetypeid {
	NA = 0, NUMBER_ = 1, IDENTIFIER_, ADDITION, EXPRESSIONLIST, ASSIGNMENT,
	SUBTRACTION, MULTIPLICATION, DIVISION, MODULUS, EXPONENTIATION, UNARYMINUS
	, UNARYPLUS, FLOORDIVISION, LOGICALAND, LOGICALOR, LOGICALNOT, LESSTHAN, GREATERTHAN,
	LESSTHANOREQUAL, GREATERTHANOREQUAL, EQUAL, NOTEQUAL, INCREMENT, DECREMENT, USERDEFINEDFUNCTIONCALL,
	BUILTINFUNCTIONCALL,
	BITAND, BITOR, BITXOR, BITNOT,
	LSHFT, RSHFT, ARGUMENTLIST, FUNCTIONDEFINITION, PARAMLIST,
	STATEMENT, STATEMENTS, COMPILATION_UNIT, DECLARATION, VARIABLEDECLARATION,
	TYPESPECIFIER, DECLARATORS, DIRECTDECLARATOR, ARRAYDIRECTDECLARATOR, EXPRESSIONSTATEMENT,
	COMMPOUNDSTATEMENT, FORLOOP, WHILELOOP, DOWHILELOOP, IFSTATEMENT,
	RETURNSTATEMENT, BREAKSTATEMENT, CONTINUESTATEMENT, DECLARATIONS, EMPTYSTATEMENT,
	IFELSESTATEMENT
}NODETYPE;

class NUMBER : public STNode {
public:

	NUMBER(char* text);
	~NUMBER();

	string GetNumberText();
	int GetValue();

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;

private:
	string m_number;
	int m_value;

};

class IDENTIFIER : public STNode {
public:
	IDENTIFIER(char* text);
	~IDENTIFIER();
	string GetIdentifierText();
	int SetValue(int v);
	int GetValue();

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
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
	void Accept(CVisitor* visitor) override;
};

class Subtraction : public STNode {
public:
	Subtraction(STNode* number);
	Subtraction(STNode* addition, STNode* number);
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class Multiplication : public STNode {
public:
	Multiplication(STNode* number);
	Multiplication(STNode* addition, STNode* number);
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class Assignment : public STNode {
public:
	Assignment(STNode* identifier, STNode* addition);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class ExpressionList : public STNode {
public:
	ExpressionList(STNode* addition);
	ExpressionList(STNode* additionList, STNode* addition);
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class Division : public STNode {
public:
	Division(STNode* number);
	Division(STNode* division, STNode* number);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class Modulo : public STNode {
public:
	Modulo(STNode* number);
	Modulo(STNode* modulus, STNode* number);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class Exponentiation : public STNode {
public:
	Exponentiation(STNode* number);
	Exponentiation(STNode* base, STNode* exponent);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class UnaryMinus : public STNode {
public:
	UnaryMinus(STNode* expression);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class UnaryPlus : public STNode {
public:
	UnaryPlus(STNode* expression);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class FloorDivision : public STNode {
public:
	FloorDivision(STNode* number);
	FloorDivision(STNode* floordiv, STNode* number);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class LogicalAnd : public STNode {
public:
	LogicalAnd(STNode* lhs, STNode* rhs);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class LogicalOr : public STNode {
public:
	LogicalOr(STNode* lhs, STNode* rhs);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class LogicalNot : public STNode {
public:
	LogicalNot(STNode* expr);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class LessThan : public STNode {
public:
	LessThan(STNode* lhs, STNode* rhs);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class GreaterThan : public STNode {
public:
	GreaterThan(STNode* lhs, STNode* rhs);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class LessThanOrEqual : public STNode {
public:
	LessThanOrEqual(STNode* lhs, STNode* rhs);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class GreaterThanOrEqual : public STNode {
public:
	GreaterThanOrEqual(STNode* lhs, STNode* rhs);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class Equal : public STNode {
public:
	Equal(STNode* lhs, STNode* rhs);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class NotEqual : public STNode {
public:
	NotEqual(STNode* lhs, STNode* rhs);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class Increment : public STNode {
public:
	Increment(STNode* identifier);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class Decrement : public STNode {
public:
	Decrement(STNode* identifier);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class UserDefinedFunctionCall : public STNode {
public:
	UserDefinedFunctionCall(STNode* identifier, STNode* args);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class BuiltInFunctionCall : public STNode {
public:
	BuiltInFunctionCall(STNode* identifier, STNode* args);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class BITWISEAND : public STNode {
public:
	BITWISEAND(STNode* lhs, STNode* rhs);
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class BITWISEOR : public STNode {
public:
	BITWISEOR(STNode* lhs, STNode* rhs);
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class BITWISEXOR : public STNode {
public:
	BITWISEXOR(STNode* lhs, STNode* rhs);
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class BITWISENOT : public STNode {
public:
	BITWISENOT(STNode* expr);
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class LSHIFT : public STNode {
public:
	LSHIFT(STNode* lhs, STNode* rhs);
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class RSHIFT : public STNode {
public:
	RSHIFT(STNode* lhs, STNode* rhs);
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class ArgumentList : public STNode {
public:
	ArgumentList(STNode* identifier);
	ArgumentList(STNode* identifierList, STNode* identifier);
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class FunctionDefinition : public STNode {
public:
	FunctionDefinition(STNode* typspec, STNode* identifier, STNode* paramList, STNode* expList);
	FunctionDefinition(STNode* typspec, STNode* identifier, STNode* expList);
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class ParamList : public STNode {
public:
	ParamList(STNode* paramList, STNode* identifier);
	ParamList(STNode* identifier);
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

// Represents a single statement (e.g., assignment, expression, function definition)
class Statement : public STNode {
public:
	// A statement directly wrapping an expression/assignment/etc.
	Statement(STNode* node);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

// Represents a sequence of statements
class Statements : public STNode {
public:
	// Single statement
	Statements(STNode* statement);
	// statementList statement
	Statements(STNode* statementList, STNode* statement);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

// Represents the top-level program (root of the AST)
class CompilationUnit : public STNode {
public:
	// Typically wraps a StatementList or ExpressionList according to grammar.y
	CompilationUnit(STNode* c1);
	CompilationUnit(STNode* c1, STNode* c2);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class Declaration : public STNode {
public:
	Declaration(STNode* node);
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class Declarations : public STNode {
public:
	Declarations(STNode* declaration);
	Declarations(STNode* declarations, STNode* declaration);
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class VariableDeclaration : public STNode {
public:
	VariableDeclaration(STNode* typeSpecifier, STNode* declarators);
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class TypeSpecifier : public STNode {
public:
	TypeSpecifier(string type);
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class Declarators : public STNode {
public:
	Declarators(STNode* node);
	Declarators(STNode* declarators, STNode* directDeclarator);
	Declarators(STNode* declarators, STNode* directDeclarator, STNode *expression);

public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class DirectDeclarator : public STNode {
public:
	DirectDeclarator(string identifier);
	DirectDeclarator(STNode* directDeclarator);
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class ArrayDirectDeclarator : public STNode {
public:
	ArrayDirectDeclarator(string identifier);
	ArrayDirectDeclarator(STNode* directDeclarator);
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class ExpressionStatement : public STNode {
public:
	ExpressionStatement(STNode* expression);
	ExpressionStatement(); // For empty statement
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class CompoundStatement : public STNode {
public:
	CompoundStatement(STNode* statementList);
	CompoundStatement();
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class ForLoop : public STNode {
public:
	ForLoop(STNode* init, STNode* condition, STNode* increment, STNode* body);
	ForLoop(STNode* init, STNode* condition, STNode* body);
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class WhileLoop : public STNode {
public:
	WhileLoop(STNode* condition, STNode* body);
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class DoWhileLoop : public STNode {
public:
	DoWhileLoop(STNode* body, STNode* condition);
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class IfStatement : public STNode {
public:
	IfStatement(STNode* condition, STNode* thenBranch, STNode* elseBranch);
	IfStatement(STNode* condition, STNode* thenBranch);
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class IfElseStatement : public STNode {
public:
	IfElseStatement(STNode* condition, STNode* thenBranch, STNode* elseBranch);
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class ReturnStatement : public STNode {
public:
	ReturnStatement(STNode* expression);
	ReturnStatement();
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};


class BreakStatement : public STNode {
public:
	BreakStatement();
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class ContinueStatement : public STNode {
public:
	ContinueStatement();
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};

class EmptyStatement : public STNode {
public:
	EmptyStatement();
public:
	int Evaluate() override;
	void Accept(CVisitor* visitor) override;
};
