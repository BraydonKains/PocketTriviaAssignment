#pragma once
#include <string>
#include <vector>
#include "chapter.h"

class Unit {
public:
	int unit_id;
	std::string unit_name;
	std::vector<Chapter> chapters;

	Unit(int _id, string name, std::vector<Chapter> _chapters);
};