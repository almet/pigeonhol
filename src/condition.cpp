#include "condition.h"

/**
 * Create the condition, and internally store the str to check for
 *
 * @param string str the string to look at
 */
FileExtensionIs::FileExtensionIs(string str){
    this->_str = str;
}

/**
 * Check that the file extension is the given one.
 *
 * @param File f
 */
bool FileExtensionIs::isMet(File* f) {
    return f->matchExtension(this->_str);
}

/**
 * Create the condition, and internally store the str to check for
 *
 * @param string str the string to look at
 */
FilenameContains::FilenameContains(string str){
    this->_str = str;
}

/**
 * Check that the file name contains the given text
 * This can be useful for
 *
 * TODO: Really check it !
 */
bool FilenameContains::isMet(File* f) {
    return true; // return true each time now, but need to look at the real file name to say so
}
