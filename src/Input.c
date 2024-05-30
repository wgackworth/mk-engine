#include <MK/Core/Input.h>

bool mk_isKeyPressed(const mk_gfx_Window* window, const mk_Key key)
{
  return glfwGetKey(window->glfwInstance, key) == GLFW_PRESS;
}
