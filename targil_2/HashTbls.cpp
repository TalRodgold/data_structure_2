#include "HashTbls.h"
#include "Item.h"
#include <iostream>
using namespace std;
template<class T, class k>
HashTbls<T, k>::HashTbls(int number)
{ 
    int size = isPrime(number);  
    tbl = new Item<T, K>*[size];
}

template<class T, class k>
HashTbls<T, k>::~HashTbls()
{
    for (int i = 0; i < size; i++)
    {
        delete *tbl[i];
    }
}

//template<class T, class k>
//int HashTbls<T, k>::H1(class K k)
//{
//    return k % size;
//}


int isPrime(int num) 
{
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) 
        {
            isPrime(num++);
        }
    }
    return num;
}
