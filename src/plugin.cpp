#include "plugin.h"

Plugin::Plugin(vector<Conditions> conditions, string script){
    this->_conditions = conditions;
    this->_script = script;
}

void Plugin::run(File file){
    foreach(Condition cond, this->_conditions){	
	if not condition->isMet(file){
	    return;
	}
    }

    cout << "launch the execution of ";
    cout << findAndReplace(this->_script, "%filename%", file.name) << endl;
}
