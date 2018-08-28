#pragma once
enum Answer {
	A,
	B,
	C,
	D
};

enum State {
	Start,
	UnitSelect,
	ChapterSelect,
	AskQuestionNormal,
	AskQuestionAllChapters,
	AskQuestionAllUnits,
	FinalScore,
	Exit
};