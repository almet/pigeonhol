#ifndef __CONDITION_H
#define __CONDITION_H

#include "file.h"

// that's the condition interface; A condtion have jsut to be met
class Condition {
public:
	Condition();
	bool isMet(File&) const;
};
#endif
