#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <vector>
#include <string>

#include "question_screen.h"
#include "cursor.h"

using std::vector;
using std::string;

QuestionScreen::QuestionScreen(Question* _question) {
	background = "unit_screen.bmp";
	points = 0;
	question = _question;
	menu.activate(question->options);
}

void QuestionScreen::run(ALLEGRO_FONT* font) {
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_draw_text(font, al_map_rgb(255, 255, 255), 240, 100, ALLEGRO_ALIGN_CENTER, question->question_text.c_str());
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
				al_draw_text(font, al_map_rgb(255, 255, 255), 240, 400, ALLEGRO_ALIGN_CENTER, get_result_text().c_str());
				al_draw_text(font, al_map_rgb(255, 255, 255), 240, 410, ALLEGRO_ALIGN_CENTER, "Press any key to continue.");
				al_flip_display();
				while (!exit_screen) {
					al_wait_for_event(event_queue, &ev);
					if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
						exit_screen = true;
					}
				}
				cont();
				break;
			case ALLEGRO_KEY_BACKSPACE:
				back();
				exit_screen = true;
				break;
			}
			al_draw_text(font, al_map_rgb(255, 255, 255), 240, 100, ALLEGRO_ALIGN_CENTER, question->question_text.c_str());
			al_flip_display();
		}
	}
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
}

void QuestionScreen::back() {
	next_state = Start;
}

void QuestionScreen::cont() {
	return;
}

string QuestionScreen::get_result_text() {
	string result_text;
	if (menu.get_selected()->correct) {
		points = 50;
		return "Correct!";
	}
	else {
		return "Incorrect! The correct answer is " + question->get_correct_option()->text;
	}

}