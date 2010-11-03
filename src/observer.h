#ifndef __OBSERVER_H
#define __OBSERVER_H

#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Observer {
    vector<string> _paths;
    map<string, bool> _observing;

public:
    Observer();
    void observe(string);
    bool stop(string);
};
#endif
