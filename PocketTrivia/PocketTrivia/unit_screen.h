#pragma once
#include <vector>

#include "screen.h"
#include "cursor.h"
#include "unit.h"

class UnitScreen : public Screen {
public:
	Cursor<Unit*> menu;

	bool all;
	Unit* selected;

	UnitScreen(std::vector<Unit*> _units);

	void run(ALLEGRO_FONT* font);
	void back();
	void cont();
};