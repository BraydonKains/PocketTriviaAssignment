#include <vector>
#include "cursor.h"

using std::vector;

template<class T>
Cursor<T>::Cursor()
{
	active = false;
}

template<class T>
Cursor<T>::activate(std::vector<T> _options)
{
	options = _options;
	selected = 0;
	active = true;
}

template<class T>
Cursor<T>::deactivate()
{
	active = false;
}
