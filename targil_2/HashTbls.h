// NAME:  Tal Rodgold  & Avichay Kadosh
// ID:    318162344    & 313317364
// GROUP: Haim Prianti & Efi Naftali
// PROJECT NUMBER: 2
#pragma once
#include <iostream>
#include "Item.h"
#include <list>
using namespace std;

template<class T, class K>
class HashTbls
{
protected:
	int size;
	Item<T, K>* tbl;//T is item K is key

public:
	HashTbls(int number);//constructor
	~HashTbls();//distructor
    virtual int H1(K key) = 0;//asistenting hash function
    virtual int H2(K key) = 0;// hash function
    int isPrime(int);
    int Hash(K k, int I);
    void Hash_insert(Item<T, K> item);
    int Hash_search(K k);
    void Hash_delete(T t, K k);
    void Hash_print();
    int Get_size();
    Item<T, K>& operator[](int index);
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
inline int HashTbls<T, K>::Hash(K k, int I)
{
    return (H1(k) + I*H2(k)) % size;
}

template<class T, class K>
inline void HashTbls<T, K>::Hash_insert(Item<T, K> item)
{
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        j = Hash(item.key, i);
        if (tbl[j].flag == state::empty)
        {
            tbl[j] = item;
            tbl[j].flag = state::full; // casting
            return;
        }
        if (tbl[j].flag == state::deleted)
        {
            tbl[j] = item;
            return;
        }
    }
    throw "OVERFLOW!";
}

template<class T, class K>
inline int HashTbls<T, K>::Hash_search(K k)
{
    int i = 0;
    int j = 0;
    while (i < size || tbl[j].flag != state::empty)
    {
        j = Hash(k, i);
        if (tbl[j].key == k)
        {
            return j;
        }
        i = i + 1;
    }
    return -1;
}

template<class T, class K>
inline void HashTbls<T, K>::Hash_delete(T t, K k)
{
    int i = Hash_search(k);
    tbl[i].flag = state::deleted;
}

template<class T, class K>
inline void HashTbls<T, K>::Hash_print()
{
    for (int i=0;i<size;i++)
    {
        if (tbl[i].flag == full)
        {
            cout << tbl[i].data << endl;
        }
    }
}

template<class T, class K>
inline int HashTbls<T, K>::Get_size()
{
    { return size; }
}

template<class T, class K>
inline Item<T, K>& HashTbls<T, K>::operator[](int index)
{
    return tbl[index]; 
}

template<class T, class K>
inline int HashTbls<T,K>::isPrime(int num)//return the closer prime number to size of arrey
{

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0)
        {
            isPrime(++num);
        }
    }
    return num;
}




