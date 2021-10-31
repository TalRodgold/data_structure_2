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
};
inline void DataBase::addVolunteer(Volunteer v)
{
	hash_volunteer.Hash_insert(Item<Volunteer, string>(v, v.GetName()));
}

inline void DataBase::delVolunteer(Volunteer v)
{
	hash_volunteer.Hash_delete(v, v.GetName());
}

inline void DataBase::addClient(Client c)
{
	hash_client.Hash_insert(Item<Client, int>(c, c.GetPhone()));
}

inline void DataBase::Delete_client(Client c)
{
	hash_client.Hash_delete(c, c.GetPhone());
}

inline void DataBase::addVolunteerToClient(Volunteer v, Client c)
{

	if ((hash_client.Hash_search(c.GetPhone()) == -1) || (hash_volunteer.Hash_search(v.GetName()) == -1))
	{
		throw "ERROR";
	}
	c.Add_to_list(v.GetName());
	

}

inline void DataBase::listOfVolunteers(Client c)
{
	c.Print_list();
}

inline void DataBase::listOfClients(Volunteer v)
{
	for (int i = 0; i < hash_client.Get_size(); i++)
	{
		if (hash_client[i].flag == state::empty || hash_client[i].flag == state::deleted)
		{
			continue;
		}
		if(hash_client.FindInList(hash_client[i].data, v.GetName()))
		{
			cout << hash_client[i].data.GetName() << endl;
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
