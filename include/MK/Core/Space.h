#ifndef MK_SPACE_H
#define MK_SPACE_H

/**
 * @brief Structure representing a 2D vector.
 */
typedef struct mk_Vec2
{
  float x;
  float y;
} mk_Vec2;

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

#endif // MK_SPACE_H
