#pragma once
#include <vector>
#include <string>
#include "unit.h"
#include "chapter.h"
#include "question.h"
#include "cursor.h"


class Game {
public:
	const std::string unit_defs = "units.txt";
	
	State state;

	int score;

	std::vector <Unit*> units;
	Unit* current_unit;
	Cursor<Unit*> unit_cursor;

	Chapter* current_chapter;
	Cursor<Chapter*> chapter_cursor;
	
	Question* current_question;

	Game();

	void init();
	void run();

private:
	void to_state(State next_state);
	void set_unit_cursor();
	void set_chapter_cursor();
	void set_option_cursor();
};