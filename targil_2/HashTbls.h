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
    virtual int H1() = 0;//asistenting hash function
    virtual int H2() = 0;// hash function
    int isPrime(int);
    int Hash(K k, int I);
    void Hash_insert(Item<T, K> item);
    int Hash_search(T t);
    void Hash_delete(T t, K k);
    void Hash_print();
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
    delete tbl; 
}

template<class T, class K>
inline int HashTbls<T, K>::Hash(K k, int I)
{
    return (k + I) % size;
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
            tbl[j].flag = static_cast<state>(1); // casting
            return;
        }
        if (tbl[j].key == static_cast<state>(2))
        {
            tbl[j] = item;
            return;
        }
    }
    throw "OVERFLOW!";
}

template<class T, class K>
inline int HashTbls<T, K>::Hash_search(T t)
{
    int i = 0;
    int j = 0;
    while (i < size || tbl[j].flag != NULL)
    {
        j = Hash(t, i);
        if (tbl[j].key == t)
        {
            return j;
        }
        i = i + 1;
        return -1;
    }
}

template<class T, class K>
inline void HashTbls<T, K>::Hash_delete(T t, K k)
{
    int i = Hash_search(k);
    tbl[i].flag = static_cast<state>(2);
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
inline int HashTbls<T,K>::isPrime(int num)//return the closer prime number to size of arrey
{
#pragma region MyRegion

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0)
        {
            isPrime(++num);
        }
    }
    return num;
#pragma endregion
}

template<class T, class k>
inline int H1(class K k)//asistenting hash function
{
    return k * size;
}
template<class T, class k>
inline int H2(class K k)// hash function
{
    return hush(k);
}




