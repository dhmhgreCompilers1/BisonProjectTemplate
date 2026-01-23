#pragma once
#include "Visitor.h"

class CScopeSystemVisitor : public CVisitor {
	public:
	void VisitIdentifier(IDENTIFIER* id) override;
	void VisitFunctionDefinition(FunctionDefinition* funcDef) override;
	void VisitParameterList(ParamList* paramList) override;
	void VisitAssignment(Assignment* assignment) override;
	void VisitBuiltinFunctionCall(BuiltInFunctionCall* builtinFuncCall) override;
	void VisitUserDefinedFunctionCall(UserDefinedFunctionCall* userFuncCall) override;
	void VisitCompilationUnit(CompilationUnit* compUnit) override;
	/*
	void VisitArgumentList(ArgumentList* argList) override;*/
};
