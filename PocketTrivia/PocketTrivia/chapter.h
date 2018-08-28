#pragma once
#include <string>
#include <vector>
#include "question.h"

class Chapter {
public:
	std::string name;
	std::string question_set;
	std::vector<Question*> questions;
	
	Chapter(std::string name, std::string _question_set);

	void load();
};