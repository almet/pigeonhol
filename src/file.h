#ifndef __FILE_H
#define __FILE_H

#include <string>

using namespace std;

class File {
    string _name;
public:
	File(string);
	string getName();
};
#endif
