// NAME:  Tal Rodgold  & Avichay Kadosh
// ID:    318162344    & 313317364
// GROUP: Haim Prianti & Efi Naftali
// PROJECT NUMBER: 2
#pragma once
#include "HashTbls.h"
#include <string>
#include <iostream>
#include "Item.h"
using namespace std;

class Volunteer//:public Item<Volunteer, string>
{
public:
	string name;
	string address;
	int phone;
	string city;

	Volunteer() { name = ""; address = ""; phone = 0; city = ""; }
	Volunteer(string n , string a, int p, string c);
	~Volunteer() { }
	Volunteer operator=(const Volunteer& v);
	bool operator==(const Volunteer& v)const;
	friend ostream& operator<<(ostream& os, const Volunteer& in); // cout
	friend istream& operator>>(istream& is, Volunteer& in); // cin
};

inline Volunteer::Volunteer(string n, string a, int p, string c)
{
	name = n;
	address = a;
	phone = p;
	city = c;
}


inline Volunteer Volunteer::operator=(const Volunteer& v)
{
	this->name = v.name;
	this->address = v.address;
	this->phone = v.phone;
	this->city = v.city;
	return *this;
}

inline bool Volunteer::operator==(const Volunteer& v) const
{
	if (this->name == v.name)
	{
		return true;
	}
	return false;
}

inline ostream& operator<<(ostream& os, const Volunteer& in)
{
	os << "Name: " << in.name << endl;
	os << "Address: " << in.address << endl;
	os << "Phone: " << in.phone << endl;
	os << "City: " << in.city << endl;
	return os;
}

inline istream& operator>>(istream& is, Volunteer& in)
{
	cout << "Enter volunteer name phone address" << endl; // print
	string input_name;
	//string input_address;
	int input_phone;
	string input_city;
	is >> input_name  >> input_phone >> input_city;
	in.name = input_name;
	//in.address = input_address;
	in.phone = input_phone;
	in.city = input_city;
	return is;
}

