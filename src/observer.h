#ifndef __OBSERVER_H
#define __OBSERVER_H

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "rules.h"

using namespace std;

class Observer {
    vector<string> _paths;
    map<string, bool> _observing;
    void run_rules(vector<Rule*>, string, string);

public:
    Observer();
    void observe(string, vector<Rule*>);
    void stop(string);
};
#endif
