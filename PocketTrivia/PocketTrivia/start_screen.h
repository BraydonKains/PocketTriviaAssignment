#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <vector>
#include <string>

#include "screen.h"
#include "cursor.h"

class StartScreen : public Screen {
public:
	Cursor<std::string> menu;

	StartScreen();
	
	void run(ALLEGRO_FONT* font);
	void back();
	void cont();
};