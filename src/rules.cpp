#include "rules.h"
#include <stdlib.h>

Rule::Rule(vector<Condition> conditions, string script){
    this->_conditions = conditions;
    this->_script = script;
}

void Rule::run(File file) const{
    
    vector<Condition>::const_iterator iterator;
    for(iterator = this->_conditions.begin();
     iterator != this->_conditions.end(); ++iterator ){	

        if (!iterator->isMet(file)){
            return;
        }
    }
    cout << "action to be done on " << file.getName() << endl;
    system(findAndReplace(this->_script, "%filename%", file.getName()).c_str());
}
