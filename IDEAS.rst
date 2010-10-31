Firstly, I had the idea of using plugins, and wanted to reuse the name of
"stereotypes". The idea I had was using some properties of the file to determine
a set of stereotypes that are true for it. 

For instance, let's say that a file greater than 10mb is a "big file", or that
every file with the extension ".zip" is a zip file.

I've abandonned this idea, at the profit of the concept of "conditions", because
it seems to be a lot more reliable. Using stereotypes means that each stereotype
must be understood in a really specific way, and I had needed to add a lot of
stereotypes, each time I found a new usage.

Now we have conditions and plugins. A plugin is defined by two things: an
actions and some conditions.

The action should be done when the conditions are met.
