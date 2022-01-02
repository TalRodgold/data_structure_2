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

class HuffmanNode
{
	class compareNode
	{
	public:
		bool operator()(HuffmanNode* const& n1, HuffmanNode* const& n2)
		{
			return n1->GetFrequency() > n2->GetFrequency();
		}
	};
private:
	
	char ch; // character
	int frequency; // frequency
	HuffmanNode* left; // left node
	HuffmanNode* right; // right node

public:
	HuffmanNode() { ch = NULL; frequency = 0; left = NULL; right = NULL; } // default
	HuffmanNode(char c, int f, HuffmanNode* l, HuffmanNode* r) { ch = c; frequency = f; left = l; right = r; } // constructor
	HuffmanNode* build_huffman(string str, HuffmanNode* r); // build huffman tree
	HuffmanNode* rebuild_huffman(HuffmanNode* r, int num_of_leafs, string letters, string structer); // get decoded data to rebulid the huffman tree
	int* creat_frequency_table(string str, int* t); // creat frequency table
	int GetCounter(string str); // get the counter 
	void GetLeafsNode(HuffmanNode* r); // get all the leaf nodes
	int GetFrequency(); // get frequency
	void GetTreeInCode(HuffmanNode* r); // get the tree path in code
	void EncodeAlgo(HuffmanNode* r, char c, string s); // Encode
	void DecodeAlgo(HuffmanNode* r, string str); // Decode
	void Check_valid_tree(HuffmanNode* r); // check if tree is valid
	friend class compareNode; // include friend class
};


