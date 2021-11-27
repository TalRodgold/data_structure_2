// NAME:  Tal Rodgold  & Avichay Kadosh
// ID:    318162344    & 313317364
// GROUP: Haim Prianti & Efi Naftali
// PROJECT NUMBER: 3
#pragma once
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
		TrieNode* children[25];
		TrieNode* father;
		bool isEndWord = false;
		TrieNode() // constructor
		{
			for (int i = 0; i < 25; i++)
			{
				this->children[i] = nullptr;
			}
		};
	};
	TrieNode* root;

public:
	Trie() { root = new TrieNode(); } // constructor
	void insertWord(string str); // insert a new word
	bool deleteWord(string str); // delete a word
	bool searchWord(string str); // search a word
	void printAllWordsFromPrefix(TrieNode*); // print
private:
	bool recursiveDelete(TrieNode*& t, string str);
	bool hasChildren(TrieNode const* curr); // check if a trie node has children
};

inline void Trie::insertWord(string str) // insert a new word
{
	TrieNode* t = this->root; // current trie
	for (int i = 0; i < str.size(); i++) // for each letter in str
	{
		if (t->children[str[i] - 97] == nullptr) // if new node
		{
			t->children[str[i] - 97] = new TrieNode();
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
	if (this->root == nullptr) // if trie is empty
	{
		return false;
	}
	TrieNode* t = this->root; // current trie
	for (int i = 0; i < str.size(); i++) // for each letter in str
	{
		t = t->children[str[i] - 97]; // go to the next node
		if (t == nullptr) // if the str is not in trie
		{
			return false;
		}
	}
	return t->isEndWord; // if last letter is end word returns true else returns false
	
}


inline void Trie::printAllWordsFromPrefix(TrieNode*)
{

}

bool Trie::recursiveDelete(TrieNode*& t, string str)
{
	if (t == nullptr) // return if Trie is empty
	{
		return false;
	}
	if (str.size()) // if the end of the str is not reached
	{
		if (t != nullptr && t->children[str[0] - 97] != nullptr && recursiveDelete(t->children[str[0] - 97], str.substr(1)) && t->isEndWord == false) 
		{
			if (!hasChildren(t))
			{
				delete t; // delete
				t = nullptr; // delete
				return true;
			}
			else {
				return false;
			}
		}
	}
	if (str.size() == 0 && t->isEndWord) // if the end of the str is reached
	{
		if (!hasChildren(t)) // if leaf and doesn't have any children
		{	
			delete t; // delete 
			t = nullptr; // delete 
			return true;
		}
		else // if is leaf and has children
		{
			t->isEndWord = false;
			return false;
		}
	}
	return false;
}

bool Trie::hasChildren(TrieNode const* curr) // check if a trie node has children
{
	for (int i = 0; i < 25; i++) // for all letters
	{
		if (curr->children[i]) 
		{
			return true;    // child found
		}
	}
	return false; 
}
