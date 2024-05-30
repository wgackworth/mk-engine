#ifndef MK_DEBUG_H
#define MK_DEBUG_H

#include <MK/Core.h>

/**
 * @brief Prints the components of a 2D vector.
 * @param vec The vector to print.
 */
void mk_printVec2(const mk_Vec2 vec);
/**
 * @brief Prints the components of a 3D vector.
 * @param vec The vector to print.
 */
void mk_printVec3(const mk_Vec3 vec);

/**
 * @brief Prints the elements of a 4x4 matrix.
 * @param mat The matrix to print.
 */
void mk_printMat4(const mk_Mat4 mat);

#endif // MK_DEBUG_H
