// NAME:  Tal Rodgold  & Avichay Kadosh
// ID:    318162344    & 313317364
// GROUP: Haim Prianti & Efi Naftali
// PROJECT NUMBER: 4

#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#include "huffman.h"
using namespace std;

int main()
{
	char choice;


	huffman* t = new huffman();
	cout << "enter E to encode a text\n";
	cout << "enter D to decode a text\n";
	cout << "enter X to exit\n";

	do
	{
		cin >> choice;
		switch (choice)
		{
		case 'E':
			{
			string word;
			cout << "enter the original text" << endl;
			cin >> word;
			cout << "The encoded string is : \n" ;
			t->Start(word); //Build Huffman tree given the data inside "word".
			cout << t->GetNumOfLetters(word) << endl;
			t->GetLeafs();
			cout << endl;
			t->GetTreeStructer(); 
			cout << endl;
			t->Encode(word);
			cout << endl;
			}
			break;
		case 'D':
			{
			int n;
			string s, l, te;
			cout << "enter n" << endl; //input the number of leaves
			cin >> n;
			cout << "enter the letters" << endl; //the  order of letters
			cin >> l;
			cout << "enter the encoded structure" << endl; //tree structure
			cin >> s;
			cout << "enter the encoded text" << endl; //the encoded text
			cin >> te;
			try
			{
				t->Decode(n, l, s, te); //build the Huffman Tree according to the tree strcture find the original text, and print it.
				cout << endl;
			}
			catch (...)
			{
				cout << "ERROR\n";
			}
			}
		}
	} while (choice != 'X');
	cout << "bye";
	return 0;
}