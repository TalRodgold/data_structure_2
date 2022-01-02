// NAME:  Tal Rodgold  & Avichay Kadosh
// ID:    318162344    & 313317364
// GROUP: Haim Prianti & Efi Naftali
// PROJECT NUMBER: 4
#include "huffman.h"
#include <string>

void huffman::Start(string str) // start and build the huffman tree
{
	root = new HuffmanNode(); 
	root = root->build_huffman(str, root);
}

void huffman::GetLeafs() // get all the leafs in tree
{
	return root->GetLeafsNode(this->root);
}

void huffman::Encode(string str) // Encode
{
	for (int i = 0; i < str.size(); i++)
	{
		root->EncodeAlgo(root, str[i], "");
	}
}

void huffman::Decode(int num_of_leafs, string letters, string structer, string text) //Decode
{
	HuffmanNode* r = new HuffmanNode();
	r = root->rebuild_huffman(r, num_of_leafs, letters, structer);
	root->Check_valid_tree(r);
	cout << "The decoded string is" << endl;
	root->DecodeAlgo(r, text);
}
