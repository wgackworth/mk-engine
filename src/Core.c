#include <MK/Core.h>

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
