#pragma once
#include <vector>

template <class T>
class Cursor {
public:
	std::vector<T> options;
	int selected;
	bool active;

	Cursor();

	void activate(std::vector<T> options);
	void deactivate();
};