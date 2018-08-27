#pragma once
#include <vector>

template <class T>
class Cursor {
public:
	std::vector<T> options;
	int selected;
	bool active;

	Cursor();

	activate(std::vector<T> options);
	deactivate();
};