#pragma once
#include <string>
#include <map>
#include "enums.h"

using std::string;
using std::map;
using std::pair;

using namespace std;

class Question {
public:
	Answer guess;
	Answer correct;
	map <Answer, string> options;

	Question(string a, string b, string c, string d, Answer _correct);

	bool guessAnswer(Answer _guess);
};