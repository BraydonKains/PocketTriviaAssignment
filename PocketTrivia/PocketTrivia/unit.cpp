#include <string>
#include <vector>
#include "chapter.h"
#include "unit.h"

using std::string;
using std::vector;

Unit::Unit(int _id, string _name, vector<Chapter> _chapters) {
	unit_id = _id;
	unit_name = _name;
	chapters = _chapters;
}