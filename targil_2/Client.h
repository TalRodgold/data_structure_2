// NAME:  Tal Rodgold  & Avichay Kadosh
// ID:    318162344    & 313317364
// GROUP: Haim Prianti & Efi Naftali
// PROJECT NUMBER: 2
#pragma once
#include <iostream>
#include<string>
#include <list>
#include <algorithm>
using namespace std;

class Client
{
public:
	string name; // name
	int phone; // phone number
	string address; // address
	list<string> list_of_volunteers; // list of all the volunteers that helped this client

	 Client(string,int,string); // constructor
	 Client() { name = ""; phone = 0; address = "";} // default
	 ~Client(){} // distructor
	void Print_list(); // print list of volunteers
	void Add_to_list(string s); // add a volunteer to list
	bool Find_in_list(string s); // find a volunteer in list
	Client operator=(const Client& v); // operator =
	bool operator==(const Client& v)const; // operator ==
	friend ostream& operator<<(ostream& os, const Client& in); // cout
	friend istream& operator>>(istream& is, Client& in); // cin
	
};

inline Client::Client(string n, int p, string a) // constructor
{
	name = n;
	phone = p;
	address = a;
}

inline void Client::Print_list() // print list of volunteers
{
	for_each(list_of_volunteers.begin(), list_of_volunteers.end(), [](string n) { cout << n << endl; });
}

inline void Client::Add_to_list(string s) // add a volunteer to list
{
	if (find(list_of_volunteers.begin(), list_of_volunteers.end(), s) != list_of_volunteers.end()) // if exisists already
	{
		throw "ERROR"; // throw
	}
	list_of_volunteers.push_back(s); // else add
}

inline bool Client::Find_in_list(string s) // find a volunteer in list
{
	if (find(list_of_volunteers.begin(), list_of_volunteers.end(), s) != list_of_volunteers.end()) // if found
	{
		return true;
	}
	return false; // if not found
}

inline Client Client::operator=(const Client& v) // operator =
{
	name = v.name;
	phone = v.phone;
	address = v.address;
	list_of_volunteers = v.list_of_volunteers;
	return *this;
}

inline bool  Client::operator==(const Client& v) const // operator ==
{
	if(name==v.name) // chaek by name
	{
		return true;
	}
	return false;
}

inline ostream& operator<<(ostream& os, const Client& in) // cout
 {
	 os << "Name: " << in.name << endl;
	 os << "Address: " << in.address << endl;
	 os << "Phone: " << in.phone << endl;
	 cout << "list of all volunteers" << endl;
	 for_each(in.list_of_volunteers.begin(), in.list_of_volunteers.end(), [](string n) {cout << n << endl;});
	 return os;
 }

 inline istream& operator>>(istream& is, Client& in) // cin
 {
	 cout << "please enter name and phone and address of client " << endl; // print
	string input_name;
	string input_address;
	int input_phone;
	is >> input_name >> input_phone >> input_address  ;
	in.name = input_name;
	in.address = input_address;
	in.phone = input_phone;
	return is;
 }

