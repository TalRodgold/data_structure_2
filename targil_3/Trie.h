// NAME:  Tal Rodgold  & Avichay Kadosh
// ID:    318162344    & 313317364
// GROUP: Haim Prianti & Efi Naftali
// PROJECT NUMBER: 3
#pragma once
#include <cstddef>
#include <iostream>
#include <list>
#include <string>
using namespace std;
class Trie
{
protected:
	class TrieNode
	{
	public:
		TrieNode* children[26];
		TrieNode* father;
		bool isEndWord = false;
		TrieNode() // constructor
		{
			for (int i = 0; i < 26; i++)
			{
				this->children[i] = NULL;
			}
		};
	};
	TrieNode* root;

public:
	Trie() { root = new TrieNode(); } // constructor
	void insertWord(string str); // insert a new word
	bool deleteWord(string str); // delete a word
	bool searchWord(string str); // search a word
	int printAllWordsFromPrefix(string str); // print
private:
	
	bool hasChildren(TrieNode const* curr); // check if a trie node has children
	void print(TrieNode*& t,string str);
};

inline void Trie::insertWord(string str) // insert a new word
{
	TrieNode* t = this->root; // current trie
	for (int i = 0; i < str.size(); i++) // for each letter in str
	{
		if (t->children[str[i] - 97] == NULL) // if new node
		{
			t->children[str[i] - 97] = new TrieNode();
			t->children[str[i] - 97]->father = t;
		}
		t = t->children[str[i] - 97]; // change current trie to next
	}
	t->isEndWord = true; // change end word
}

inline bool Trie::deleteWord(string str) // delete a word
{
	return recursiveDelete(this->root, str); // call a recursive func to delete
}

inline bool Trie::searchWord(string str) // search a word
{
	if (this->root == NULL) // if trie is empty
	{
		return false;
	}
	TrieNode* t = this->root; // current trie
	for (int i = 0; i < str.size(); i++) // for each letter in str
	{
		t = t->children[str[i] - 97]; // go to the next node
		if (t == NULL) // if the str is not in trie
		{
			return false;
		}
	}
	return t->isEndWord; // if last letter is end word returns true else returns false	
}

inline int Trie::printAllWordsFromPrefix(string str)
{

	if (this->root == NULL) // if trie is empty
	{
		return 0;
	}
	TrieNode* t = this->root; // current trie
	for (int i = 0; i < str.size(); i++) // for each letter in str
	{
		t = t->children[str[i] - 97]; // go to the next node
		if (t == NULL) // if the str is not in trie
		{
			return 0;
		}
	}
	print(t,str);
	return 1;
}

TrieNode*& Trie::recursiveDelete(TrieNode*& t, string str)
{
	if (t == NULL)
	{
		return false;
	}
	if (t->isEndWord)
		return true;
	if (t->children[str[0]-97] == NULL)
		return false;
	recursiveDelete(t->children[str[0] - 97], str.substr(1,str.size()));
	//if (t->isEndWord && [=](TrieNode*& t) {for (int i = 0;i < 26;i++) { if (t->children[i] != NULL) return false; }}(t))
	//{
	//	t->father->children[str[0] - 97] = NULL;
	//}

	//if (t == NULL) // return if Trie is empty
	//{
	//	return false;
	//}
	//if (str.size()) // if the end of the str is not reached
	//{
	//	if (t != NULL && t->children[str[0] - 97] != NULL && recursiveDelete(t->children[str[0] - 97], str.substr(1)) && t->isEndWord == false)
	//	{
	//		if (!hasChildren(t))
	//		{
	//			delete t; // delete
	//			t = NULL; // delete
	//			return true;
	//		}
	//		else {
	//			return false;
	//		}
	//	}
	//}
	//if (str.size() == 0 && t->isEndWord) // if the end of the str is reached
	//{
	//	if (!hasChildren(t)) // if leaf and doesn't have any children
	//	{	
	//		delete t; // delete 
	//		t = NULL; // delete 
	//		return true;
	//	}
	//	else // if is leaf and has children
	//	{
	//		t->isEndWord = false;
	//		return false;
	//	}
	//}
	//return false;
}

bool Trie::hasChildren(TrieNode const* curr) // check if a trie node has children
{
	for (int i = 0; i < 26; i++) // for all letters
	{
		if (curr->children[i]) 
		{
			return true;    // child found
		}
	}
	return false; 
}

inline void Trie::print(TrieNode*& t,string str)
{
	if (t->isEndWord)
	{
		cout << str << endl;
		return;
	}
	
	for (int i = 0; i <26; i++) // for each letter in str
	{
		if (t->children[i] != NULL)
		{
			str += char(i + 97);
			print(t->children[i] , str);
			str=str.substr(0,str.size()-1);
		}
	}

}
