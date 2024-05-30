# Executable
add_executable(
  mk
  Main.c
)

# Linking the MK Engine Library
target_link_libraries(mk PUBLIC MK)
