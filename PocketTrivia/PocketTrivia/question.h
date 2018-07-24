#pragma once
#include <string>
#include <map>
#include "enums.h"

using std::string;
using std::map;
using std::pair;

class Question {
public:
	Answer correct;
	map <Answer, string> options;

	Question(string a, string b, string c, string d);

	bool guessAnswer(Answer answer);
};