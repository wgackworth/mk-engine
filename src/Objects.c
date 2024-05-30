#include <MK/Graphics/Objects.h>

mk_gfx_Shader mk_gfx_emergeShader(const char* vertexPath, const char* fragmentPath)
{
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
  GLuint programID = glCreateProgram();
  glAttachShader(programID, vertexShader);
  glAttachShader(programID, fragmentShader);
  glLinkProgram(programID);

  // Info Log
  char infoLog[512];
  int success = 0;

  // Validating the Vertex Shader
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    fprintf(stderr, "Failed to compile the vertex shader!\n");
    fprintf(stderr, "Error: %s\n", infoLog);
  }

  // Validating the Fragment Shader
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    fprintf(stderr, "Failed to compile the fragment shader!\n");
    fprintf(stderr, "Error: %s\n", infoLog);
  }

  // Validating the Shader Program
  glGetProgramiv(programID, GL_LINK_STATUS, &success);
  if (!success)
  {
    glGetProgramInfoLog(programID, 512, NULL, infoLog);
    fprintf(stderr, "Failed to link the shader program!\n");
    fprintf(stderr, "Error: %s\n", infoLog);
  }

  // Deleting the Shaders
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  // Shader Objecz
  mk_gfx_Shader shader =
  {
    .ID = programID
  };

  // Returning the Shader Object
  return shader;
}

void mk_gfx_useShader(const mk_gfx_Shader shader)
{
  glUseProgram(shader.ID);
}

void mk_gfx_deleteShader(const mk_gfx_Shader shader)
{
  glDeleteProgram(shader.ID);
}