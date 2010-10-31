#include <file.h>
using namespace std;

/**
 * Plugin interface.
 *
 */
class Plugin
{
    public:
	vector<Plugin> loadPlugins();

	/**
	 * Called when the plugin is run on a file.
	 */
	virtual void run(File file) = 0;

	/**
	 * Return the list of stereotypes that must be validated to call this
	 * plugin.
	 */
	virtual vector<Stereotype> listUsedStereotypes() = 0;

	/**
	 * Virtual destructor to change the pointer ownership if needed.
	 * Otherwise, the destructor is not called when using polymophism.
	 */
	virtual ~Plugin() {}
};

class DumbPlugin: public Plugin
{
    void run(File file);
    vector<Stereotype> listUsedStereotypes();
};
