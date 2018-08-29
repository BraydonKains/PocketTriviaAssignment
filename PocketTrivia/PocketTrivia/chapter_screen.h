#pragma once
#include <vector>

#include "screen.h"
#include "cursor.h"
#include "unit.h"

class ChapterScreen : public Screen {
public:
	Cursor<Chapter*> menu;

	bool all;
	Unit* unit;
	Chapter* selected;

	ChapterScreen(Unit* _unit);

	void run(ALLEGRO_FONT* font);
	void back();
	void cont();
};