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
  0.f,  0.f,  1.f, 1.f, 1.f,
  32.f, 0.f,  1.f, 1.f, 1.f,
  0.f,  32.f, 1.f, 1.f, 1.f,
  32.f, 32.f, 1.f, 1.f, 1.f,
};
GLuint indices[] = {
  2, 3, 1,
  2, 1, 0,
};

int main()
{
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

  mk_gfx_linkAttribVAO(&VBO, 0, 2, GL_FLOAT, 5 * sizeof(GLfloat), (void*)0);
  mk_gfx_linkAttribVAO(&VBO, 1, 3, GL_FLOAT, 5 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));

  mk_gfx_unbindVAO(VAO);
  mk_gfx_unbindVBO(VBO);
  mk_gfx_unbindEBO(EBO);

  // Line Mode
  mk_gfx_useLineMode();

  // Engine and Version Info
  mk_printEngineInfo();
  printf("\n");
  mk_printVersionInfo();

  // Player Position
  mk_Vec2 playerPosition = mk_emergeVec2(0.f, 0.f);

  // Main Loop
  while (mk_gfx_isWindowOpen(&window))
  {
    mk_gfx_updateWindow(&window);

    if (mk_isKeyPressed(&window, MK_KEY_C))
    { mk_gfx_usePointMode(); }
    else if (mk_isKeyPressed(&window, MK_KEY_V))
    { mk_gfx_useLineMode(); }
    else if (mk_isKeyPressed(&window, MK_KEY_B))
    { mk_gfx_useFillMode(); }

    mk_Vec2 movement = mk_emergeVec2(0.f, 0.f);
    if (mk_isKeyPressed(&window, MK_KEY_W))
    {
      movement.y -= 1.f;
    }
    if (mk_isKeyPressed(&window, MK_KEY_S))
    {
      movement.y += 1.f;
    }
    if (mk_isKeyPressed(&window, MK_KEY_A))
    {
      movement.x -= 1.f;
    }
    if (mk_isKeyPressed(&window, MK_KEY_D))
    {
      movement.x += 1.f;
    }

    playerPosition = mk_addVec2(
      playerPosition,
      mk_multVec2Float(
        mk_normalizeVec2(movement),
        100.f * window.deltaTime
      )
    );

    mk_Mat4 model = mk_transMat4Vec2(
      mk_emergeMat4(1.f),
      playerPosition
    );
    mk_Mat4 view = mk_emergeMat4(1.f);
    mk_Mat4 projection = mk_ortho(
      0.f,
      (float)WINDOW_WIDTH,
      (float)WINDOW_HEIGHT,
      0.f,
      -1.f,
      1.f
    );

    mk_gfx_shaderSetMat4(defaultShader, &model, "model");
    mk_gfx_shaderSetMat4(defaultShader, &view, "view");
    mk_gfx_shaderSetMat4(defaultShader, &projection, "projection");

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
