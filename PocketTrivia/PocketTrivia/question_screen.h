#pragma once
#include <vector>
#include <string>

#include "screen.h"
#include "cursor.h"
#include "unit.h"

class QuestionScreen : public Screen {
public:
	Cursor<Option*> menu;

	int points;

	Unit* unit;
	Chapter* chapter;
	Question* question;

	QuestionScreen(Question* _question);

	void run(ALLEGRO_FONT* font);
	void back();
	void cont();

private:
	std::string get_result_text();
};