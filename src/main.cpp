#include <iostream>
#include "observer.h"
#include "condition.h"
#include "rules.h"
#include "file.h"

using namespace std;

int main(void)
{
    vector<Condition> conditions;
    vector<Rule> rules;
    rules.push_back(Rule(conditions, "echo '%filename%' >> /tmp/pigeonhol"));

    Observer* obs = new Observer();
    obs->observe("/home/alexis/Downloads", rules);

    /*
	// Config* config = new Config("/path/to/config");
	// for each config entry related to paths, add it
        obs->observe("/home/alexis/Images");
	obs->stop("/home/alexis/Downloads");
    */
    return 1;
}
