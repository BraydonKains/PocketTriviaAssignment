#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <vector>

#include "unit_screen.h"
#include "cursor.h"

using std::vector;

UnitScreen::UnitScreen(vector<Unit*> _units) {
	background = "unit_screen.bmp";

	menu.activate(_units);
	all = false;
}

void UnitScreen::run(ALLEGRO_FONT* font) {
	menu.draw(100, 100, 5, font);
}

void UnitScreen::back() {
	next_state = Start;
}

void UnitScreen::cont() {
	if (all) {
		next_state = AskQuestionAllUnits;
	}
	else {
		next_state = ChapterSelect;
	}
}
