#include "observer.h"
#include "inotify-cxx.h"

Observer::Observer(){
    cout << "creating the observer" << endl;
}

void Observer::observe(string path, vector<Rule> rules){
    this->_observing[path] = true;
    try {
        Inotify notify;
 
        InotifyWatch watch(path, IN_CREATE);
        notify.Add(watch);
		cout << "Start observing for changes in " << path << endl;
 
        while (this->_observing[path]) {
            notify.WaitForEvents();
 
            size_t count = notify.GetEventCount();
            while (count > 0) {
                InotifyEvent event;
                bool got_event = notify.GetEvent(&event);
 
                if (got_event) {
                    string mask_str;
                    event.DumpTypes(mask_str);
 
                    string filename = event.GetName();
                    this->run_rules(rules, path + '/' + filename, mask_str); 
                }
 
                count--;
            }
        }
     } catch (InotifyException &e) {
         cerr << "Inotify exception occured: " << e.GetMessage() << endl;
     } catch (exception &e) {
         cerr << "STL exception occured: " << e.what() << endl;
     } catch (...) {
         cerr << "unknown exception occured" << endl;
     }
}

void Observer::run_rules(vector<Rule> rules, string filename, string masks){
    // FIXME consider we can have directories too here (basically we just want to remove them)
    File file = File(filename);

    vector<Rule>::const_iterator rule;
    for(rule = rules.begin(); rule != rules.end(); ++rule ){	
        rule->run(file);
    }
}

bool Observer::stop(string path){
    cout << "stoping";
    return true;
}
