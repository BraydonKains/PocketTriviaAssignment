#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <vector>
#include <string>

#include "cursor.h"
#include "unit.h"
#include "chapter.h"
#include "option.h"

using std::string;
using std::vector;

template<class T>
Cursor<T>::Cursor()
{
	active = false;
}

template<class T>
void Cursor<T>::activate(std::vector<T> _items)
{
	items = _items;
	selected = 0;
	active = true;
}

template<class T>
void Cursor<T>::deactivate()
{
	active = false;
}

template<class T>
void Cursor<T>::display(float _x_start, float _y_start, float _y_offset, ALLEGRO_FONT* font) {
	vector<string> items_text = get_item_strings();
	
	x_start = _x_start;
	y_start = _y_start;
	y_offset = _y_offset;

	for (int i = 0; i < items_text.size(); i++) {
		al_draw_text(font, al_map_rgb(255, 255, 255), x_start, y_start + (y_offset*i), ALLEGRO_ALIGN_LEFT, items_text.at(i).c_str());
	}

	update_selector();
}

template<class T>
void Cursor<T>::update_selector() {
	ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
	float offset = y_offset*selected;
	al_draw_filled_triangle(x_start-5, y_start+offset, x_start-5, y_start+4+offset, x_start-1, y_start+2+offset, white);
}

template Cursor<string>::Cursor();
template void Cursor<string>::activate(std::vector<string> _options);
template void Cursor<string>::deactivate();
template void Cursor<string>::display(float x_start, float y_start, float _y_offset, ALLEGRO_FONT* font);
vector<string> Cursor<string>::get_item_strings() {
	return items;
}

template Cursor<Unit*>::Cursor();
template void Cursor<Unit*>::activate(std::vector<Unit*> _options);
template void Cursor<Unit*>::deactivate();
template void Cursor<Unit*>::display(float x_start, float y_start, float _y_offset, ALLEGRO_FONT* font);
vector<string> Cursor<Unit*>::get_item_strings() {
	vector<string> items_text;
	for (int i = 0; i < items.size(); i++) {
		items_text.push_back(items.at(i)->name);
	}
	return items_text;
}

template Cursor<Chapter*>::Cursor();
template void Cursor<Chapter*>::activate(std::vector<Chapter*> _options);
template void Cursor<Chapter*>::deactivate();
template void Cursor<Chapter*>::display(float x_start, float y_start, float _y_offset, ALLEGRO_FONT* font);
vector<string> Cursor<Chapter*>::get_item_strings() {
	vector<string> items_text;
	for (int i = 0; i < items.size(); i++) {
		items_text.push_back(items.at(i)->name);
	}
	return items_text;
}

template Cursor<Option*>::Cursor();
template void Cursor<Option*>::activate(std::vector<Option*> _options);
template void Cursor<Option*>::deactivate();
template void Cursor<Option*>::display(float x_start, float y_start, float _y_offset, ALLEGRO_FONT* font);
vector<string> Cursor<Option*>::get_item_strings() {
	vector<string> items_text;
	for (int i = 0; i < items.size(); i++) {
		items_text.push_back(items.at(i)->text);
	}
	return items_text;
}
