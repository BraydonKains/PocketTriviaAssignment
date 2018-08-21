#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "question.h"
#include "chapter.h"
#include "enums.h"

using std::vector;
using std::ifstream;
using std::istringstream;

Chapter::Chapter(string _name, string _question_set) {
	chapter_name = _name;
	question_set = _question_set;
}

Question* parseQuestion(string questionLine) {
	std::string questionText;
	std::string answers[4];
	Answer correct;
	
	istringstream qStream(questionLine);
	std::string element;
	std::string elements[3];
	int i = 0;
	while (getline(qStream, element, '|')) {
		elements[i++] = element;
	}

	questionText = elements[0];

	istringstream aStream(elements[1]);
	i = 0;
	while (getline(aStream, element, ';')) {
		answers[i++] = element;
	}
	
	std::string correctStr = elements[2];
	if (correctStr.compare("A") == 0) {
		correct = A;
	}
	else if (correctStr.compare("B") == 0) {
		correct = B;
	}
	else if (correctStr.compare("C") == 0) {
		correct = C;
	}
	else {
		correct = D;
	}
	
	return new Question(answers[0], answers[1], answers[2], answers[3], correct);
}

void Chapter::load() {
	string line;
	ifstream questionFile (this->question_set);
	
	if (questionFile.is_open()) {
		while (getline(questionFile, line)) {
			this->questions.push_back(parseQuestion(line));
		}
	}

	questionFile.close();
}