#include "observer.h"
#include "inotify-cxx.h"

/**
 * Create the observer
 */
Observer::Observer(){
    cout << "creating the observer" << endl;
}

/**
 * Tell the observer to watch the given folder. 
 * Then, the observer will process all the rules
 *
 * @param string path the path to be watched
 * @param vector<Rule> the list of rules to be checked
 */
void Observer::observe(string path, vector<Rule*> rules){
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

/**
 * This method will be called if modifications have been catched on existing
 * files.
 *
 * For now, the rules will be only checked if the file is a new one.
 * FIXME: consider the other use cases (modification, suppression and so on
 *
 * @param vector<Rule> the list of rules to be checked
 * @param string filename the filename that have changed
 * @param string masks the changes on this file
 */
void Observer::run_rules(vector<Rule*> rules, string filename, string masks){
    // FIXME consider we can have directories too here (basically we just want to remove them)
    File file = File(filename);

    vector<Rule*>::iterator iterator;
    for(iterator = rules.begin(); iterator != rules.end(); ++iterator){	
        (*iterator)->process(file);
    }
}

void Observer::stop(string path){
    cout << "stop watching the repository" << path << endl;
}
