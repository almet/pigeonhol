#include "file.h"
#include "utils.h"

File::File(string filename){
    this->_name = filename;
}

string File::getName(){
    return this->_name;
}

bool File::matchExtension(string ext){
    return endsWith(this->_name, ext);
}
