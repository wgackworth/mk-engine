# Library
add_library(
  MK
  File.c
  Color.c
  Graphics.c
  Objects.c
)

# Linking Libraries
target_link_libraries(MK PUBLIC m GL ${GLEW_LIB} ${GLFW_LIB})
