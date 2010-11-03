#ifndef __RULES_H
#define __RULES_H

#include <iostream>
#include <vector>
#include <string>

#include "condition.h"
#include "file.h"
#include "utils.h"

using namespace std;

class Rule
{
   vector<Condition> _conditions;
   string _script;

public:
    Rule(vector<Condition>, string);
    void run(File);
};
#endif
