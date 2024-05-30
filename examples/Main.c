#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

// Constants
const unsigned int WINDOW_WIDTH  = 800u;
const unsigned int WINDOW_HEIGHT = 600u;
const char*        WINDOW_TITLE  = "GLFW";

int main()
{
  // Initializing GLFW
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

  // Creating the Window
  GLFWwindow* window = glfwCreateWindow(
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    WINDOW_TITLE,
    NULL,
    NULL
  );
  if (window == NULL)
  {
    fprintf(stderr, "Failed to create a GLFW Window!\n");
    glfwTerminate();
    return EXIT_FAILURE;
  }
  glfwMakeContextCurrent(window);

  // Initializing GLEW
  GLenum glewErr = glewInit();
  if (glewErr != GLEW_OK)
  {
    fprintf(stderr, "Failed to initialize GLEW!\n");
    fprintf(stderr, "Error: %s", glewGetErrorString(glewErr));
    glfwTerminate();
    return EXIT_FAILURE;
  }

  // Clear Color
  GLclampf red   = 0.0f;
  GLclampf green = 0.0f;
  GLclampf blue  = 0.0f;
  GLclampf alpha = 1.0f;
  glClearColor(red, green, blue, alpha);

  // Main Loop
  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return EXIT_SUCCESS;
}
