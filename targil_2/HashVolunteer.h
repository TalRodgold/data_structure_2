// NAME:  Tal Rodgold  & Avichay Kadosh
// ID:    318162344    & 313317364
// GROUP: Haim Prianti & Efi Naftali
// PROJECT NUMBER: 2
#pragma once
#include "HashTbls.h"
#include "Volunteer.h"
#include <string>
#include <iostream>
using namespace std;

class HashVolunteer:public HashTbls<Volunteer,string>
{
public:
	HashVolunteer(int x) :HashTbls::HashTbls(x) {}; // constructor
	int H1(string key) override; // h1 func
	int H2(string key) override; // h2 func
};

inline int HashVolunteer::H1(string key) // h1 func
{
	return (key[0] % size);
}

inline int HashVolunteer::H2(string key) // h2 func
{
	return 1 + (key[0] % (size - 1));
}

