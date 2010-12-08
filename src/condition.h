#ifndef __CONDITION_H
#define __CONDITION_H

#include "file.h"

// that's the condition interface; A condtion have just to be met
class Condition {
    public:
    virtual bool isMet(File*) = 0;
};

class FileExtensionIs : public Condition
{
    string _str;
    public:
    FileExtensionIs(string);
    bool isMet(File*);
};

class FilenameContains : public Condition
{
    string _str;
    public:
    FilenameContains(string);
    bool isMet(File*);
};
#endif
