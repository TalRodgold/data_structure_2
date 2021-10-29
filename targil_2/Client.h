#pragma once
#include <iostream>
#include<string>
#include <list>
#include <algorithm>
#include "Item.h"
using namespace std;
class Client//:public Item<Client, int>
{
public:
	string name;
	int phone;
	string address;
	list<string> list_of_volunteers;

	 Client(string,int,string);		
	 Client() { name = ""; phone = 0; address = ""; }
	 ~Client() {};
	int GetPhone();
	string GetName() { return name; }
	void Print_list();
	void Add_to_list(string s);
	bool Find_in_list(string s);
	Client operator=(const Client& v);
	bool operator==(const Client& v)const;
	friend ostream& operator<<(ostream& os, const Client& in); // cout
	friend istream& operator>>(istream& is, Client& in); // cin
	
};

inline int Client::GetPhone()
{
	return phone;
}
inline void Client::Print_list()
{
	cout << "list of all volunteers" << endl;
	for_each(list_of_volunteers.begin(), list_of_volunteers.end(), [](string n) { cout << n << endl; });
}
inline void Client::Add_to_list(string s)
{
	if (find(list_of_volunteers.begin(), list_of_volunteers.end(), s) != list_of_volunteers.end())
	{
		return;
	}
	list_of_volunteers.push_back(s);
}
inline bool Client::Find_in_list(string s)
{
	if (find(list_of_volunteers.begin(), list_of_volunteers.end(), s) != list_of_volunteers.end())
	{
		return true;
	}
	return false;
}
inline Client Client::operator=(const Client& v)
{
	name = v.name;
	phone = v.phone;
	address = v.address;
	list_of_volunteers = v.list_of_volunteers;
	return *this;
}
inline Client::Client(string n,int p,string a)
{
	name = n;
	phone = p;
	address = a;
}

inline bool  Client::operator==(const Client& v) const
{
	if(name==v.name)
	{
		return true;
	}
	return false;
}
inline ostream& operator<<(ostream& os, const Client& in)
 {
	 os << "Name: " << in.name << endl;
	 os << "Address: " << in.address << endl;
	 os << "Phone: " << in.phone << endl;
	 cout << "list of all volunteers" << endl;
	 for_each(in.list_of_volunteers.begin(), in.list_of_volunteers.end(), [](string n) {cout << n << endl;});
	 return os;
 }

 inline istream& operator>>(istream& is, Client& in)
 {
	 cout << "Enter volunteers details: \n 1)Name \n 2) Address \n 3) Phone number \n " << endl; // print
	string input_name;
	string input_address;
	int input_phone;
	//string v;
	is >> input_name >> input_address >> input_phone ;
	in.name = input_name;
	in.address = input_address;
	in.phone = input_phone;

	//while (v != "stop")
	//{
	//	if (find(in.list_of_volunteers.begin(), in.list_of_volunteers.end(), v) != in.list_of_volunteers.end())
	//	{
	//		continue;
	//	}
	//	in.list_of_volunteers.push_back(v);
	//}
	return is;
 }

