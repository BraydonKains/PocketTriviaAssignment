#pragma once
#include <string>
#include <vector>
#include "question.h"
using namespace std;
class Chapter {
public:
	int id;
	string questionSet;

	Chapter(int _id, string _questionSet);

	vector <Question*> load();
};