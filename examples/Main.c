#include <MK/Core.h>
#include <MK/Graphics.h>
#include <stdlib.h>
#include <stdio.h>

// Window Settings
const unsigned int WINDOW_WIDTH  = 800u;
const unsigned int WINDOW_HEIGHT = 600u;
const char*        WINDOW_TITLE  = "GLFW";

// Constants
const unsigned int INFO_LOG_SIZE = 512u;

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
  GLclampf red   = 0.0f;
  GLclampf green = 0.0f;
  GLclampf blue  = 0.0f;
  GLclampf alpha = 1.0f;
  glClearColor(red, green, blue, alpha);

  // Shaders
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

  // Shader Source Codes
  const char* vertexShaderSource = mk_getFileContents("resources/Shaders/default.vert");
  const char* fragmentShaderSource = mk_getFileContents("resources/Shaders/default.frag");

  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(vertexShader);
  glCompileShader(fragmentShader);

  // Shader Program
  GLuint shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  // Info Log
  char infoLog[INFO_LOG_SIZE];
  int success = 0;

  // Validating the Vertex Shader
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(vertexShader, INFO_LOG_SIZE, NULL, infoLog);
    fprintf(stderr, "Failed to compile the vertex shader!\n");
    fprintf(stderr, "Error: %s\n", infoLog);
  }

  // Validating the Fragment Shader
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(fragmentShader, INFO_LOG_SIZE, NULL, infoLog);
    fprintf(stderr, "Failed to compile the fragment shader!\n");
    fprintf(stderr, "Error: %s\n", infoLog);
  }

  // Validating the Shader Program
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success)
  {
    glGetProgramInfoLog(shaderProgram, INFO_LOG_SIZE, NULL, infoLog);
    fprintf(stderr, "Failed to link the shader program!\n");
    fprintf(stderr, "Error: %s\n", infoLog);
  }

  // Deleting the Shaders
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  // VAO, VBO, and EBO
  GLuint VAO;
  GLuint VBO;
  GLuint EBO;

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
  glEnableVertexAttribArray(1);

  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  // Main Loop
  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
    glfwSwapBuffers(window);
  }

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);
  glDeleteProgram(shaderProgram);
  glfwDestroyWindow(window);
  glfwTerminate();
  return EXIT_SUCCESS;
}