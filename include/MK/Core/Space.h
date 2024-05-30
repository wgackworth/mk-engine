#ifndef MK_SPACE_H
#define MK_SPACE_H

#include <math.h>

/**
 * @brief Structure representing a 2D vector.
 */
typedef struct mk_Vec2
{
  float x;
  float y;
} mk_Vec2;

/**
 * @brief Structure representing a 3D vector.
 */
typedef struct mk_Vec3
{
  float x;
  float y;
  float z;
} mk_Vec3;


/**
 * @brief Calculates the length of a 2D vector.
 * @param vec The vector to calculate the length of.
 * @return The length of the vector.
 */
float mk_lenVec2(const mk_Vec2 vec);
/**
 * @brief Calculates the length of a 3D vector.
 * @param vec The vector to calculate the length of.
 * @return The length of the vector.
 */
float mk_lenVec3(const mk_Vec3 vec);

/**
 * @brief Creates a 2D vector.
 * @param x X component of the vector.
 * @param y Y component of the vector.
 * @return A 2D vector.
 */
mk_Vec2 mk_emergeVec2(const float x, const float y);
/**
 * @brief Adds two 2D vectors.
 * @param vecOne The first vector.
 * @param vecTwo The second vector.
 * @return The result of adding the two vectors.
 */
mk_Vec2 mk_addVec2(const mk_Vec2 vecOne, const mk_Vec2 vecTwo);
/**
 * @brief Subtracts the second 2D vector from the first.
 * @param vecOne The first vector.
 * @param vecTwo The second vector.
 * @return The result of subtracting vecTwo from vecOne.
 */
mk_Vec2 mk_subVec2(const mk_Vec2 vecOne, const mk_Vec2 vecTwo);
/**
 * @brief Multiplies a 2D vector by an integer scalar.
 * @param vec The vector to multiply.
 * @param scalar The scalar value to multiply by.
 * @return The result of the multiplication.
 */
mk_Vec2 mk_multVec2Int(const mk_Vec2 vec, const int scalar);
/**
 * @brief Multiplies a 2D vector by a float scalar.
 * @param vec The vector to multiply.
 * @param scalar The scalar value to multiply by.
 * @return The result of the multiplication.
 */
mk_Vec2 mk_multVec2Float(const mk_Vec2 vec, const float scalar);
/**
 * @brief Multiplies a 2D vector by a double scalar.
 * @param vec The vector to multiply.
 * @param scalar The scalar value to multiply by.
 * @return The result of the multiplication.
 */
mk_Vec2 mk_multVec2Double(const mk_Vec2 vec, const double scalar);
/**
 * @brief Normalizes a 2D vector.
 * @param vec The vector to normalize.
 * @return The normalized vector.
 */
mk_Vec2 mk_normalizeVec2(const mk_Vec2 vec);
/**
 * @brief Calculates the dot product of two 2D vectors.
 * @param vecOne The first vector.
 * @param vecTwo The second vector.
 * @return The dot product of the two vectors.
 */
float mk_dotVec2(const mk_Vec2 vecOne, const mk_Vec2 vecTwo);

/**
 * @brief Creates a 3D vector.
 * @param x X component of the vector.
 * @param y Y component of the vector.
 * @param z Z component of the vector.
 * @return A 3D vector.
 */
mk_Vec3 mk_emergeVec3(const float x, const float y, const float z);
/**
 * @brief Adds two 3D vectors.
 * @param vecOne The first vector.
 * @param vecTwo The second vector.
 * @return The result of adding the two vectors.
 */
mk_Vec3 mk_addVec3(const mk_Vec3 vecOne, const mk_Vec3 vecTwo);
/**
 * @brief Subtracts the second 3D vector from the first.
 * @param vecOne The first vector.
 * @param vecTwo The second vector.
 * @return The result of subtracting vecTwo from vecOne.
 */
mk_Vec3 mk_subVec3(const mk_Vec3 vecOne, const mk_Vec3 vecTwo);
/**
 * @brief Multiplies a 3D vector by an integer scalar.
 * @param vec The vector to multiply.
 * @param scalar The scalar value to multiply by.
 * @return The result of the multiplication.
 */
mk_Vec3 mk_multVec3Int(const mk_Vec3 vec, const int scalar);
/**
 * @brief Multiplies a 3D vector by a float scalar.
 * @param vec The vector to multiply.
 * @param scalar The scalar value to multiply by.
 * @return The result of the multiplication.
 */
mk_Vec3 mk_multVec3Float(const mk_Vec3 vec, const float scalar);
/**
 * @brief Multiplies a 3D vector by a double scalar.
 * @param vec The vector to multiply.
 * @param scalar The scalar value to multiply by.
 * @return The result of the multiplication.
 */
