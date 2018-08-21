#pragma once
#include <vector>
#include <string>
#include "unit.h"

class Game {
public:
	const std::string unit_defs = "units.txt";
		
	int score;

	std::vector <Unit*> units;
	Unit* current_unit;
	Chapter* current_chapter;
	Question* current_question;

	Game();

	void init();
};