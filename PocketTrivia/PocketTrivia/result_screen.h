#pragma once
#include <vector>
#include <string>

#include "screen.h"
#include "cursor.h"
#include "unit.h"

class ResultScreen : public Screen {
public:
	int score;
	
	ResultScreen(int _score);

	void run(ALLEGRO_FONT* font);
	void back();
	void cont();
};