// NAME:  Tal Rodgold  & Avichay Kadosh
// ID:    318162344    & 313317364
// GROUP: Haim Prianti & Efi Naftali
// PROJECT NUMBER: 4
#pragma once
#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
using namespace std;

class CompareNode
{
public:
	bool operator()(HuffmanNode* const& n1, HuffmanNode* const& n2)
	{
		return n1->frequency > n2->frequency;
	}
};

class HuffmanNode
{
protected:
	
	char ch;
	int frequency;
	HuffmanNode* left;
	HuffmanNode* right;

public:
	HuffmanNode() { ch = NULL; frequency = 0; left = NULL; right = NULL; }
	HuffmanNode(char c, int f, HuffmanNode* l, HuffmanNode* r) { ch = c; frequency = f; left = l; right = r; }
	HuffmanNode* build_huffman(string str);
	friend CompareNode;
};


