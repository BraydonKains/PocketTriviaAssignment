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
#include "chapter_screen.h"
#include "question_screen.h"
#include "result_screen.h"

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
	while (getline(chapters, chapter, ';')) {
		string question_set;
		string chapter_name;
		string chapter_element;
		istringstream chapter_stream(chapter);
		//get chapter file
		getline(chapter_stream, chapter_element, '?');
		question_set = chapter_element;
		//get chapter name
		getline(chapter_stream, chapter_element, '?');
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
		break;
	}

	state = next_state;
}

void Game::reset() {
	score = 0;
	current_unit = nullptr;
	current_chapter = nullptr;
}

//MOST IMPORTANT FUNCTION SO IT'S AT THE BOTTOM
void Game::run() {
	while(state != Exit) {
		if (state == Start) {
			reset();
			StartScreen start_screen;
			start_screen.run(font);
			state = start_screen.next_state;
		}
		else if(state == UnitSelect) {
			UnitScreen unit_screen(units);
			unit_screen.run(font);
			if (unit_screen.next_state == ChapterSelect) {
				current_unit = unit_screen.menu.get_selected();
			}
			state = unit_screen.next_state;
		}
		else if (state == ChapterSelect) {
			ChapterScreen chapter_screen(current_unit);
			chapter_screen.run(font);
			if (chapter_screen.next_state == AskQuestionNormal) {
				current_chapter = chapter_screen.menu.get_selected();
			}
			state = chapter_screen.next_state;
		}
		else if (state == AskQuestionAllUnits) {
			for (int i = 0; i < units.size(); i++) {
				Unit* ask_unit = units.at(i);
				for (int j = 0; j < ask_unit->chapters.size(); j++) {
					Chapter* ask_chapter = ask_unit->chapters.at(j);
					for (int k = 0; k < ask_chapter->questions.size(); k++) {
						QuestionScreen ask_screen(ask_chapter->questions.at(k), ask_unit->name, ask_chapter->name);
						ask_screen.run(font);
						score += ask_screen.points;
					}
				}
			}
			state = FinalScore;
		}
		else if (state == AskQuestionAllChapters) {
			for (int j = 0; j < current_unit->chapters.size(); j++) {
				Chapter* ask_chapter = current_unit->chapters.at(j);
				for (int k = 0; k < ask_chapter->questions.size(); k++) {
					QuestionScreen ask_screen(ask_chapter->questions.at(k), current_unit->name, ask_chapter->name);
					ask_screen.run(font);
					score += ask_screen.points;
				}
			}
			state = FinalScore;
		}
		else if (state == AskQuestionNormal) {
			for (int k = 0; k < current_chapter->questions.size(); k++) {
				QuestionScreen ask_screen(current_chapter->questions.at(k), current_unit->name, current_chapter->name);
				ask_screen.run(font);
				score += ask_screen.points;
			}
			state = FinalScore;
		}
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_flip_display();
		if (state == FinalScore) {
			ResultScreen result_screen(score);
			result_screen.run(font);
			state = result_screen.next_state;
		}
	}
}