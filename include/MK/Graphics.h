#ifndef MK_GRAPHICS_H
#define MK_GRAPHICS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Graphics/Objects.h"

/**
 * @brief Sets OpenGL to point rendering mode.
 */
void mk_gfx_usePointMode();
/**
 * @brief Sets OpenGL to line rendering mode.
 */
void mk_gfx_useLineMode();
/**
 * @brief Sets OpenGL to fill rendering mode.
 */
void mk_gfx_useFillMode();

#endif // MK_GRAPHICS_H
