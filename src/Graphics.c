#include <MK/Graphics.h>

void mk_gfx_usePointMode()
{
  glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
}

void mk_gfx_useLineMode()
{
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void mk_gfx_useFillMode()
{
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
