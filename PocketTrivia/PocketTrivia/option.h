#pragma once
#include <string>
#include <vector>
#include "enums.h"
#include "menu_item.h"

class Option : public MenuItem {
public:
	Answer answer;
	std::string text;
	bool correct;

	Option(Answer _answer, std::string _text, bool correct);
};