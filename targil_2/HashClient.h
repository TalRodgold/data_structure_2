#pragma once
#include "HashTbls.h"
#include "Client.h"
#include <string>
#include <iostream>
using namespace std;
class HashClient:public HashTbls<Client,int>
{
public:
	HashClient(int x) :HashTbls::HashTbls(x) {};
	int H1(int key) override;
	int H2(int key) override;
	bool FindInList(Client c, string s) { return c.Find_in_list(s); }
};
inline int HashClient::H1(int key)
{
	return key % size;
}

inline int HashClient::H2(int key)
{
	return 1+key%(size-1);
}



