#pragma once
#include <string>
#include <vector>
#include "question.h"

class Chapter {
public:
	int id;
	string questionSet;

	Chapter(int _id, string _questionSet);

	vector<Question> load();
};