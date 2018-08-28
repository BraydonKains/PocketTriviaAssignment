#pragma once
#include <string>
#include <vector>
#include "chapter.h"

class Unit {
public:
	std::string name;
	std::vector<Chapter*> chapters;

	Unit(std::string _name);

	void set_chapters(std::vector<Chapter*> _chapters);
};