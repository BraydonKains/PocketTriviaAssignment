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
			case ALLEGRO_KEY_SPACE:
				all = true;
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
