#include <allegro5/allegro.h>
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
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	menu.draw(320.0, 240.0, 20.0, font);
	al_flip_display();
	bool exit_screen = false;
	while (!exit_screen) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				menu.up();
				break;
			case ALLEGRO_KEY_DOWN:
				menu.down();
				break;
			case ALLEGRO_KEY_ENTER:
				cont();
				exit_screen = true;
				break;
			case ALLEGRO_KEY_BACKSPACE:
				back();
				exit_screen = true;
				break;
			}
		}
	}
	al_clear_to_color(al_map_rgb(0, 0, 0));
}

void StartScreen::back() {
	next_state = Exit;
}

void StartScreen::cont() {
	if (menu.get_selected() == "Start") {
		next_state = UnitSelect;
	}
	else {
		next_state = Exit;
	}
}
