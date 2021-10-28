#pragma once
#include "HashTbls.h"
#include "Client.h"
#include <string>
#include <iostream>
using namespace std;
class HashClient:public HashTbls<Client,int>
{
public:
	int H1(int key) override;
	int H2(int key) override;
};
int HashClient::H1(int key)
{
	return key % size;
}

int HashClient::H2(int key)
{
	return 1+key%(size-1);
}
