// NAME:  Tal Rodgold  & Avichay Kadosh
// ID:    318162344    & 313317364
// GROUP: Haim Prianti & Efi Naftali
// PROJECT NUMBER: 2
#pragma once
#include <iostream>
#include "Item.h"
#include <list>
#include <algorithm>
using namespace std;

template<class T, class K>
class HashTbls
{
protected:
	int size; // size of hash table
	Item<T, K>* tbl; // T is item K is key

public:
	HashTbls(int number);//constructor
	~HashTbls();//distructor
    virtual int H1(K key) = 0;// h1 hash function
    virtual int H2(K key) = 0;// h2 hash function
    int isPrime(int); // get next prime number
    int Hash(K k, int I); // hash
    void Hash_insert(Item<T, K> item); // hash insert
    int Hash_search(K k); // hash search
    void Hash_delete(T t, K k); // hash delete
    void Hash_print(); // hash print
    int Get_size(); // get size
    Item<T, K>& operator[](int index); // operator []
};

template<class T, class K>
inline HashTbls<T, K>::HashTbls(int number)//constructor
{
    size = isPrime(number); 
    tbl = new Item<T, K>[size];
}

template<class T, class K>
inline HashTbls<T, K>::~HashTbls()//distructor
{
    if (tbl)
    {
        delete[] tbl;
    }
}

template<class T, class K>
inline int HashTbls<T, K>::Hash(K k, int I) // hash
{
    return (H1(k) + I*H2(k)) % size;
}

template<class T, class K>
inline void HashTbls<T, K>::Hash_insert(Item<T, K> item) // hash insert
{
    int j = 0; // holds hash location
    for (int i = 0; i < size; i++) // for size of hash table
    {
        j = Hash(item.key, i); // calculate hash
        if (tbl[j].flag == state::empty || tbl[j].flag == state::deleted) // if cell is free
        {
            tbl[j] = item; // add to cell
            tbl[j].flag = state::full; // change cell to full
            return; 
        }
    }
    throw "OVERFLOW!"; // else throw
}

template<class T, class K>
inline int HashTbls<T, K>::Hash_search(K k) // hash search
{
    int i = 0; // index counter
    int j = 0; // holds hash location
    while (i < size || tbl[j].flag != state::empty) // untiil we find free cell
    {
        j = Hash(k, i); // calculate hash
        if (tbl[j].key == k) // if found
        {
            return j;
        }
        i = i + 1; // grow index counter
    }
    return -1; // if not found
}

template<class T, class K>
inline void HashTbls<T, K>::Hash_delete(T t, K k) // hash delete
{
    int i = Hash_search(k); // location in hash
    if (i == -1) // if not found
    {
        throw "ERROR";
    }
    tbl[i].flag = state::deleted; // change cell status to deleted
}

template<class T, class K>
inline void HashTbls<T, K>::Hash_print() // hash print
{
    for (int i=0;i<size;i++)
    {
        if (tbl[i].flag == state::full) // if there is element in cell
        {
            cout << tbl[i].data << endl; // print
        }
    }
}

template<class T, class K>
inline int HashTbls<T, K>::Get_size() // get size
{
    return size; 
}

template<class T, class K>
inline Item<T, K>& HashTbls<T, K>::operator[](int index) // operator []
{
    return tbl[index]; 
}

template<class T, class K>
inline int HashTbls<T,K>::isPrime(int num)//return the closer prime number to size of arrey
{

    for (int i = 2; i <= num / 2; i++) 
    {
        if (num % i == 0)
        {
            isPrime(++num);
        }
    }
    return num;
}




