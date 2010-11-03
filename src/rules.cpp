#include "rules.h"

Rule::Rule(vector<Condition> conditions, string script){
    this->_conditions = conditions;
    this->_script = script;
}

void Rule::run(File file){
    
    vector<Condition>::const_iterator iterator;
    for(iterator = this->_conditions.begin();
	 iterator != this->_conditions.end(); ++iterator ){	

        if (!iterator->isMet(file)){
            return;
        }
    }

    cout << "launch the execution of ";
    cout << findAndReplace(this->_script, "%filename%", file.getName()) << endl;
}
