#pragma once
#include "Visitor.h"

class CScopeSystemVisitor : public CVisitor {
	public:
	void VisitIdentifier(IDENTIFIER* id) override;
	void VisitExpressionList(ExpressionList* exprList) override;
	/*void VisitFunctionDefinition(FunctionDefinition* funcDef) override;
	void VisitParameterList(ParamList* paramList) override;
	void VisitArgumentList(ArgumentList* argList) override;*/
};
