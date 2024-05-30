#include <MK/Core.h>
#include <MK/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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
  // Vector Testing
  mk_Vec2 vecOne = mk_emergeVec2(1.f, 3.f);
  mk_Vec2 vecTwo = mk_emergeVec2(4.f, -1.f);
  mk_printVec2(
    mk_multVec2Float(
      mk_normalizeVec2(vecOne),
      2.f
    )
  );

  // Initializing GLFW
  bool glfwSuccess = mk_initializeGlfw();
  if (!glfwSuccess)
  {
    return EXIT_FAILURE;
  }

  // Window
  mk_gfx_Window window = mk_gfx_emergeWindow(
    WINDOW_TITLE,
    WINDOW_WIDTH,
    WINDOW_HEIGHT
  );

  // Initializing GLEW
  bool glewSuccess = mk_initializeGlew();
  if (!glewSuccess)
  {
    mk_gfx_destroyWindow(&window);
    mk_terminate();
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
  mk_gfx_VAO VAO = mk_gfx_emergeVAO();
  mk_gfx_VBO VBO = mk_gfx_emergeVBO(vertices, sizeof(vertices));
  mk_gfx_EBO EBO = mk_gfx_emergeEBO(indices, sizeof(indices));

  mk_gfx_bindVAO(VAO);
  mk_gfx_bindVBO(VBO);
  mk_gfx_bindEBO(EBO);

  mk_gfx_linkAttribVAO(&VBO, 0, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)0);
  mk_gfx_linkAttribVAO(&VBO, 1, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

  mk_gfx_unbindVAO(VAO);
  mk_gfx_unbindVBO(VBO);
  mk_gfx_unbindEBO(EBO);

  // Line Mode
  mk_gfx_useLineMode();

  // Engine and Version Info
  mk_printEngineInfo();
  printf("\n");
  mk_printVersionInfo();

  // Main Loop
  while (mk_gfx_isWindowOpen(&window))
  {
    mk_gfx_updateWindow(&window);
    mk_gfx_clearWindow(&window);
    mk_gfx_useShader(defaultShader);
    mk_gfx_bindVAO(VAO);
    glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
    mk_gfx_displayWindow(&window);
  }

  // Termination
  mk_gfx_deleteVAO(VAO);
  mk_gfx_deleteVBO(VBO);
  mk_gfx_deleteEBO(EBO);
  mk_gfx_deleteShader(defaultShader);
  mk_gfx_destroyWindow(&window);
  mk_terminate();
  return EXIT_SUCCESS;
}
