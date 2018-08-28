#pragma once
#include <vector>

template <class T>
class Cursor {
public:
	std::vector<T> items;
	int selected;
	bool active;

	Cursor();

	void activate(std::vector<T> _items);
	void deactivate();
	void display(float _x_start, float _y_start, float _y_offset, ALLEGRO_FONT* font);

private:
	float x_start;
	float y_start;
	int y_offset;

	std::vector<std::string> get_item_strings();
	void update_selector();
};