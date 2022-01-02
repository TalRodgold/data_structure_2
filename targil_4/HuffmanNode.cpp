// NAME:  Tal Rodgold  & Avichay Kadosh
// ID:    318162344    & 313317364
// GROUP: Haim Prianti & Efi Naftali
// PROJECT NUMBER: 4
#include "HuffmanNode.h"
#include <list>
#include <queue>
#include <algorithm>
#include <stack>
HuffmanNode* HuffmanNode::build_huffman(string str, HuffmanNode* r) // build huffman tree
{
	int* table = new int[26]{ 0 }; // creat table for alphabet
	table = creat_frequency_table(str, table); // creat requency table
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, compareNode> pQueue; // priority queue
	int counter = 26; // counter for 26 letters
	HuffmanNode* temp; // temp node
	for (int i = 0; i < 26; i++) // for every letter
	{
		if (table[i] != 0) // if letter exsists
		{
			temp = new HuffmanNode((char)(i+97), table[i], NULL, NULL); // creat node
			pQueue.push(temp); // add to queue
		}
		else
		{
			counter--;
		}
	}
	for (int i = 0; i < counter-1; i++) // build tree
	{
		temp = new HuffmanNode(); 
		temp->left = pQueue.top(); 
		pQueue.pop();
		temp->right = pQueue.top();
		pQueue.pop();
		temp->frequency = temp->left->frequency + temp->right->frequency;
		pQueue.push(temp);
	}
	r = pQueue.top(); // return root
	return r;
}

HuffmanNode* HuffmanNode::rebuild_huffman(HuffmanNode* r, int num_of_leafs, string letters, string structer)// get decoded data to rebulid the huffman tree
{
	HuffmanNode* h = r; // save root
	int indexer = 0;
	int counter = 0;
	stack<HuffmanNode*> father_root; // stack to keep father nodes
	father_root.push(r);
	r->right = new HuffmanNode(); // build min tree
	r->left = new HuffmanNode(); // build min tree
	r = r->left; // root = root right
	for (int i = 0; i < num_of_leafs; i++)
	{
		while (structer[indexer] != '1') // if 0
		{
			r->right = new HuffmanNode(); // build right node
			r->left = new HuffmanNode(); // build left node
			father_root.push(r); // push father root
			r = r->left; // root = root left
			indexer++;
		}
		// if 1
		r->ch = letters[counter++]; // input letter	
		r = father_root.top(); // r = father 
		r = r->right; // go right
		father_root.pop(); // pop
		indexer++;
	}
	h->right = h->left->right;
	h->left = h->left->left;
	return h;
}

int* HuffmanNode::creat_frequency_table(string str, int* t) // creat frequency table
{
	
	for (int i = 0; i < str.size(); i++)
	{
		t[str[i] - 97]++;
	}
	return t;
}

int HuffmanNode::GetCounter(string str)// get the counter 
{
	int* table = new int[26]{ 0 }; // array size of alphabet
	table = creat_frequency_table(str, table); // creat requency table
	int counter = 26;
	for (int i = 0; i < 26; i++)
	{
		if (table[i] == 0)
		{
			counter--;
		}
	}
	return counter;
}

void HuffmanNode::GetLeafsNode(HuffmanNode* r) // get all the leaf nodes
{
	if (r->left == NULL && r->right == NULL) // if leaf
	{
		cout << r->ch;
		return;
	}
	GetLeafsNode(r->left); // recursion 
	GetLeafsNode(r->right); // recursion 
}

int HuffmanNode::GetFrequency() // get frequency
{
	return this->frequency;
}

void HuffmanNode::GetTreeInCode(HuffmanNode* r) // get the tree path in code
{
	if (r->left == NULL && r->right == NULL) // if leaf
	{
		cout <<"1";
		return;
	}
	cout << "0";
	GetTreeInCode(r->left); // recursion 
	GetTreeInCode(r->right); // recursion 
}

void HuffmanNode::EncodeAlgo(HuffmanNode* r, char c, string s)// Encode
{
	if (r->left == NULL && r->right == NULL && r->ch != c) // if leaf
	{
		return;
	}
	if (r->ch == c)
	{
		cout << s;
		return;
	}
	EncodeAlgo(r->left, c, s + "0"); // recursion 
	EncodeAlgo(r->right, c, s + "1"); // recursion 
	
	
}

void HuffmanNode::DecodeAlgo(HuffmanNode* r, string str) // Decode
{
	HuffmanNode* pointer = r;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '0') // if 0
		{
			pointer = pointer->left; // go to left node
			if (pointer->left == NULL && pointer->right == NULL) // if leaf
			{
				cout << pointer->ch;
				pointer = r;
			}
		}
		else // if 1
		{
			pointer = pointer->right; // go to right node
			if (pointer->left == NULL && pointer->right == NULL) // if leaf
			{
				cout << pointer->ch;
				pointer = r;
			}
		}
	}
}
void HuffmanNode::Check_valid_tree(HuffmanNode* r)// check if tree is valid
{

	if (r->left == NULL && r->right == NULL) // if leaf
	{
		if (r->ch == NULL) // if no letter
		{
			throw "ERROR"; // throw exception
		}
		return;
	}
	Check_valid_tree(r->left); // recursion
	Check_valid_tree(r->right); // recursion

}

