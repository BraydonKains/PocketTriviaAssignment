#include <map>
#include <string>
#include "enums.h"
#include "question.h"

using namespace std;

Question::Question(string a, string b, string c, string d, Answer _correct) {
	options.insert(pair <Answer, string> (Answer::A, a));
	options.insert(pair <Answer, string>(Answer::B, b));
	options.insert(pair <Answer, string>(Answer::C, c));
	options.insert(pair <Answer, string>(Answer::D, d));
	correct = _correct;
}

bool Question::guessAnswer(Answer _guess) {
	guess = _guess;
	if (guess == correct) {
		return true;
	}
	return false;
}