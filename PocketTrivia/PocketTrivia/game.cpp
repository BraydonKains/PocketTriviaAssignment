#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "game.h"
#include "start_screen.h"
#include "unit_screen.h"

using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

Game::Game() {
	score = 0;
	state = Start;
}

Unit* parse_unit(string line) {
	istringstream unitLine(line);
	string element;
	
	//get unit name
	getline(unitLine, element, '|');
	Unit* unit = new Unit(element);
	
	//get chapters
	getline(unitLine, element, '|');

	string chapter;
	istringstream chapters(element);
	while (getline(chapters, chapter, '?')) {
		string question_set;
		string chapter_name;
		string chapter_element;
		istringstream chapter_stream(chapter);
		//get chapter file
		getline(chapter_stream, chapter_element, ';');
		question_set = chapter_element;
		//get chapter name
		getline(chapter_stream, chapter_element, ';');
		chapter_name = chapter_element;

		unit->chapters.push_back(new Chapter(chapter_name, question_set));
	}

	return unit;
}

void Game::init() {
	//Unit setup
	string line;
	ifstream unitsFile (unit_defs);

	if (unitsFile.is_open()) {
		while (getline(unitsFile, line)) {
			units.push_back(parse_unit(line));
		}
	}
	
	unitsFile.close();	

	font = al_create_builtin_font();
}

void Game::to_state(State next_state) {
	switch (next_state) {
	case Start:
		init();		
	}

	state = next_state;
}

//MOST IMPORTANT FUNCTION SO IT'S AT THE BOTTOM
void Game::run() {
	
	while(state != Exit) {
		switch (state) {
		case Start:
			StartScreen start_screen;
			start_screen.run(font);
			
		}
	}
}