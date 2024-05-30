#ifndef MK_COLOR_H
#define MK_COLOR_H

#include <stdint.h>

/**
 * @brief Structure representing an RGBA color.
 */
typedef struct mk_RGBA
{
  float red;
  float green;
  float blue;
  float alpha;
} mk_RGBA;

/**
 * @brief Creates an RGBA color.
 * @param red Red component (0-255).
 * @param green Green component (0-255).
 * @param blue Blue component (0-255).
 * @param alpha Alpha component (0.0-1.0).
 * @return An RGBA color.
 */
mk_RGBA mk_emergeRGBA(const uint8_t red, const uint8_t green, const uint8_t blue, const float alpha);

#endif // MK_COLOR_H
