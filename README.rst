Pigeonhol
#########

Pigeonhol is a simple script wrote in C++, that takes care, for you, about the
organisation of your folders.

*This piece of software have been made during my course of paradigms of
programing, while studdying at the oxford brookes university.*

It's been created to help you doing some basic stuff, like categorizing files in
folder regarding their extensions.

    Pigeonholing is a term used to describe processes that attempt to classify
    disparate entities into a small number of categories (usually, mutually
    exclusive ones).

    The expression usually carries connotations of criticism, implying that the
    classification scheme referred to inadequately reflects the entities being
    sorted, or that it is based on stereotypes.

    Wikipedia.

I've tried to make pigeonhol as extensible as I can, so its currently working
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

Internal structure
===================

Internallyn pigeonhol use the inotify mechanism, that is a part of the linux
kernel, to watch out the different modifications to the folders/files of a
specific directory.

Here is a UML class diagram:

.. image::
