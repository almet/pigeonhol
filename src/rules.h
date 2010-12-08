#ifndef __RULES_H
#define __RULES_H

#include <iostream>
#include <vector>
#include <string>

#include "condition.h"
#include "file.h"

using namespace std;

class Rule
{
   vector<Condition> _conditions;
   string _script;

public:
    /**
     * A rule contains a list of conditions and the name of the script to call
     * if all the conditons are met
     */
    Rule(vector<Condition>, string);

    /**
     * When processing the rule, it will check that all the conditions are met,
     * and if so, will call the script
     *
     * @param File file: the file to check against the conditions.
     * @return void
     */
    void process(File) const;
};
#endif
