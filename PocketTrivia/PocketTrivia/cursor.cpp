#include <vector>

#include "cursor.h"
#include "menu_item.h"

using std::vector;

Cursor::Cursor(vector<MenuItem> _options) {
	options = _options;
}