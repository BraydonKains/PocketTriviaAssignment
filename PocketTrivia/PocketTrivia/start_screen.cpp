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

void StartScreen::run(ALLEGRO_FONT * font) {
	menu.display(320.0, 240.0, 20.0, font);
	al_flip_display();
	while (1) {}
}

void StartScreen::back() {
	next_state = Exit;
}

void StartScreen::cont() {
	next_state = UnitSelect;
}
