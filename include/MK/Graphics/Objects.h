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

#endif // MK_OBJECTS_H
