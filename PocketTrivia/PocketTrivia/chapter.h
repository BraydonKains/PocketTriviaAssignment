#pragma once
#include <string>
#include <vector>
#include "question.h"
#include "menu_item.h"

class Chapter {
public:
	std::string question_set;
	std::vector<Question*> questions;
	
	Chapter(std::string name, std::string _question_set);

	void load();
	MenuItem<Chapter> to_menu_item();
};