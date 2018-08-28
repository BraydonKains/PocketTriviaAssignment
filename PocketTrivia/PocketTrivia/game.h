#pragma once
#include <vector>
#include <string>
#include "unit.h"
#include "chapter.h"
#include "question.h"
#include "cursor.h"
#include "screen.h"

class Game {
public:
	const std::string unit_defs = "units.txt";
	
	State state;

	int score;

	std::vector <Unit*> units;
	Unit* current_unit;

	Chapter* current_chapter;

	Question* current_question;

	Game();

	void init();
	void run();

private:
	void to_state(State next_state);
};