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

mk_gfx_VBO mk_gfx_emergeVBO(GLfloat* vertices, GLsizeiptr size)
{
  GLuint ID;

  glGenBuffers(1, &ID);
  glBindBuffer(GL_ARRAY_BUFFER, ID);
  glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  mk_gfx_VBO VBO =
  {
    .ID = ID
  };
  return VBO;
}

void mk_gfx_bindVBO(const mk_gfx_VBO VBO)
{
  glBindBuffer(GL_ARRAY_BUFFER, VBO.ID);
}

void mk_gfx_unbindVBO(const mk_gfx_VBO VBO)
{
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void mk_gfx_deleteVBO(const mk_gfx_VBO VBO)
{
  glDeleteBuffers(1, &VBO.ID);
}

mk_gfx_EBO mk_gfx_emergeEBO(GLuint* indices, GLsizeiptr size)
{
  GLuint ID;

  glGenBuffers(1, &ID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  mk_gfx_EBO EBO =
  {
    .ID = ID
  };
  return EBO;
}

void mk_gfx_bindEBO(const mk_gfx_EBO EBO)
{
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO.ID);
}

void mk_gfx_unbindEBO(const mk_gfx_EBO EBO)
{
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void mk_gfx_deleteEBO(const mk_gfx_EBO EBO)
{
  glDeleteBuffers(1, &EBO.ID);
}
