#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
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
	//Allegro elements
	ALLEGRO_FONT* font;

	//Game elements
	State state;

	int score;

	std::vector <Unit*> units;
	Unit* current_unit;

	Chapter* current_chapter;
	
	Game();

	void init();
	void run();

private:
	void reset();
};