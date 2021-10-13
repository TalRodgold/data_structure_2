#include "Tree.h"

void Node::removeSonValue(string v)
{

}



Node* Tree::search(Node* p, string val, Node*& parent)
{
	if (p->value == val)
	{
		return p;
	}
	if (p->isLeaf)
	{
		return;
	}
	std::list<Answer*>::iterator it;
	for (it = p->answersList.begin(); it != p->answersList.end(); ++it)
	{
		Node* tmp = search((*it)->son, val, p);
		//if (tmp != NULL)
			//return tmp;

	}
}

bool Tree::searchAndPrint(Node* p, string val)
{
	if (p->value == val)
	{
		return p;
	}
	if (p->isLeaf)
	{
		return;
	}
	std::list<Answer*>::iterator it;
	for (it = p->answersList.begin(); it != p->answersList.end(); ++it)
	{
		searchAndPrint((*it)->son, val);	
	}
	cout << p->value << "=>";
}

void Tree::print(Node* p, int level)
{
}

void Tree::process(Node* p)
{
	if (p->isLeaf)
	{
		cout << p->value << endl;
	}
	cout << p->value << endl;
	string user_answer;
	cin >> user_answer;
	std::list<Answer*>::iterator it;
	for (it = p->answersList.begin(); it != p->answersList.end(); ++it)
	{
		if (user_answer == (*it)->ans)
		{
			process((*it)->son);
		}
	}
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

void Tree::deleteSubTree(string val)
{
	Node* father_pointer = this->root;
	Node* pointer;
	pointer = search(this->root, val, father_pointer);
	father_pointer->isLeaf = true;
	delete_(father_pointer);
	//father_pointer->answersList.clear();
}

void Tree::delete_(Node* p)
{
	if (p->isLeaf)
		return;
	auto it = p->answersList.begin();
	for (;it != (*p).answersList.end();it++)
	{
		delete((*it)->son);
	}
	p->answersList.clear();
}
