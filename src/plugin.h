#ifndef __PLUGIN_H
#define __PLUGIN_H

#include <vector>
#include <string>
#include <boost/foreach.hpp>
#define foreach BOOST_FOREACH

#include "condition.h"
#include "file.h"
#include "utils.h"

using namespace std;

class Plugin
{
   vector<Condition> _conditions;
   string _script;

public:
    Plugin(vector<Condition>, string);
    void run(File);
};
#endif
