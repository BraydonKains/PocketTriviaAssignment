#include <map>
#include <string>
#include "enums.h"
#include "question.h"

using namespace std;

Question::Question(string a, string b, string c, string d) {
	options.insert(pair <Answer, string> (Answer::A, a));
	options.insert(pair <Answer, string>(Answer::B, b));
	options.insert(pair <Answer, string>(Answer::C, c));
	options.insert(pair <Answer, string>(Answer::D, d));
}

bool Question::guessAnswer(Answer answer) {
	if (answer == correct) {
		return true;
	}
	return false;
}