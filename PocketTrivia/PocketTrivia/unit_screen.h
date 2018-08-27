#pragma once
#include <allegro5/allegro.h>
#include "screen.h"
#include "cursor.h"
#include "unit.h"

class UnitScreen : public Screen {
public:
	Cursor<Unit*> unit_cursor;

	UnitScreen();
};