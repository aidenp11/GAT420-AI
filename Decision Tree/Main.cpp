#include "Node.h"

void traverse(node_t* node)
{
	node_t* nextNode = node->execute();
	if (nextNode != nullptr)
	{
		traverse(nextNode);
	}
}

int main()
{
	float numBraincells = 12;
	bool likesSchool = true;
	float daysOfSchoolAttendedAWeek = 6;
	bool isIrish = true;

	node_t* lobotomyAction = new action_t("lobotomy");
	node_t* celebrateAction = new action_t("celebrate");
	node_t* moreSchoolAction = new action_t("more schooling");
	node_t* expellAction = new action_t("expelled");

	node_t* root = new decision_t<float>("number of braincells", numBraincells, ePredicate::Less, 15);
	node_t* likesSchoolDecision = new decision_t<bool>("likes school", likesSchool, ePredicate::Equal, true);
	node_t* expellDecision = new decision_t<float>("getting expelled", daysOfSchoolAttendedAWeek, ePredicate::Less, 4);
	node_t* irishDecision = new decision_t<bool>("is irish", isIrish, ePredicate::Equal, true);

	root->trueNode = likesSchoolDecision;
	root->falseNode = celebrateAction;

	likesSchoolDecision->trueNode = expellDecision;
	likesSchoolDecision->falseNode = lobotomyAction;

	expellDecision->trueNode = expellAction;
	expellDecision->falseNode = irishDecision;

	irishDecision->trueNode = lobotomyAction;
	irishDecision->falseNode = moreSchoolAction;

	traverse(root);

	// traverse root using recursion
}
