#include <string>
#include <vector>
#include "chapter.h"
#include "unit.h"

using std::string;
using std::vector;

Unit::Unit(string _name) {
	name = _name;
}

void Unit::set_chapters(vector<Chapter*> _chapters) {
	chapters = _chapters;
}
