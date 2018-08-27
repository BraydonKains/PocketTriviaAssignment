#pragma once
#include <allegro5/allegro.h>
#include <string>

class Screen {
public:
	std::string background;

	virtual void start(ALLEGRO_DISPLAY* display) = 0;
	virtual void destroy(ALLEGRO_DISPLAY* display) = 0;
};