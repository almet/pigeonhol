#include "file.h"

File::File(string filename){
    this->_name = filename;
}

string File::getName(){
    return this->_name;
}
