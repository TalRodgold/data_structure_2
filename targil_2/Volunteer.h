#pragma once
#include "HashTbls.h"
#include <iostream>
using namespace std;
class Volunteer:public HashTbls<class, class>////
{
	string name;
	string address;
	int phone;
	string city;
public:
	Volunteer() {};
	~Volunteer() {};
	Volunteer operator=(const Volunteer& v);
	Volunteer operator==(const Volunteer& v)const;
	friend ostream& operator<<(ostream& os, const Volunteer& in); // cout
	friend istream& operator>>(istream& is, Volunteer& in); // cin
};

