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
#include "HuffmanNode.h"
using namespace std;

class huffman
{
private:
	HuffmanNode* root;

public:
	huffman() { root = NULL; } // constructor
	void Start(string str); // start and build the huffman tree
	void GetLeafs(); // get all the leafs in tree
	int GetNumOfLetters(string str) { return root->GetCounter(str); } // get number of letters
	void GetTreeStructer() { root->GetTreeInCode(root); } // get tree in code
	void Encode(string str); // Encode
	void Decode(int num_of_leafs, string letters, string structer, string text); //Decode
};

