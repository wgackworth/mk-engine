#include <MK/Core/Debug.h>

void mk_printVec2(const mk_Vec2 vec)
{
  printf("X: %.3f; Y: %.3f\n", vec.x, vec.y);
}

void mk_printVec3(const mk_Vec3 vec)
{
  printf("X: %.3f; Y: %.3f; Z: %.3f\n", vec.x, vec.y, vec.z);
}

void mk_printMat4(const mk_Mat4 mat)
{
  for (int y = 0; y < 4; y++)
  {
    for (int x = 0; x < 4; x++)
      printf("%.2f ", mat.elements[y][x]);
    printf("\n");
  }
}
