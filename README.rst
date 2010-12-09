Pigeonhol
#########

*Rules based files organiser*

Pigeonhol is a simple script written in C++, that takes care for you about the
organisation of your folders.

*This piece of software have been made during my course of paradigms of
programing, while studying at the oxford brookes university.*

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
with a concept of `rules`.

Plugins
=======

Rules are defined in an XML file, and tell what action have to be called when
a set of conditions is met::

    <plugins>
        <plugin name="unzip">
            <condition filetype="zip" /> 
            <action>unzip %file%</action>
        </plugin>
    </plugins>

This example will unzip files when a zip file have been found. For now, it is
only possible to use the filename to get informations, but the code is easy to
change.

Note: this is not finished, and the config parser is not implemented so far.
Currently, the sofware looks for .zip files in the "observed" folder, and
extract them in "extracted". It also create a `pigeonhole.log` file.

Internal structure
===================

Internally pigeonhol use the inotify mechanism, that is a part of the linux
kernel, to watch out the different modifications to the folders/files of a
specific directory, so it is only linux compliant.

Feedback
========

This is basically a proof of concept, but I think it can be useful then. If you
have any feedback on features you want to add, or about the code, drop me
a mail at alexis at notmyidea.org !
