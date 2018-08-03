#include <vector>  
#include <iostream> 
#include "question.h"
#include "chapter.h"
#include "enums.h"

int x()
{
	Chapter* one = new Chapter(1, "chapter_one.txt");

	vector <Question*> questions = one->load();

	for (int i = 0; i < questions.size(); i++) {
		Question* current = questions.at(i);
		cout << current->options[A] << endl;
	}

	int x;
	cin >> x;

	return 0;
}