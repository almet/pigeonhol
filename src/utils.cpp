#include "utils.h"

/**
 * Replace all `find` occurences by `replace` in the given 
 * `text`, and return a new string.
 *
 * @param string input
 * @param string find
 * @param string replace
 * @return string
 */ 
string findAndReplace(string input, string find, string replace) { 
    size_t pos = 0; 
    string text(input); // copy input into text

    if( find.length() == 0 ) {
	return text;
    }

    for( ;(pos = text.find(find, pos)) != string::npos; ) {
	text.replace(pos, find.length(), replace);
	pos += replace.length();
    }
    return text;
}


bool endsWith(std::string const &fullString, std::string const &ending)
{
    if (fullString.length() > ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

