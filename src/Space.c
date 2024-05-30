#include <MK/Core/Space.h>

mk_Vec2 mk_emergeVec2(const float x, const float y)
{
  mk_Vec2 vec =
  {
    .x = x,
    .y = y
  };
  return vec;
}

mk_Vec2 mk_addVec2(const mk_Vec2 vecOne, const mk_Vec2 vecTwo)
{
  mk_Vec2 vec =
  {
    .x = vecOne.x + vecTwo.x,
    .y = vecOne.y + vecTwo.y
  };
  return vec;
}

mk_Vec2 mk_subVec2(const mk_Vec2 vecOne, const mk_Vec2 vecTwo)
{
  mk_Vec2 vec =
  {
    .x = vecOne.x - vecTwo.x,
    .y = vecOne.y - vecTwo.y
  };
  return vec;
}
