#version 330 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec3 aCol;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 vertCol;

void main()
{
  vertCol = aCol;
  gl_Position = projection * view * model * vec4(aPos, 0.f, 1.f);
}
