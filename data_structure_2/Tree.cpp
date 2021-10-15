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
		return NULL;
	}
	std::list<Answer*>::iterator it;
	for (it = p->answersList.begin(); it != p->answersList.end(); ++it)
	{
		
		if (search((*it)->son, val, p) == NULL)
			continue;
		else
			return search((*it)->son, val, p);
		//if (tmp != NULL)
			//return tmp;

	}
	return NULL;
}

bool Tree::searchAndPrint(Node* p, string val)
{
	if (p->value == val)
	{
		return p;
	}
	if (p->isLeaf)
	{
		return NULL;
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

void Tree::deleteAllSubTree(Node* t)
{
	if (t == nullptr)
		return;
	if (t->isLeaf)
		return;
	std::list<Answer*>::iterator it;
	for (it = t->answersList.begin(); it != t->answersList.end(); ++it)
	{
		deleteAllSubTree((*it)->son);
		delete *it;
	}
	t->answersList.clear();
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
	 Node* location = search(this->root, fatherquestion, this->root);
	if (location == NULL)
	{
		return false;
	}
	location->isLeaf = false;
	Node* user_input=new Node(newval);
	Answer* next_statment =new Answer(newanswer, user_input);
	location->answersList.push_back(next_statment);
	return true;
	/*if (location->answersList.empty())
	{
		location->answersList.push_front(next_statment);
		return true;
	}*/
	

}

string Tree::printToString(Node* p)
{
	return p->value;
}

void Tree::deleteSubTree(string val)
{
	Node* father_pointer = this->root;
	Node* pointer;
	pointer = search(this->root, val, father_pointer);
	father_pointer->isLeaf = true;
	deleteAllSubTree(pointer);
	//father_pointer->answersList.clear(); ?
}