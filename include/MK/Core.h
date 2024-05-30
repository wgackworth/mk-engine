#ifndef MK_CORE_H
#define MK_CORE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

#include "Core/Constants.h"
#include "Core/File.h"
#include "Core/Color.h"

/**
 * @brief Prints information about the MK engine.
 */
void mk_printEngineInfo();
/**
 * @brief Prints version information.
 */
void mk_printVersionInfo();

#endif // MK_CORE_H
