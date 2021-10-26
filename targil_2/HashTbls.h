#pragma once
#include <iostream>
#include "Item.h"
#include <list>
template<class T, class k>
class HashTbls
{
	int size;
	Item<T, K>** tbl;//T is item K is key

public:
	HashTbls(int number);//constructor
	~HashTbls();//distructor
    virtual int H1();// = 0;//asistenting hash function
    virtual int H2();// = 0;// hash function
    int Hash(class K, int I=0);
    void Hash_insert(class T, class K);
    int Hash_search(class T, class K);
};
template <class T, class K>
class Item
{
public:
    T data;
    K key;
    state flag;
    Item() {}//defult constructor
    Item(T d, K k, state f) { data = d; key = k; flag = f; }//constructor 
};
template<class T, class k>
HashTbls<T, k>::HashTbls(int number)//constructor
{
#pragma region MyRegion
    int size = isPrime(number);
    tbl = new Item<T, K>*[size];
#pragma endregion

}

template<class T, class k>
HashTbls<T, k>::~HashTbls()//distructor
{
#pragma region MyRegion
    for (int i = 0; i < size; i++)
    {
        delete* tbl[i];
    }
    delete tbl;
#pragma endregion  
}

template<class T, class k>
int Hash_search(T, K)//return the index of cell of key k 
{
#pragma region MyRegion
    int i = 0;
    int j = 0;
    while (i < m or tbl[j] != NULL)
    {
        j = hash2(k, i);
        if (tbl[j] == k)
        {
            return j;
        }
        i = i + 1;
        return NULL;
    }
#pragma endregion

}

template<class T, class k>
 int Hash(K, int I)//return hush value with known i
{
     return (h1(k) + i) % size;
}


//template<class T, class k>
//int HashTbls<T, k>::H1(class K k)
//{
//    return k % size;
//}
template<class T, class k>
int H1(class K k)//asistenting hash function
{
    return k * size;
}
template<class T, class k>
int H2(class K k)// hash function
{
    return hush(k);
}

template<class T, class k>
void Hash_insert(T, K)//insret a item by key value 
{
#pragma region MyRegion
    int i = 0;
    int j = 0;
    while (i < m)
    {
        j = hash2(k, i);
        if (tbl[j] == NULL )|| tbl[j] == NULL)
        {
            tbl[j] = k;
            return j;
        }
        if (*(tbl[j]).key == -1)
        {
            delete tbl[j];
            tbl[j] = new  Item<T,K>;
            tbl[j] = k;
            return j;
        }
        else
        {
            i = i + 1;
        }
        throw "ERROR";
    }
#pragma endregion
}






int isPrime(int num)//return the closer prime number to size of arrey
{
#pragma region MyRegion

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0)
        {
            isPrime(num++);
        }
    }
    return num;
#pragma endregion
}



