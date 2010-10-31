#include <plugins.h>
#include <stereotypes.h>

/**
 * Load the plugins
 *
 * TODO: Use a XML file for loading the plugins instead of doing it statically
 * like here.
 */
vector<Plugin> Plugin::loadPlugins(){
   vector<Plugin> plugins;
   plugins.push_back(new DumbPlugin());
}


void DumbPlugin::run(File file){
    cout << "yeah"; 
}


vector<Stereotype> DumbPlugin::listUsedStereotypes(){
    vector<Stereotype> stereotypes;
    stereotypes.push_back(BigFile)
}
