#pragma once
#include <string>
#include <vector>
#include "chapter.h"

class Unit {
public:
	std::vector<Chapter*> chapters;

	Unit(std::string name);

	MenuItem<Unit> to_menu_item();
};