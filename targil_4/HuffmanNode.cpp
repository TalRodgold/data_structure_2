#include "HuffmanNode.h"
#include <list>
#include <queue>
#include <algorithm>
HuffmanNode* HuffmanNode::build_huffman(string str)
{
	int* table = creat_frequency_table(str);
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNode> pQueue;
	int counter = 26;
	HuffmanNode* temp;
	for (int i = 0; i < 26; i++)
	{
		if (table[i] != 0)
		{
			temp = new HuffmanNode((char)(i+97), table[i], NULL, NULL);
			pQueue.push(temp);
		}
		else
		{
			counter--;
		}
	}
	for (int i = 0; i < counter-1; i++)
	{
		temp = new HuffmanNode();
		temp->left = pQueue.top();
		pQueue.pop();
		temp->right = pQueue.top();
		pQueue.pop();
		temp->frequency = temp->left->frequency + temp->right->frequency;
		pQueue.push(temp);
	}
	return  pQueue.top();
}

int* creat_frequency_table(string str)
{
	int table[26]{ 0 };
	for (int i = 0; i < str.size(); i++)
	{
		table[str[i] - 97]++;
	}
	return table;
}
