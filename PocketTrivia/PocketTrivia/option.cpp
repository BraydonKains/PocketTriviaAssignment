#include <string>
#include <vector>
#include "option.h"
#include "enums.h"

using std::string;
using std::vector;

Option::Option(Answer _answer, std::string _text, bool correct)
{
	answer = _answer;
	text = _text;
}
