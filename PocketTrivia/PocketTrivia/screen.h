#pragma once
#include <allegro5/allegro.h>
#include <string>

#include "enums.h"

class Screen {
public:
	State next_state;

	std::string background;

	virtual void run(ALLEGRO_DISPLAY* display, ALLEGRO_FONT* font) = 0;
	virtual void back() = 0;
	virtual void cont() = 0;
};