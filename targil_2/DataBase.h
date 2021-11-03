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
	HashClient hash_client{ 100 }; //hash table of clients
	HashVolunteer hash_volunteer{ 100 }; //hash table of volunteers
public:
	DataBase() {};  // default 
	void addVolunteer(Volunteer v); // add a volunteer
	void delVolunteer(Volunteer v); // delete a volunteer
	void addClient(Client c); // add a client
	void Delete_client(Client c); // delete a client
	void addVolunteerToClient(Volunteer v, Client c); // add a volunteer to a client
	void listOfVolunteers(Client c); // print list of volunteers
	void listOfClients(Volunteer v); // print list of clients
	void PrintAll(Volunteer v, Client c); // print all volunteers and clients
};

inline void DataBase::addVolunteer(Volunteer v) // add a volunteer
{
	hash_volunteer.Hash_insert(Item<Volunteer, string>(v, v.name));
}

inline void DataBase::delVolunteer(Volunteer v) // delete a volunteer
{
	int index = hash_volunteer.Hash_search(v.name); // index of wanted volunteer
	if (index == -1) // if volunteer doesnt exsist
	{
		throw "ERROR"; // throw
	}
	hash_volunteer.Hash_delete(v, v.name); // delete
}

inline void DataBase::addClient(Client c) // add a client
{
	hash_client.Hash_insert(Item<Client, int>(c, c.phone));
}

inline void DataBase::Delete_client(Client c) // delete a client
{
	hash_client.Hash_delete(c, c.phone);
}

inline void DataBase::addVolunteerToClient(Volunteer v, Client c) // add a volunteer to a client
{
	int index_client = hash_client.Hash_search(c.phone); // find index of client
	int index_volunteer = hash_volunteer.Hash_search(v.name); // find index of volunteer
	if (index_volunteer == -1 || index_client == -1 || hash_volunteer[index_volunteer].flag == state::deleted || hash_client[index_client].flag == state::deleted) // if one of them dosent exisist
	{
		throw "ERROR"; // throw
	}
	hash_client[index_client].data.Add_to_list(v.name); // add do list of volunteers
}

inline void DataBase::listOfVolunteers(Client c) // print list of volunteers
{
	int index_client = hash_client.Hash_search(c.phone); // find index of client
	cout << "The volunteers that helped to client " << c.phone << ": "; 
	if (index_client != -1) // if exsist
	{
		hash_client[index_client].data.Print_list(); // print
	}
}

inline void DataBase::listOfClients(Volunteer v) // print list of clients
{
	cout << "The clients that were helped by volunteer " << v.name << ": ";
	for (int i = 0; i < hash_client.Get_size(); i++) // for all hash
	{
		if (hash_client[i].flag == state::empty || hash_client[i].flag == state::deleted) // if empty or deleted
		{
			continue;
		}
		if(hash_client.FindInList(hash_client[i].data, v.name)) // else find in list
		{
			cout << hash_client[i].data.name << endl; // print
		}
	}
}

inline void DataBase::PrintAll(Volunteer v, Client c) // print all volunteers and clients
{
	cout << "ALL CLIENTS:" << endl;
	for (int i = 0; i < hash_client.Get_size(); i++) // print all clients
	{
		if (hash_client[i].flag == state::empty || hash_client[i].flag == state::deleted)
		{
			continue;
		}
			cout << hash_client[i].data << endl;
	}
	cout << "ALL VOLUNTEERS:" << endl;
	for (int i = 0; i < hash_client.Get_size(); i++) // print all volunteers
	{
		if (hash_volunteer[i].flag == state::empty || hash_volunteer[i].flag == state::deleted)
		{
			continue;
		}
			cout << hash_volunteer[i].data << endl;
	}
}
