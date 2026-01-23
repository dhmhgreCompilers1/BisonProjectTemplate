#pragma once
#include "ConcreteNode.h"
class CVisitor {
public:
	virtual void VisitChildren(STNode* node) {
		for (auto child : *(node->m_children)) {
			child->Accept(this);
		}
	}

	virtual void Visit(STNode* node) {
		node->Accept(this);
	}

	virtual void VisitNumber(NUMBER* num) {}
	virtual void VisitIdentifier(IDENTIFIER* id) {}
	virtual void VisitAddition(Addition* add) { VisitChildren(add); }
	virtual void VisitAssignment(Assignment* assignment) { VisitChildren(assignment); }
	virtual void VisitSubtraction(Subtraction* sub) { VisitChildren(sub); }
	virtual void VisitMultiplication(Multiplication* mul) { VisitChildren(mul); }
	virtual void VisitDivision(Division* div) { VisitChildren(div); }
	virtual void VisitModulo(Modulo* mod) { VisitChildren(mod); }
	virtual void VisitExponentiation(Exponentiation* expon) { VisitChildren(expon); }
	virtual void VisitUnaryMinus(UnaryMinus* unMinus) { VisitChildren(unMinus); }
	virtual void VisitUnaryPlus(UnaryPlus* unPlus) { VisitChildren(unPlus); }
	virtual void VisitFloorDivision(FloorDivision* fdiv) { VisitChildren(fdiv); }
	virtual void VisitLogicalAnd(LogicalAnd* logicalAnd) { VisitChildren(logicalAnd); }
	virtual void VisitLogicalOr(LogicalOr* logicalOr) { VisitChildren(logicalOr); }
	virtual void VisitLogicalNot(LogicalNot* logicalNot) { VisitChildren(logicalNot); }
	virtual void VisitLessThan(LessThan* lessThan) { VisitChildren(lessThan); }
	virtual void VisitGreaterThan(GreaterThan* greaterThan) { VisitChildren(greaterThan); }
	virtual void VisitLessThanOrEqual(LessThanOrEqual* lessThanOrEqual) { VisitChildren(lessThanOrEqual); }
	virtual void VisitGreaterThanOrEqual(GreaterThanOrEqual* greaterThanOrEqual) { VisitChildren(greaterThanOrEqual); }
	virtual void VisitEqual(Equal* equalExpr) { VisitChildren(equalExpr); }
	virtual void VisitNotEqual(NotEqual* notEqual) { VisitChildren(notEqual); }
	virtual void VisitIncrement(Increment* increment) { VisitChildren(increment); }
	virtual void VisitDecrement(Decrement* decrement) { VisitChildren(decrement); }
	virtual void VisitUserDefinedFunctionCall(UserDefinedFunctionCall* userFuncCall) { VisitChildren(userFuncCall); }
	virtual void VisitBuiltinFunctionCall(BuiltInFunctionCall* builtinFuncCall) { VisitChildren(builtinFuncCall); }
	virtual void VisitBitAnd(BITWISEAND* bitAnd) { VisitChildren(bitAnd); }
	virtual void VisitBitOr(BITWISEOR* bitOr) { VisitChildren(bitOr); }
	virtual void VisitBitXor(BITWISEXOR* bitXor) { VisitChildren(bitXor); }
	virtual void VisitBitNot(BITWISENOT* bitNot) { VisitChildren(bitNot); }
	virtual void VisitLeftShift(LSHIFT* lshift) { VisitChildren(lshift); }
	virtual void VisitRightShift(RSHIFT* rshift) { VisitChildren(rshift); }
	virtual void VisitArgumentList(ArgumentList* argList) { VisitChildren(argList); }
	virtual void VisitFunctionDefinition(FunctionDefinition* funcDef) { VisitChildren(funcDef); }
	virtual void VisitParameterList(ParamList* paramList) { VisitChildren(paramList); }
	virtual void VisitCompilationUnit(CompilationUnit* compUnit) { VisitChildren(compUnit); }
	virtual void VisitStatement(Statement* statement) { VisitChildren(statement); }
	virtual void VisitStatements(Statements* stmts) { VisitChildren(stmts); }
	virtual void VisitDeclaration(Declaration* decl) { VisitChildren(decl); }
	virtual void VisitDeclarations(Declarations* decls) { VisitChildren(decls); }
	virtual void VisitVariableDeclaration(VariableDeclaration* varDecl) { VisitChildren(varDecl); }
	virtual void VisitTypeSpecifier(TypeSpecifier* typeSpec) { VisitChildren(typeSpec); }
	virtual void VisitDeclarators(Declarators* decls) { VisitChildren(decls); }
	virtual void VisitDirectDeclarator(DirectDeclarator* directDecl) { VisitChildren(directDecl); }
	virtual void VisitExpressionStatement(ExpressionStatement* exprStmt) { VisitChildren(exprStmt); }
	virtual void VisitCompoundStatement(CompoundStatement* compStmt) { VisitChildren(compStmt); }
	virtual void VisitForLoop(ForLoop* forLoop) { VisitChildren(forLoop); }
	virtual void VisitWhileLoop(WhileLoop* whileLoop) { VisitChildren(whileLoop); }
	virtual void VisitDoWhileLoop(DoWhileLoop* doWhileLoop) { VisitChildren(doWhileLoop); }
	virtual void VisitIfStatement(IfStatement* ifStmt) { VisitChildren(ifStmt); }
	virtual void VisitReturnStatement(ReturnStatement* returnStmt) { VisitChildren(returnStmt); }
	virtual void VisitBreakStatement(BreakStatement* breakStmt) { VisitChildren(breakStmt); }
	virtual void VisitContinueStatement(ContinueStatement* continueStmt) { VisitChildren(continueStmt); }
	virtual void VisitEmptyStatement(EmptyStatement* emptyStmt) { VisitChildren(emptyStmt); }
	virtual void VisitIfElseStatement(IfElseStatement* ifElseStmt) { VisitChildren(ifElseStmt); }

};





