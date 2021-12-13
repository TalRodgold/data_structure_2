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
		bool isEndWord;
		TrieNode() // constructor
		{
			isEndWord = false;
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
	void print(TrieNode*& t,string str); // print
	bool hasChildren(TrieNode*& t); // check if a trie node has children
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

		if (!searchWord(str))
			return false;
		TrieNode* tn = this->root;
		int i = 0;
		for (; i < str.length(); i++)
		{
			tn = tn->children[str[i] - 97];
		}

		if (hasChildren(tn))
		{
			tn = tn->father;
			tn->children[str[i - 1] - 97] = NULL;
		}
		else
		{
			tn->isEndWord = false;
			return true;
		}

		while (tn != this->root)  // we're climbing the tree until we get to the root
		{
			if (hasChildren(tn) && tn->isEndWord != true) // we will delete if leaf and not an end of a word
			{
				tn = tn->father;
				tn->children[str[i - 1] - 97] = NULL;
			}
			else
				return true;
		}
		return true;
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

inline int Trie::printAllWordsFromPrefix(string str)//print
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

inline void Trie::print(TrieNode*& t,string str) // print
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

inline bool Trie::hasChildren(TrieNode*& t) // check if a trie node has children
{
	for (int i = 0; i < 26; i++)
	{
		if (t->children[i] != NULL)
			return false;
	}
	return true;
}
