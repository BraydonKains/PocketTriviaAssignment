#pragma once
#include <string>

template <class T> 
class MenuItem {
public:
	std::string text;
	T item;

	MenuItem(T _item);
};
