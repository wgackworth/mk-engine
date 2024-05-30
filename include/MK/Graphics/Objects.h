#ifndef MK_OBJECTS_H
#define MK_OBJECTS_H

#include <GL/glew.h>
#include <MK/Core/File.h>

/**
 * @brief Structure representing an OpenGL shader program.
 */
typedef struct mk_gfx_Shader
{
  GLuint ID;
} mk_gfx_Shader;

/**
 * @brief Creates a shader program from vertex and fragment shader files.
 * @param vertexPath Path to the vertex shader file.
 * @param fragmentPath Path to the fragment shader file.
 * @return A shader program.
 */
mk_gfx_Shader mk_gfx_emergeShader(const char* vertexPath, const char* fragmentPath);
/**
 * @brief Uses the specified shader program.
 * @param shader The shader program to use.
 */
void mk_gfx_useShader(const mk_gfx_Shader shader);
/**
 * @brief Deletes the specified shader program.
 * @param shader The shader program to delete.
 */
void mk_gfx_deleteShader(const mk_gfx_Shader shader);

/**
 * @brief Structure representing an OpenGL Vertex Buffer Object (VBO).
 */
typedef struct mk_gfx_VBO
{
  GLuint ID;
} mk_gfx_VBO;

/**
 * @brief Creates a Vertex Buffer Object (VBO) and fills it with data.
 * @param vertices Pointer to the vertex data.
 * @param size Size of the vertex data in bytes.
 * @return A VBO.
 */
mk_gfx_VBO mk_gfx_emergeVBO(GLfloat* vertices, GLsizeiptr size);
/**
 * @brief Binds the specified VBO.
 * @param VBO The VBO to bind.
 */
void mk_gfx_bindVBO(const mk_gfx_VBO VBO);
/**
 * @brief Unbinds the specified VBO.
 * @param VBO The VBO to unbind.
 */
void mk_gfx_unbindVBO(const mk_gfx_VBO VBO);
/**
 * @brief Deletes the specified VBO.
 * @param VBO The VBO to delete.
 */
void mk_gfx_deleteVBO(const mk_gfx_VBO VBO);

/**
 * @brief Structure representing an OpenGL Element Buffer Object (EBO).
 */
typedef struct mk_gfx_EBO
{
  GLuint ID;
} mk_gfx_EBO;

/**
 * @brief Creates an Element Buffer Object (EBO) and fills it with data.
 * @param indices Pointer to the index data.
 * @param size Size of the index data in bytes.
 * @return An EBO.
 */
mk_gfx_EBO mk_gfx_emergeEBO(GLuint* indices, GLsizeiptr size);
/**
 * @brief Binds the specified EBO.
 * @param EBO The EBO to bind.
 */
void mk_gfx_bindEBO(const mk_gfx_EBO EBO);
/**
 * @brief Unbinds the specified EBO.
 * @param EBO The EBO to unbind.
 */
void mk_gfx_unbindEBO(const mk_gfx_EBO EBO);
/**
 * @brief Deletes the specified EBO.
 * @param EBO The EBO to delete.
 */
void mk_gfx_deleteEBO(const mk_gfx_EBO EBO);

#endif // MK_OBJECTS_H
