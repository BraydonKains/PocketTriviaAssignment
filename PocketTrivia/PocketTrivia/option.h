#pragma once
#include <string>
#include <vector>
#include "enums.h"

class Option {
public:
	Answer answer;
	std::string text;
	bool correct;

	Option(Answer _answer, std::string _text, bool correct);
};