#include "Tree.h"

void Node::removeSonValue(string v)
{

}



Node* Tree::search(Node* p, string val)
{
	Node* node_pointer = p;
	Answer* pointer = p->answersList.front();
	std::list<Answer*>::iterator it;
	for (it = p->answersList.begin(); it != p->answersList.end(); ++it)
	{
		while (!node_pointer->isLeaf)
		{
			if (node_pointer->value == val)
			{
				return node_pointer;
			}
			node_pointer = (*it)->son;
		}
	}
	return nullptr;
}

void Tree::addRoot(string newval) // add new root
{
	if (root != NULL) // if root not new
	{
		throw "ERROR: tree already exists";
	}
	this->root = new Node(newval);
}

bool Tree::addSon(string fatherquestion, string newanswer, string newval)
{
	Node* location = search(this->root, fatherquestion);
	if(location == NULL)
	{
		return false;
	}
	location->isLeaf = false;
	Node* son_val = new Node(newval);
	Answer next_statment(newanswer, son_val);
	Answer* pointer = location->answersList.back();
	location->answersList.emplace_back(newanswer, son_val);
}
