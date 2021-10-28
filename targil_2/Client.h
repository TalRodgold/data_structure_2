#pragma once
#include <iostream>
using namespace std;
#include<string>
#include <list>
#include <algorithm>
class Client
{
	string name;
	int phone;
	string address;
	list<string> list_of_volunteers;
public:
	 Client(string,int,string,list<string> l);
	~Client();
	Client operator=(const Client& v);
	bool operator==(const Client& v)const;
	friend ostream& operator<<(ostream& os, const Client& in); // cout
	friend istream& operator>>(istream& is, Client& in); // cin
};
Client:: ~Client()
{}
inline Client Client::operator=(const Client& v)
{
	name = v.name;
	phone = v.phone;
	address = v.address;
	list_of_volunteers = v.list_of_volunteers;
	return *this;
}
Client::Client(string n="",int p=0,string a="", list<string> l)
{
	name = n;
	phone = p;
	address = a;
	list_of_volunteers = l;
}

 bool  Client::operator==(const Client& v) const
{
	if(name==v.name)
	{
		return true;
	}
	return false;
}
 ostream& operator<<(ostream& os, const Client& in)
 {
	 os << "Name: " << in.name << endl;
	 os << "Address: " << in.address << endl;
	 os << "Phone: " << in.phone << endl;
	 for_each(in.list_of_volunteers.begin(), in.list_of_volunteers.end(), [](string n) {cout << "list of all volunteers" << n << endl;});
	 return os;
 }

 inline istream& operator>>(istream& is, Client& in)
 {
	 cout << "Enter volunteers details: \n 1)Name \n 2) Address \n 3) Phone number \n 4) city" << endl; // print
	string input_name;
	string input_address;
	int input_phone;
	string v;
	is >> input_name >> input_address >> input_phone;
	in.name = input_name;
	in.address = input_address;
	in.phone = input_phone;

	while (v != "stop")
	{
		if (find(in.list_of_volunteers.begin(), in.list_of_volunteers.end(), v) != in.list_of_volunteers.end())
		{
			continue;
		}
		in.list_of_volunteers.push_back(v);
	}
	return is;
 }
