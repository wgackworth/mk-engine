#include <MK/Core/Space.h>

float mk_lenVec2(const mk_Vec2 vec)
{
  if (
    vec.x == 0.f &&
    vec.y == 0.f
  ) return 0.f;
  return sqrtf(pow(vec.x, 2) + pow(vec.y, 2));
}

float mk_lenVec3(const mk_Vec3 vec)
{
  if (
    vec.x == 0.f &&
    vec.y == 0.f &&
    vec.z == 0.f
  ) return 0.f;
  return sqrtf(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
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

mk_Vec3 mk_emergeVec3(const float x, const float y, const float z)
{
  mk_Vec3 result =
  {
    .x = x,
    .y = y,
    .z = z
  };
  return result;
}

mk_Vec3 mk_addVec3(const mk_Vec3 vecOne, const mk_Vec3 vecTwo)
{
  mk_Vec3 result =
  {
    .x = vecOne.x + vecTwo.x,
    .y = vecOne.y + vecTwo.y,
    .z = vecOne.z + vecTwo.z
  };
  return result;
}

mk_Vec3 mk_subVec3(const mk_Vec3 vecOne, const mk_Vec3 vecTwo)
{
  mk_Vec3 result =
  {
    .x = vecOne.x - vecTwo.x,
    .y = vecOne.y - vecTwo.y,
    .z = vecOne.z - vecTwo.z
  };
  return result;
}

mk_Vec3 mk_multVec3Int(const mk_Vec3 vec, const int scalar)
{
  mk_Vec3 result =
  {
    .x = vec.x * scalar,
    .y = vec.y * scalar,
    .z = vec.y * scalar
  };
  return result;
}

mk_Vec3 mk_multVec3Float(const mk_Vec3 vec, const float scalar)
{
  mk_Vec3 result =
  {
    .x = vec.x * scalar,
    .y = vec.y * scalar,
    .z = vec.y * scalar
  };
  return result;
}

mk_Vec3 mk_multVec3Double(const mk_Vec3 vec, const double scalar)
{
  mk_Vec3 result =
  {
    .x = vec.x * scalar,
    .y = vec.y * scalar,
    .z = vec.y * scalar
  };
  return result;
}

mk_Vec3 mk_normalizeVec3(const mk_Vec3 vec)
{
  const float length = mk_lenVec3(vec);
  mk_Vec3 result =
  {
    .x = length == 0.f ? 1.f : vec.x / length,
    .y = length == 0.f ? 1.f : vec.y / length,
    .z = length == 0.f ? 1.f : vec.z / length
  };
  return result;
}

float mk_dotVec3(const mk_Vec3 vecOne, const mk_Vec3 vecTwo)
{
  return vecOne.x * vecTwo.x + vecOne.y * vecTwo.y + vecOne.z * vecTwo.z;
}

mk_Vec3 mk_crossVec3(const mk_Vec3 vecOne, const mk_Vec3 vecTwo)
{
  mk_Vec3 result =
  {
    .x = vecOne.y * vecTwo.z - vecOne.z * vecTwo.y,
    .y = vecOne.z * vecTwo.x - vecOne.x * vecTwo.z,
    .z = vecOne.x * vecTwo.y - vecOne.y * vecTwo.x
  };
  return result;
}

mk_Mat4 mk_emergeMat4(const float diagonalValue)
{
  mk_Mat4 mat;
  for (int y = 0; y < 4; y++)
    for (int x = 0; x < 4; x++)
      mat.elements[y][x] = x == y ? diagonalValue : 0.f;
  return mat;
}
