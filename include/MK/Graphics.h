#ifndef MK_GRAPHICS_H
#define MK_GRAPHICS_H

#include <MK/Core/Color.h>

#include "Graphics/Window.h"
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

/**
 * @brief Sets the OpenGL clear color.
 * @param clearColor The color to use for clearing the screen.
 */
void mk_gfx_useClearColor(const mk_RGBA clearColor);

#endif // MK_GRAPHICS_H
