#include <iostream>
#include "observer.h"
#include "condition.h"
#include "rules.h"
#include "file.h"

using namespace std;

int main(void)
{
    vector<Condition*> conditions;
    vector<Rule*> rules;

    // FIXME: replace with the use of a config parser.
    conditions.push_back(new FileExtensionIs("zip"));
    rules.push_back(new Rule(conditions, "sleep 1 && unzip '%filename%' -d extracted >pigeonhol.log"));

    Observer* obs = new Observer();
    obs->observe("observed", rules); // this value should be read from a config file too.

    return 1;
}
