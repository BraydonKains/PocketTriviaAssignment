#pragma once
#include <vector>
#include <string>
#include "unit.h"
#include "cursor.h"

class Game {
public:
	const std::string unit_defs = "units.txt";
		
	int score;

	std::vector <Unit*> units;
	Unit* current_unit;
	Chapter* current_chapter;
	Question* current_question;
	Cursor* menu_cursor;

	Game();

	void init();
	void set_unit_menu();
	void set_chapter_menu();
	void set_question_menu();
};