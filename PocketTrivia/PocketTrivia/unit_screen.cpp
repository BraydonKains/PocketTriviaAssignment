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

void UnitScreen::run(ALLEGRO_DISPLAY* display, ALLEGRO_FONT* font) {
	int v_offset = 50;
	
	for (int i = 0; i < menu.options.size(); i++) {
		al_draw_text(font, al_map_rgb(255, 255, 255), 400, 300 + v_offset, ALLEGRO_ALIGN_CENTER, menu.options.at(i)->name.c_str());
	}

	al_flip_display();
}

void UnitScreen::back() {
	next_state = Start;
}

void UnitScreen::cont() {
	if (all) {
		next_state = AskQuestionAllUnits;
	}
	else {
		selected = menu.options.at(menu.selected);
		next_state = ChapterSelect;
	}
}
