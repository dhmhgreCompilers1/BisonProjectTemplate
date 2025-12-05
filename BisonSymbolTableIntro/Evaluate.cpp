#include "ConcreteNode.h"




int Evaluate(STNode* current, STNode* parent) {
	STNode* left;
	STNode* right;
	std::list<STNode*>::iterator it;
	int nchildren;
	int result;

	switch (current->GetNodeType()) {

	case nodetypeid::NUMBER_:
		return ((NUMBER*)current)->GetValue();
		break;
	case nodetypeid::ADDITION:
		it = current->m_children->begin();
		left = *it;
		it++;
		right = *it;
		return Evaluate(left, current) +
			   Evaluate(right, current);		
	case nodetypeid::EXPRESSIONLIST:
		nchildren = current->m_children->size();
		it = current->m_children->begin();
		if (nchildren == 1) {
			STNode* addition = *it;
			result = Evaluate(addition, current);
			cout << "Expression Result: " << result << endl;
			return 0;
		}
		else {
			STNode* additionList = *it;
			it++;
			STNode* addition = *it;
			Evaluate(additionList, current);
			result = Evaluate(addition, current);
			cout << "Expression Result: " << result << endl;
			
		}
	default:
		return 0;
		break;
	}
}


