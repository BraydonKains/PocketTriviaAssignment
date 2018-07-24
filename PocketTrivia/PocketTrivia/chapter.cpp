#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "question.h"
#include "chapter.h"
#include "enums.h"

using std::vector;
using std::ifstream;
using std::string;
using std::istringstream;

Chapter::Chapter(int _id, string _questionSet) {
	id = _id;
	questionSet = _questionSet;
}

Question* parseQuestion(string questionLine) {
	string questionText;
	string answers[4];
	Answer correct;
	
	istringstream qStream(questionLine);
	string element;
	string elements[3];
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
	
	if (element[2] == "A") {
		correct = A;
	}
	else if (element[2] == "B") {
		correct = B;
	}
	else if (element[2] == "C") {
		correct = C;
	}
	else {
		correct = D;
	}
	
	return new Question(answers[0], answers[1], answers[2], answers[3]);
}

vector<Question> Chapter::load() {
	vector<Question> questions;

	string line;
	ifstream questionFile (this->questionSet);
	
	if (questionFile.is_open()) {
		while (getline(questionFile, line)) {
			
		}
	}
}