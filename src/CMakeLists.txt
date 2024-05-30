# Library
add_library(
  MK
  Core.c
  Constants.c
  File.c
  Color.c
  Graphics.c
  Window.c
  Objects.c
)

# Linking Libraries
target_link_libraries(MK PUBLIC m GL ${GLEW_LIB} ${GLFW_LIB})
