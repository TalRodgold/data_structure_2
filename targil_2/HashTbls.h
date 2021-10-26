#pragma once
#include <iostream>
#include "Item.h"
#include <list>
template<class T, class k>
class HashTbls
{
	int size;
	Item<T, K>** tbl;//t is item k is key

public:
	HashTbls(int number);
	~HashTbls();
	virtual int H1() = 0;
	virtual void H2() = 0;
};


