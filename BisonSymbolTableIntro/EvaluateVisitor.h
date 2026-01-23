#pragma once

#include "Visitor.h"

class EvaluateVisitor : public CVisitor {
public:
	virtual void VisitNumber(NUMBER* num);
	virtual void VisitIdentifier(IDENTIFIER* id);
	virtual void VisitAddition(Addition* add);
	virtual void VisitAssignment(Assignment* assignment);
	virtual void VisitSubtraction(Subtraction* sub);
	virtual void VisitMultiplication(Multiplication* mul);
	virtual void VisitDivision(Division* div);
	virtual void VisitModulo(Modulo* mod);
	virtual void VisitExponentiation(Exponentiation* expon);
	virtual void VisitUnaryMinus(UnaryMinus* unMinus);
	virtual void VisitUnaryPlus(UnaryPlus* unPlus);
	virtual void VisitFloorDivision(FloorDivision* fdiv);
	virtual void VisitLogicalAnd(LogicalAnd* logicalAnd);
	virtual void VisitLogicalOr(LogicalOr* logicalOr);
	virtual void VisitLogicalNot(LogicalNot* logicalNot);
	virtual void VisitLessThan(LessThan* lessThan);
	virtual void VisitGreaterThan(GreaterThan* greaterThan);
	virtual void VisitLessThanOrEqual(LessThanOrEqual* lessThanOrEqual);
	virtual void VisitGreaterThanOrEqual(GreaterThanOrEqual* greaterThanOrEqual);
	virtual void VisitEqual(Equal* equalExpr);
	virtual void VisitNotEqual(NotEqual* notEqual);
	virtual void VisitIncrement(Increment* increment);
	virtual void VisitDecrement(Decrement* decrement);
	virtual void VisitUserDefinedFunctionCall(UserDefinedFunctionCall* userFuncCall);
	virtual void VisitBuiltinFunctionCall(BuiltInFunctionCall* builtinFuncCall);
	virtual void VisitBitAnd(BITWISEAND* bitAnd);
	virtual void VisitBitOr(BITWISEOR* bitOr);
	virtual void VisitBitXor(BITWISEXOR* bitXor);
	virtual void VisitBitNot(BITWISENOT* bitNot);
	virtual void VisitLeftShift(LSHIFT* lshift);
	virtual void VisitRightShift(RSHIFT* rshift);
	virtual void VisitArgumentList(ArgumentList* argList);
	virtual void VisitFunctionDefinition(FunctionDefinition* funcDef);
	virtual void VisitParameterList(ParamList* paramList);
	/*virtual void VisitCompilationUnit(CompilationUnit* compUnit);
	virtual void VisitStatement(Statement* statement);
	virtual void VisitStatements(Statements* stmts);*/
	virtual void VisitDeclaration(Declaration* decl);
	/*virtual void VisitDeclarations(Declarations* decls);*/
	virtual void VisitVariableDeclaration(VariableDeclaration* varDecl);
	virtual void VisitTypeSpecifier(TypeSpecifier* typeSpec);
	virtual void VisitDeclarators(Declarators* decls);
	virtual void VisitDirectDeclarator(DirectDeclarator* directDecl);
	virtual void VisitExpressionStatement(ExpressionStatement* exprStmt);
	virtual void VisitCompoundStatement(CompoundStatement* compStmt);
	virtual void VisitForLoop(ForLoop* forLoop);
	virtual void VisitWhileLoop(WhileLoop* whileLoop);
	virtual void VisitDoWhileLoop(DoWhileLoop* doWhileLoop);
	virtual void VisitIfStatement(IfStatement* ifStmt);
	virtual void VisitReturnStatement(ReturnStatement* returnStmt);
	virtual void VisitBreakStatement(BreakStatement* breakStmt);
	virtual void VisitContinueStatement(ContinueStatement* continueStmt);
	virtual void VisitEmptyStatement(EmptyStatement* emptyStmt);
	virtual void VisitIfElseStatement(IfElseStatement* ifElseStmt);

	void GetActualArguments(STNode* argsNode);
	void GetFormalArguments(STNode* arguments_root);

private:
	int m_result;
	list<string> m_formalParams;
	list<int> m_argValues;
};