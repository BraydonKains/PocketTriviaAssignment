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

Chapter::Chapter(int _id, string _name, string _questionSet) {
	chapter_id = _id;
	chapter_name = _name;
	questionSet = _questionSet;
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

vector <Question*> Chapter::load() {
	vector <Question*> questions;

	string line;
	ifstream questionFile (this->questionSet);
	
	if (questionFile.is_open()) {
		while (getline(questionFile, line)) {
			questions.push_back(parseQuestion(line));
		}
	}
	questionFile.close();

	return questions;
}