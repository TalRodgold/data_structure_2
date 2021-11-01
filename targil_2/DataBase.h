// NAME:  Tal Rodgold  & Avichay Kadosh
// ID:    318162344    & 313317364
// GROUP: Haim Prianti & Efi Naftali
// PROJECT NUMBER: 2
#pragma once
#include "HashClient.h"
#include "HashVolunteer.h"
#include <string>
#include <iostream>
using namespace std;

class DataBase
{
	HashClient hash_client{ 100 };
	HashVolunteer hash_volunteer{ 100 };
public:
	DataBase() {};
	void addVolunteer(Volunteer v);
	void delVolunteer(Volunteer v);
	void addClient(Client c);
	void Delete_client(Client c);
	void addVolunteerToClient(Volunteer v, Client c);
	void listOfVolunteers(Client c);
	void listOfClients(Volunteer v);
	void PrintAll(Volunteer v, Client c);
	void printallclient() { hash_client.printall(); }//i aadded
	void printallvolunteer() { hash_volunteer.printall(); }//i addd
};
inline void DataBase::addVolunteer(Volunteer v)
{
	hash_volunteer.Hash_insert(Item<Volunteer, string>(v, v.name));
}

inline void DataBase::delVolunteer(Volunteer v)
{
	hash_volunteer.Hash_delete(v, v.name);
	for (int i = 0; i < hash_client.Get_size(); i++)//i added !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	{
		auto j = hash_client[i].data.list_of_volunteers.end();
		//hash_client[i].data.list_of_volunteers.remove(v.name);
		j=for_each(hash_client[i].data.list_of_volunteers.begin(), hash_client[i].data.list_of_volunteers.end(), [=](string s, list<string> ::iterator it) {if (s == v.name)return it;});
		if (j != hash_client[i].data.list_of_volunteers.end())
		{
			hash_client[i].data.list_of_volunteers.erase(j);
		}

	}
}

inline void DataBase::addClient(Client c)
{
	hash_client.Hash_insert(Item<Client, int>(c, c.phone));
}

inline void DataBase::Delete_client(Client c)
{
	hash_client.Hash_delete(c, c.phone);
}

inline void DataBase::addVolunteerToClient(Volunteer v, Client c)
{
	int index_client = hash_client.Hash_search(c.phone);
	int index_volunteer = hash_volunteer.Hash_search(v.name);
	if (index_volunteer == -1 || index_client == -1)
	{
		throw "ERROR";
	}
	hash_client[index_client].data.Add_to_list(v.name);
}

inline void DataBase::listOfVolunteers(Client c)
{
	int index_client = hash_client.Hash_search(c.phone);
	if (index_client != -1)//i added
	{
		hash_client[index_client].data.Print_list();
	}
}

inline void DataBase::listOfClients(Volunteer v)
{
	cout << "The clients that were helped by volunteer " << v.name << ": ";
	for (int i = 0; i < hash_client.Get_size(); i++)
	{
		if (hash_client[i].flag == state::empty || hash_client[i].flag == state::deleted)
		{
			continue;
		}
		if(hash_client.FindInList(hash_client[i].data, v.name))
		{
			cout << hash_client[i].data.name << endl;
		}
	}
}

inline void DataBase::PrintAll(Volunteer v, Client c)
{
	cout << "ALL CLIENTS:" << endl;
	for (int i = 0; i < hash_client.Get_size(); i++)
	{
		if (hash_client[i].flag == state::empty || hash_client[i].flag == state::deleted)
		{
			continue;
		}
			cout << hash_client[i].data << endl;
	}
	cout << "ALL VOLUNTEERS:" << endl;
	for (int i = 0; i < hash_client.Get_size(); i++)
	{
		if (hash_volunteer[i].flag == state::empty || hash_volunteer[i].flag == state::deleted)
		{
			continue;
		}
			cout << hash_volunteer[i].data << endl;
	}
}
