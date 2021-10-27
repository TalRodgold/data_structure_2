#pragma once
#include <iostream>
using namespace std;
template<int T, int K>

class Client:public HashTbls<int, int>
{
	string name;
	int phone;
	string address;
	string* list
public:
	Client() {};
	~Client() {};
	Client operator=(const Client& v);
	Client operator==(const Client& v)const;
	friend ostream& operator<<(ostream& os, const Client& in); // cout
	friend istream& operator>>(istream& is, Client& in); // cin
};