mk_Vec3 mk_multVec3Double(const mk_Vec3 vec, const double scalar);
/**
 * @brief Normalizes a 3D vector.
 * @param vec The vector to normalize.
 * @return The normalized vector.
 */
mk_Vec3 mk_normalizeVec3(const mk_Vec3 vec);
/**
 * @brief Calculates the dot product of two 3D vectors.
 * @param vecOne The first vector.
 * @param vecTwo The second vector.
 * @return The dot product of the two vectors.
 */
float mk_dotVec3(const mk_Vec3 vecOne, const mk_Vec3 vecTwo);
/**
 * @brief Calculates the cross product of two 3D vectors.
 * @param vecOne The first vector.
 * @param vecTwo The second vector.
 * @return The cross product of the two vectors.
 */
mk_Vec3 mk_crossVec3(const mk_Vec3 vecOne, const mk_Vec3 vecTwo);

/**
 * @brief Structure representing a 4x4 matrix.
 */
typedef struct mk_Mat4
{
  float elements[4][4];
} mk_Mat4;

/**
 * @brief Creates a 4x4 matrix with the specified diagonal value.
 * @param diagonalValue The value to set on the diagonal elements of the matrix.
 * @return A 4x4 matrix with diagonal elements set to the specified value.
 */
mk_Mat4 mk_emergeMat4(const float diagonalValue);
/**
 * @brief Adds two 4x4 matrices.
 * @param matOne The first matrix.
 * @param matTwo The second matrix.
 * @return The result of adding the two matrices.
 */
mk_Mat4 mk_addMat4(const mk_Mat4 matOne, const mk_Mat4 matTwo);
/**
 * @brief Subtracts the second 4x4 matrix from the first.
 * @param matOne The first matrix.
 * @param matTwo The second matrix.
 * @return The result of subtracting matTwo from matOne.
 */
mk_Mat4 mk_subMat4(const mk_Mat4 matOne, const mk_Mat4 matTwo);
/**
 * @brief Multiplies a 4x4 matrix by an integer scalar.
 * @param mat The matrix to multiply.
 * @param scalar The scalar value to multiply by.
 * @return The result of the multiplication.
 */
mk_Mat4 mk_multMat4Int(mk_Mat4 mat, const int scalar);
/**
 * @brief Multiplies a 4x4 matrix by a float scalar.
 * @param mat The matrix to multiply.
 * @param scalar The scalar value to multiply by.
 * @return The result of the multiplication.
 */
mk_Mat4 mk_multMat4Float(mk_Mat4 mat, const float scalar);
/**
 * @brief Multiplies a 4x4 matrix by a double scalar.
 * @param mat The matrix to multiply.
 * @param scalar The scalar value to multiply by.
 * @return The result of the multiplication.
 */
mk_Mat4 mk_multMat4Double(mk_Mat4 mat, const double scalar);
/**
 * @brief Multiplies two 4x4 matrices.
 * @param matOne The first matrix.
 * @param matTwo The second matrix.
 * @return The result of multiplying the two matrices.
 */
mk_Mat4 mk_multMat4Mat4(const mk_Mat4 matOne, const mk_Mat4 matTwo);

/**
 * @brief Returns a pointer to the first element of a 4x4 matrix.
 * @param mat Pointer to the matrix.
 * @return Pointer to the first element of the matrix.
 */
const float* mk_valuePointerMat4(const mk_Mat4* mat);

/**
 * @brief Applies a translation to a 4x4 matrix using a 2D vector.
+ * @param mat The matrix to translate.
 * @param vec The 2D vector representing the translation.
 * @return The translated matrix.
 */
mk_Mat4 mk_transMat4Vec2(mk_Mat4 mat, const mk_Vec2 vec);
/**
 * @brief Applies a translation to a 4x4 matrix using a 3D vector.
 * @param mat The matrix to translate.
 * @param vec The 3D vector representing the translation.
 * @return The translated matrix.
 */
mk_Mat4 mk_transMat4Vec3(mk_Mat4 mat, const mk_Vec3 vec);
/**
 * @brief Creates an orthographic projection matrix.
 * @param left The coordinate for the left vertical clipping plane.
 * @param right The coordinate for the right vertical clipping plane.
 * @param bottom The coordinate for the bottom horizontal clipping plane.
 * @param top The coordinate for the top horizontal clipping plane.
 * @param zNear The distance to the near depth clipping plane.
 * @param zFar The distance to the far depth clipping plane.
 * @return The orthographic projection matrix.
 */
mk_Mat4 mk_ortho(const float left, const float right, const float bottom, const float top, const float zNear, const float zFar);

#endif // MK_SPACE_H
