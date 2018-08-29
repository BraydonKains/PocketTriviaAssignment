#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <string>
#include <sstream>

#include "result_screen.h"
#include "cursor.h"

using std::vector;
using std::string;
using std::ostringstream;

ResultScreen::ResultScreen(int _score) {
	background = "unit_screen.bmp";
	score = _score;
}

void ResultScreen::run(ALLEGRO_FONT* font) {
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	ostringstream result_message;
	result_message << "Final Score: " << score;
	al_draw_text(font, al_map_rgb(255, 255, 255), 240, 100, ALLEGRO_ALIGN_CENTER, result_message.str().c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 240, 110, ALLEGRO_ALIGN_CENTER, "Press backspace to quit or any key to continue.");
	al_flip_display();
	bool exit_screen = false;
	while (!exit_screen) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_BACKSPACE:
				back();
				exit_screen = true;
				break;
			default:
				cont();
				exit_screen = true;
				break;
			}
		}
	}
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
}

void ResultScreen::back() {
	next_state = Exit;
}

void ResultScreen::cont() {
	next_state = Start;
}