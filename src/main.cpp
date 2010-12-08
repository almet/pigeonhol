#include <iostream>
#include "observer.h"
#include "condition.h"
#include "rules.h"
#include "file.h"

using namespace std;

int main(void)
{
    // FIXME: replace with the use of a config parser
    vector<Condition*> conditions;
    conditions.push_back(new FilenameEquals("test.zip"));

    vector<Rule*> rules;
    rules.push_back(new Rule(conditions, "echo '%filename%' >> /tmp/pigeonhol"));

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
