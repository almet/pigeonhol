#ifndef __OBSERVER
#define __OBSERVER

class Observer {
    const char* path;
public:
    Observer (const char*);
    void observe();
};
#endif
