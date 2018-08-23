#include <vector>
#include "cursor.h"
#include "menu_item.h"

using std::vector;

Cursor::Cursor() {
	selected = 0;
}

void Cursor::set_options(std::vector<MenuItem*> _options){
	options = _options;

	selected = 0;
}
