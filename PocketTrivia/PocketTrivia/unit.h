#pragma once
#include <string>
#include <vector>
#include "chapter.h"

class Unit {
public:
	std::string unit_name;
	std::vector<Chapter*> chapters;

	Unit(std::string name);
};