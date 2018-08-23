#pragma once
#include <vector>
#include "menu_item.h"

class Cursor {
public:
	std::vector<MenuItem*> options;
	int selected;

	Cursor();
	void set_options(std::vector<MenuItem*> _options);
};