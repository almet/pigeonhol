#include "rules.h"
#include <stdlib.h>
#include "utils.h"

/**
 * Create the rule.
 * It needs to be passed a list of conditions, and the name of the script to
 * call.
 *
 * This name could contain some special characters, like %filename, that will
 * be replaced before running them, by the real name of the file.
 */
Rule::Rule(vector<Condition*> conditions, string script){
    this->_conditions = conditions;
    this->_script = script;
}

void Rule::process(File file){

    // iterate over all the rules
    vector<Condition*>::iterator iterator;
    for(iterator = this->_conditions.begin(); iterator != this->_conditions.end(); ++iterator ){
        if (!(*iterator)->isMet(file)){
            return; // exists if one condition is not met
        }
    }

    // otherwise, call the given action on the system
    cout << "action to be done on " << file.getName() << endl;
    system(findAndReplace(this->_script, "%filename%", file.getName()).c_str());
}
