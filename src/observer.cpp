#include "observer.h"
#include "inotify-cxx.h"

Observer::Observer(){
    cout << "creating the observer" << endl;
}

void Observer::observe(string path){
    this->_observing[path] = true;
    try {
        Inotify notify;
 
        InotifyWatch watch(path, IN_ALL_EVENTS);
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
 
                    cout << "[watch " << path << "] ";
                    cout << "event mask: \"" << mask_str << "\", ";
                    cout << "filename: \"" << filename << "\"" << endl;
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

bool Observer::stop(string path){
    cout << "stoping";
    return true;
}
