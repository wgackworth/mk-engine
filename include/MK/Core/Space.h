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

#endif // MK_SPACE_H
