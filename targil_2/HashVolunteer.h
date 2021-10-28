#pragma once
#include "HashTbls.h"
#include "Volunteer.h"
#include <string>
#include <iostream>
using namespace std;
class HashVolunteer:public HashTbls<Volunteer,string>
{
public:
	int H1(string key) override;
	int H2(string key) override;
};

int HashVolunteer::H1(string key)
{
	return (stoi(key) % size);
}
inline int HashVolunteer::H2(string key)
{
	return 1 + (stoi(key) % (size - 1));
}
