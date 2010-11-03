#ifndef __CONDITION_H
#define __CONDITION_H

#include "file.h"

class Condition {
public:
	Condition();
	bool isMet(File);
};
#endif
