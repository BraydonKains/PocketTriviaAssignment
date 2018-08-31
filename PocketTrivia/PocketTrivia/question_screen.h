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

	std::string unit_name;
	std::string chapter_name;
	Question* question;

	QuestionScreen(Question* _question, std::string _unit_name, std::string _chapter_name);

	void run(ALLEGRO_FONT* font);
	void back();
	void cont();

private:
	std::string get_result_text();
};