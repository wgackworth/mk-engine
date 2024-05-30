#include <MK/Core.h>

bool mk_initializeGlfw()
{
  int success = glfwInit();
  if (success == GLFW_FALSE)
  {
    fprintf(stderr, "Failed to initialize GLFW!\n");
    return false;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

  return true;
}

bool mk_initializeGlew()
{
  GLenum glewErr = glewInit();
  if (glewErr != GLEW_OK)
  {
    fprintf(stderr, "Failed to initialize GLEW!\n");
    fprintf(stderr, "Error: %s", glewGetErrorString(glewErr));
    return false;
  }
  return true;
}

void mk_terminate()
{
  glfwTerminate();
}

void mk_printEngineInfo()
{
  printf("%s %s\n", MK_ENGINE_NAME, MK_ENGINE_VERSION);
  printf("Created by %s\n", MK_ENGINE_AUTHOR);
  printf("Licensed under %s\n", MK_ENGINE_LICENSE);
}

void mk_printVersionInfo()
{
  printf("OpenGL: %s\n", glGetString(GL_VERSION));
  printf("GLEW:   %s\n", glewGetString(GLEW_VERSION));
  printf("GLFW:   %s\n", glfwGetVersionString());
}
