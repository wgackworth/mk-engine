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

void mk_gfx_useClearColor(const mk_RGBA clearColor)
{
  glClearColor(
    clearColor.red,
    clearColor.green,
    clearColor.blue,
    clearColor.alpha
  );
}
