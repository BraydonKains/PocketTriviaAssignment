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
void Cursor<T>::activate(std::vector<T> _options)
{
	options = _options;
	selected = 0;
	active = true;
}

template<class T>
void Cursor<T>::deactivate()
{
	active = false;
}

template Cursor<string>::Cursor();
template void Cursor<string>::activate(std::vector<string> _options);
template void Cursor<string>::deactivate();

template Cursor<Unit*>::Cursor();
template void Cursor<Unit*>::activate(std::vector<Unit*> _options);
template void Cursor<Unit*>::deactivate();

template Cursor<Chapter*>::Cursor();
template void Cursor<Chapter*>::activate(std::vector<Chapter*> _options);
template void Cursor<Chapter*>::deactivate();

template Cursor<Option*>::Cursor();
template void Cursor<Option*>::activate(std::vector<Option*> _options);
template void Cursor<Option*>::deactivate();