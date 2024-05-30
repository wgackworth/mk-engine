#include <MK/Core/Color.h>

mk_RGBA mk_emergeRGBA(const uint8_t red, const uint8_t green, const uint8_t blue, const float alpha)
{
  mk_RGBA color =
  {
    .red = (float)red / 255.f,
    .green = (float)green / 255.f,
    .blue = (float)blue / 255.f,
    .alpha = alpha
  };
  return color;
}
