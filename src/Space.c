#include <MK/Core/Space.h>

float mk_lenVec2(const mk_Vec2 vec)
{
  if (
    vec.x == 0.f &&
    vec.y == 0.f
  ) return 0.f;
  return sqrtf(pow(vec.x, 2) + pow(vec.y, 2));
}

mk_Vec2 mk_emergeVec2(const float x, const float y)
{
  mk_Vec2 result =
  {
    .x = x,
    .y = y
  };
  return result;
}

mk_Vec2 mk_addVec2(const mk_Vec2 vecOne, const mk_Vec2 vecTwo)
{
  mk_Vec2 result =
  {
    .x = vecOne.x + vecTwo.x,
    .y = vecOne.y + vecTwo.y
  };
  return result;
}

mk_Vec2 mk_subVec2(const mk_Vec2 vecOne, const mk_Vec2 vecTwo)
{
  mk_Vec2 result =
  {
    .x = vecOne.x - vecTwo.x,
    .y = vecOne.y - vecTwo.y
  };
  return result;
}

mk_Vec2 mk_multVec2Int(const mk_Vec2 vec, const int scalar)
{
  mk_Vec2 result =
  {
    .x = vec.x * scalar,
    .y = vec.y * scalar
  };
  return result;
}

mk_Vec2 mk_multVec2Float(const mk_Vec2 vec, const float scalar)
{
  mk_Vec2 result =
  {
    .x = vec.x * scalar,
    .y = vec.y * scalar
  };
  return result;
}

mk_Vec2 mk_multVec2Double(const mk_Vec2 vec, const double scalar)
{
  mk_Vec2 result =
  {
    .x = vec.x * scalar,
    .y = vec.y * scalar
  };
  return result;
}

mk_Vec2 mk_normalizeVec2(const mk_Vec2 vec)
{
  const float length = mk_lenVec2(vec);
  mk_Vec2 result =
  {
    .x = length == 0.f ? 1.f : vec.x / length,
    .y = length == 0.f ? 1.f : vec.y / length
  };
  return result;
}

float mk_dotVec2(const mk_Vec2 vecOne, const mk_Vec2 vecTwo)
{
  return vecOne.x * vecTwo.x + vecOne.y * vecTwo.y;
}
