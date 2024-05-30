#ifndef MK_INPUT_H
#define MK_INPUT_H

#include <MK/Graphics/Window.h>

/**
 * @brief Enumeration of key codes for common keys.
 */
typedef enum mk_Key
{
  MK_KEY_ESCAPE = GLFW_KEY_ESCAPE,
  MK_KEY_SPACEBAR = GLFW_KEY_SPACE,
  MK_KEY_ENTER = GLFW_KEY_ENTER,
  MK_KEY_TAB = GLFW_KEY_TAB,
  MK_KEY_BACKSPACE = GLFW_KEY_BACKSPACE,
  MK_KEY_LEFT_CONTROL = GLFW_KEY_LEFT_CONTROL,
  MK_KEY_RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL,
  MK_KEY_LEFT_SHIFT = GLFW_KEY_LEFT_SHIFT,
  MK_KEY_RIGHT_SHIFT = GLFW_KEY_RIGHT_SHIFT,
  MK_KEY_LEFT_ALT = GLFW_KEY_LEFT_ALT,
  MK_KEY_RIGHT_ALT = GLFW_KEY_RIGHT_ALT,
  MK_KEY_DELETE = GLFW_KEY_DELETE,
  MK_KEY_PAGE_UP = GLFW_KEY_PAGE_UP,
  MK_KEY_PAGE_DOWN = GLFW_KEY_PAGE_DOWN,
  MK_KEY_0 = GLFW_KEY_0,
  MK_KEY_1 = GLFW_KEY_1,
  MK_KEY_2 = GLFW_KEY_2,
  MK_KEY_3 = GLFW_KEY_3,
  MK_KEY_4 = GLFW_KEY_4,
  MK_KEY_5 = GLFW_KEY_5,
  MK_KEY_6 = GLFW_KEY_6,
  MK_KEY_7 = GLFW_KEY_7,
  MK_KEY_8 = GLFW_KEY_8,
  MK_KEY_9 = GLFW_KEY_9,
  MK_KEY_A = GLFW_KEY_A,
  MK_KEY_B = GLFW_KEY_B,
  MK_KEY_C = GLFW_KEY_C,
  MK_KEY_D = GLFW_KEY_D,
  MK_KEY_E = GLFW_KEY_E,
  MK_KEY_F = GLFW_KEY_F,
  MK_KEY_G = GLFW_KEY_G,
  MK_KEY_H = GLFW_KEY_H,
  MK_KEY_I = GLFW_KEY_I,
  MK_KEY_J = GLFW_KEY_J,
  MK_KEY_K = GLFW_KEY_K,
  MK_KEY_L = GLFW_KEY_L,
  MK_KEY_M = GLFW_KEY_M,
  MK_KEY_N = GLFW_KEY_N,
  MK_KEY_O = GLFW_KEY_O,
  MK_KEY_P = GLFW_KEY_P,
  MK_KEY_Q = GLFW_KEY_Q,
  MK_KEY_R = GLFW_KEY_R,
  MK_KEY_S = GLFW_KEY_S,
  MK_KEY_T = GLFW_KEY_T,
  MK_KEY_U = GLFW_KEY_U,
  MK_KEY_V = GLFW_KEY_V,
  MK_KEY_W = GLFW_KEY_W,
  MK_KEY_X = GLFW_KEY_X,
  MK_KEY_Y = GLFW_KEY_Y,
  MK_KEY_Z = GLFW_KEY_Z,
  MK_KEY_UP = GLFW_KEY_UP,
  MK_KEY_DOWN = GLFW_KEY_DOWN,
  MK_KEY_LEFT = GLFW_KEY_LEFT,
  MK_KEY_RIGHT = GLFW_KEY_RIGHT
} mk_Key;

/**
 * @brief Checks if a specific key is currently pressed.
 * @param window Pointer to the window where the key press is being checked.
 * @param key The key to check.
 * @return True if the key is currently pressed, false otherwise.
 */
bool mk_isKeyPressed(const mk_gfx_Window* window, const mk_Key key);

#endif // MK_INPUT_H
