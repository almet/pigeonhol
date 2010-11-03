#include <iostream>
#include "observer.h"
#include "condition.h"
#include "rules.h"
#include "file.h"

using namespace std;

int main(void)
{
    cout << "loading rules" << endl;
    
    vector<Condition> conditions;

    // plugins.push_back();
    Rule rule = Rule(conditions, "echo %filename% > /tmp/pigeonhol");
    rule.run(File("superfile"));

    Observer* obs = new Observer();
    obs->observe("/home/alexis/Downloads");

    /*

	// Config* config = new Config("/path/to/config");
	// for each config entry related to paths, add it
    obs->observe("/home/alexis/Images");
	obs->stop("/home/alexis/Downloads");
    */
    return 1;
}
