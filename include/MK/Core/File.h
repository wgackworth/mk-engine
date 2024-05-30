#ifndef MK_FILE_H
#define MK_FILE_H

#include <MK/Core.h>

/**
 * @brief Reads file contents into a string.
 * @param filePath Path to the file.
 * @return Dynamically allocated string with file contents, or NULL on error.
 */
char* mk_getFileContents(const char* filePath);

#endif // MK_FILE_H
