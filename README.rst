Pigeonhole
##########

Pigeonhole is a simple script wrote in C++, that takes care, for you, about the
organisation of your folders.

It's been created to help you doing some basic stuff, like categorizing files in
folder regarding their extensions.

    Pigeonholing is a term used to describe processes that attempt to classify
    disparate entities into a small number of categories (usually, mutually
    exclusive ones).

    The expression usually carries connotations of criticism, implying that the
    classification scheme referred to inadequately reflects the entities being
    sorted, or that it is based on stereotypes.

    Wikipedia.

I've tried to make pigeonhole as extensible as I can, so its currently working
with a concept of `plugins`.

Plugins
=======

Plugins are simple scripts that can be called when a set of conditions are
met.

It's possible to define the plugins using an XML file::

    <plugins>
        <plugin name="unzip">
            <condition filetype="zip" /> 
            <action>unzip %file%</action>
        </plugin>
    </plugins>

The conditions can be checked on:

* type
* date
* size
* folder
