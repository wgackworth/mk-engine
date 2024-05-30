#include <MK/Graphics/Window.h>

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}

mk_gfx_Window mk_gfx_emergeWindow(const char* title, const unsigned int width, const unsigned int height)
{
  GLFWwindow* glfwInstance = glfwCreateWindow(
    width,
    height,
    title,
    NULL,
    NULL
  );
  mk_gfx_Window window =
  {
    .title = title,
    .width = width,
    .height = height,
    .glfwInstance = glfwInstance
  };
  if (glfwInstance == NULL)
  {
    fprintf(stderr, "Failed to create a GLFW Window!\n");
    return window;
  }
  glfwMakeContextCurrent(glfwInstance);
  glfwSetFramebufferSizeCallback(glfwInstance, framebufferSizeCallback);
  return window;
}

void mk_gfx_updateWindow(const mk_gfx_Window* window)
{
  glfwPollEvents();
}

void mk_gfx_clearWindow(const mk_gfx_Window* window)
{
  glClear(GL_COLOR_BUFFER_BIT);
}

void mk_gfx_displayWindow(const mk_gfx_Window* window)
{
  glfwSwapBuffers(window->glfwInstance);
}

void mk_gfx_destroyWindow(mk_gfx_Window* window)
{
  glfwDestroyWindow(window->glfwInstance);
  window->glfwInstance = NULL;
}

bool mk_gfx_isWindowOpen(const mk_gfx_Window* window)
{
  return glfwWindowShouldClose(window->glfwInstance) == false;
}
