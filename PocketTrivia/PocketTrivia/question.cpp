#include <map>
#include <string>
#include "enums.h"
#include "question.h"
#include "option.h"

using namespace std;

Question::Question(string _a, string _b, string _c, string _d, Answer _correct) {
	options.push_back(new Option(A, _a, _correct == A));
	options.push_back(new Option(B, _b, _correct == B));
	options.push_back(new Option(C, _c, _correct == C));
	options.push_back(new Option(D, _d, _correct == D));
}

Option* Question::get_correct_option() {
	for (int i = 0; i < options.size(); i++) {
		if (options.at(i)->correct) {
			return options.at(i);
		}
	}
}
