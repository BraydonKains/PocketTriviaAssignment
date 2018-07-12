#include <iostream>
#include <map>
#include <string>
#include <cstdint>
#include <stdint.h>
#include "enums.h"

using namespace std;

class Question {
public:
	Answer correct;
	map <Answer, string> options;

	Question(string a, string b, string c, string d) {
		options.insert(pair <Answer, string> (Answer::A, a));
		options.insert(pair <Answer, string>(Answer::B, b));
		options.insert(pair <Answer, string>(Answer::C, c));
		options.insert(pair <Answer, string>(Answer::D, d));
	}

	bool guessAnswer(Answer answer) {
		if (answer == correct) {
			return true;
		}
		return false;
	}
};