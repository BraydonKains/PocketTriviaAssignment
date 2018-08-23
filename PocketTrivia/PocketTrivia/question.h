#pragma once
#include <string>
#include <vector>
#include "option.h"
#include "enums.h"

class Question {
public:
	std::vector<Option*> options;

	Question(std::string _a, std::string _b, std::string _c, std::string _d, Answer _correct);
};