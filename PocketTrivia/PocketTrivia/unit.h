#pragma once
#include <string>
#include <vector>
#include "chapter.h"

class Unit : public MenuItem {
public:
	std::vector<Chapter*> chapters;

	Unit(std::string name);
};