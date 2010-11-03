#include <iostream>
#include "observer.h"
#include "condition.h"
#include "plugin.h"
#include "file.h"

using namespace std;

int main(void)
{
    cout << "loading plugin" << endl;
    
    vector<Condition> conditions;

    // plugins.push_back();
    Plugin plug = Plugin(conditions, "echo %filename% > /tmp/pigeonhol");
    plug.run(File("superfile"));

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
