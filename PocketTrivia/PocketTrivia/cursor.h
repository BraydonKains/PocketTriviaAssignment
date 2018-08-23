#pragma once
#include <vector>
#include "menu_item.h"

class Cursor {
public:
	std::vector<MenuItem> options;

	Cursor(std::vector<MenuItem> _options);
};