// NAME:  Tal Rodgold  & Avichay Kadosh
// ID:    318162344    & 313317364
// GROUP: Haim Prianti & Efi Naftali
// PROJECT NUMBER: 2
#pragma once
#include <iostream>
using namespace std;

enum state { empty, full, deleted };
template <class T, class K>
class Item
{
public:
	T data;
	K key;
	state flag;
	Item() { flag = state::empty; }
	Item(T d, K k ) { data = d; key = k; }
};

