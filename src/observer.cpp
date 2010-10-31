#include <iostream>
#include "observer.h"

using namespace std;

Observer::Observer(const char* path){
   this->path = path;
}

void Observer::observe(){
    cout << "it's a test";
}
