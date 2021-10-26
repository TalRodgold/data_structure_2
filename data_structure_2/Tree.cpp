// NAME:  Tal Rodgold  & Avichay Kadosh
// ID:    318162344    & 313317364
// GROUP: Haim Prianti & Efi Naftali
// PROJECT NUMBER: 1
#include "Tree.h"

void Node::removeSonValue(string v) // change value
{
	this->value = v;
	return;
}

Node* Tree::search(Node* p, string val, Node*& parent) // search value in tree
{
	if (p->value == val) // if val is found
	{
		parent = p;//
		return p; // return node
	}
	if (p->isLeaf) // if leaf
	{
		return NULL; // return null
	}
	std::list<Answer*>::iterator it; // creat ittartor
	for (it = p->answersList.begin(); it != p->answersList.end(); ++it) // for every node in list
	{
		
		if (search((*it)->son, val, p) == NULL) // if null
			continue;
		else // recursion
			return search((*it)->son, val, p);
	}
	return NULL;
}

bool Tree::searchAndPrint(Node* p, string val) // find val and print
{
	if (p->value == val) // if val is found
	{ 
		return p; // return node
	}
	if (p->isLeaf) // if leaf
	{
		return NULL; // return null
	}
	
	std::list<Answer*>::iterator it; // creat ittartor
	for (it = p->answersList.begin(); it != p->answersList.end(); ++it) // for every node in list
	{
		searchAndPrint((*it)->son, val); // recursion
	}
	cout << "=>" << p->value; // print
	
}

void Tree::print(Node* p) // print
{
	
	std::list<Answer*>::iterator it; // creat ittartor
	for (it = p->answersList.begin(); it != p->answersList.end(); ++it) // for every node in list
	{ 
		if (p->isLeaf) // if leaf
		{
			continue;
		}
		cout <<":" << (*it)->ans << endl << " " << (*it)->son->value << endl; // print
		print((*it)->son); // recursion
	}
	return; // end
}


void Tree::process(Node* p) // process of tree
{
	
	cout << p->value << endl;
	if (p->isLeaf) // if leaf
	{
		return; // end
	}
	string user_answer; // users answer
	cin >> user_answer; // read user input
	std::list<Answer*>::iterator it; // creat ittartor
	for (it = p->answersList.begin(); it != p->answersList.end(); ++it) // for every node in list
	{
		if (user_answer == (*it)->ans) // if user input matches
		{
			process((*it)->son); // recursion
		}
	}
	
}

void Tree::deleteAllSubTree(Node* t) // delete
{
	if (t == nullptr) // if node is null
		return;
	if (t->isLeaf) // if leaf
		return;
	std::list<Answer*>::iterator it;// creat ittartor
	for (it = t->answersList.begin(); it != t->answersList.end(); ++it)// for every node in list
	{
		deleteAllSubTree((*it)->son); // recursion
		delete *it; // delete
	}
	t->answersList.clear(); // clear list
}

void Tree::addRoot(string newval) // add new root
{
	if (root != NULL) // if root not new
	{
		throw "ERROR: tree already exists";
	}
	this->root = new Node(newval); // creat new root
}

bool Tree::addSon(string fatherquestion, string newanswer, string newval) // add a new son to tree
{
	 Node* location = search(this->root, fatherquestion, this->root); // find location to add
	if (location == NULL) // if location doesnt exisist
	{
		return false;
	}
	location->isLeaf = false; // change to not leaf
	Node* user_input=new Node(newval); // creat new node with new val
	Answer* next_statment =new Answer(newanswer, user_input); // creat new answear
	location->answersList.push_back(next_statment); // add to tree
	return true;
}

string Tree::printToString(Node* p) // print
{
	return p->value;
}

void Tree::deleteSubTree(string val) // delete
{
	Node* father_pointer = this->root; // creat pointer to father
	Node* pointer; // creat pointer
	pointer = search(this->root, val, father_pointer); // find val
	father_pointer->isLeaf = true; // make father a leaf
	deleteAllSubTree(pointer); // delete sub tree
}