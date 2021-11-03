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

class Volunteer
{
public:
	string name; // name
	string address; // address
	int phone; // phone number
	string city; // city

	Volunteer() { name = ""; address = ""; phone = 0; city = ""; } // default 
	Volunteer(string n , string a, int p, string c); // constructor
	~Volunteer() {} // distructor
	Volunteer operator=(const Volunteer& v); // operator =
	bool operator==(const Volunteer& v)const; // operator ==
	friend ostream& operator<<(ostream& os, const Volunteer& in); // cout
	friend istream& operator>>(istream& is, Volunteer& in); // cin
};

inline Volunteer::Volunteer(string n, string a, int p, string c) // constructor
{
	name = n;
	address = a;
	phone = p;
	city = c;
}

inline Volunteer Volunteer::operator=(const Volunteer& v) // operator =
{
	this->name = v.name;
	this->address = v.address;
	this->phone = v.phone;
	this->city = v.city;
	return *this;
}

inline bool Volunteer::operator==(const Volunteer& v) const // operator ==
{
	if (this->name == v.name) // compair by name
	{
		return true;
	}
	return false;
}

inline ostream& operator<<(ostream& os, const Volunteer& in) // cout
{
	os << "Name: " << in.name << endl;
	os << "Address: " << in.address << endl;
	os << "Phone: " << in.phone << endl;
	os << "City: " << in.city << endl;
	return os;
}

inline istream& operator>>(istream& is, Volunteer& in) // cin
{
	cout << "Enter volunteer name phone address" << endl; // print
	string input_name;
	int input_phone;
	string input_city;
	is >> input_name  >> input_phone >> input_city;
	in.name = input_name;
	in.phone = input_phone;
	in.city = input_city;
	return is;
}

