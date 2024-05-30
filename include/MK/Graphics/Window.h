#ifndef MK_WINDOW_H
#define MK_WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Structure representing a window in the MK engine.
 */
typedef struct mk_gfx_Window
{
  const char* title;
  GLuint width;
  GLuint height;
  GLFWwindow* glfwInstance;
  float deltaTime;
  float _lastTime;
} mk_gfx_Window;

/**
 * @brief Creates a window.
 * @param title Title of the window.
 * @param width Width of the window.
 * @param height Height of the window.
 * @return A window object.
 */
mk_gfx_Window mk_gfx_emergeWindow(const char* title, const unsigned int width, const unsigned int height);
/**
 * @brief Updates the specified window.
 * @param window Pointer to the window to update.
 */
void mk_gfx_updateWindow(mk_gfx_Window* window);
/**
 * @brief Clears the specified window.
 * @param window Pointer to the window to clear.
 */
void mk_gfx_clearWindow(const mk_gfx_Window* window);
/**
 * @brief Displays the specified window.
 * @param window Pointer to the window to display.
 */
void mk_gfx_displayWindow(const mk_gfx_Window* window);
/**
 * @brief Destroys the specified window.
 * @param window Pointer to the window to destroy.
 */
void mk_gfx_destroyWindow(mk_gfx_Window* window);
/**
 * @brief Checks if the specified window is open.
 * @param window Pointer to the window to check.
 * @return True if the window is open, false otherwise.
 */
bool mk_gfx_isWindowOpen(const mk_gfx_Window* window);

#endif // MK_WINDOW_H
