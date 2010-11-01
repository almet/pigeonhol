#ifndef __OBSERVER_H
#define __OBSERVER_H

class Observer {
    const char* path;
public:
    Observer (const char*);
    void observe();
};
#endif
