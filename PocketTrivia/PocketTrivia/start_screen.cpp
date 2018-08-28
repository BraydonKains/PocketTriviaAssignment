#include <vector>
#include <string>
#include "start_screen.h"
#include "cursor.h"

using std::vector;
using std::string;

StartScreen::StartScreen() {
	background = "start_screen.bmp";

	vector<string> menu_options;
	menu_options.push_back("Start");
	menu_options.push_back("Quit");
	menu.activate(menu_options);
}

void StartScreen::run(ALLEGRO_DISPLAY * display, ALLEGRO_FONT * font) {
	int v_offset = 50;

	for (int i = 0; i < menu.options.size(); i++) {
		al_draw_text(font, al_map_rgb(255, 255, 255), 400, 300 + v_offset, ALLEGRO_ALIGN_CENTER, menu.options.at(i).c_str());
	}

	al_flip_display();

	while (1) {
		int x;
	}
}

void StartScreen::back() {
	next_state = Exit;
}

void StartScreen::cont() {
	next_state = UnitSelect;
}
