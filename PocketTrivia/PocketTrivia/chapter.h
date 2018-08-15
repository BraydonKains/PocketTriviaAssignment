#pragma once
#include <string>
#include <vector>
#include "question.h"

class Chapter {
public:
	int chapter_id;
	std::string chapter_name;
	std::string questionSet;
	
	Chapter(int _id, std::string name, ::string _questionSet);

	std::vector<Question*> load();
};