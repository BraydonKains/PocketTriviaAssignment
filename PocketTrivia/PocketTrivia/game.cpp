#include <string>
#include <fstream>
#include <sstream>

#include "game.h"

using std::ifstream;
using std::istringstream;
using std::string;

Game::Game() {
	score = 0;
}

Unit* parseUnit(string line) {
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
	string line;
	ifstream unitsFile (this->unit_defs);

	if (unitsFile.is_open()) {
		while (getline(unitsFile, line)) {
			this->units.push_back(parseUnit(line));
		}
	}
	
	unitsFile.close();
}