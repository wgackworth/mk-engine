#include <MK/Core.h>
#include <MK/Graphics.h>
#include <stdlib.h>
#include <stdio.h>

// Window Settings
const unsigned int WINDOW_WIDTH  = 800u;
const unsigned int WINDOW_HEIGHT = 600u;
const char*        WINDOW_TITLE  = "GLFW";

// Vertices and Indices
GLfloat vertices[] = {
  -0.5f,  -0.5f, 0.0f, 1.f, 1.f, 1.f,
   0.0f,  -0.5f, 0.0f, 1.f, 1.f, 1.f,
   0.5f,  -0.5f, 0.0f, 1.f, 1.f, 1.f,
  -0.25f,  0.0f, 0.0f, 1.f, 1.f, 1.f,
   0.25f,  0.0f, 0.0f, 1.f, 1.f, 1.f,
   0.0f,   0.5f, 0.0f, 1.f, 1.f, 1.f,
};
GLuint indices[] = {
  0, 1, 3,
  1, 2, 4,
  3, 4, 5,
};

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
  mk_RGBA clearColor = mk_emergeRGBA(0, 0, 0, 1.f);
  mk_gfx_useClearColor(clearColor);

  // Default Shader
  mk_gfx_Shader defaultShader = mk_gfx_emergeShader(
    "resources/Shaders/default.vert",
    "resources/Shaders/default.frag"
  );

  // VAO, VBO, and EBO
  GLuint VAO;
  mk_gfx_VBO VBO = mk_gfx_emergeVBO(vertices, sizeof(vertices));
  mk_gfx_EBO EBO = mk_gfx_emergeEBO(indices, sizeof(indices));

  glGenVertexArrays(1, &VAO);

  glBindVertexArray(VAO);
  mk_gfx_bindVBO(VBO);
  mk_gfx_bindEBO(EBO);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
  glEnableVertexAttribArray(1);

  glBindVertexArray(0);
  mk_gfx_unbindVBO(VBO);
  mk_gfx_unbindEBO(EBO);

  // Line Mode
  mk_gfx_useLineMode();

  // Main Loop
  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    mk_gfx_useShader(defaultShader);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
    glfwSwapBuffers(window);
  }

  glDeleteVertexArrays(1, &VAO);
  mk_gfx_deleteVBO(VBO);
  mk_gfx_deleteEBO(EBO);
  mk_gfx_deleteShader(defaultShader);
  glfwDestroyWindow(window);
  glfwTerminate();
  return EXIT_SUCCESS;
}
