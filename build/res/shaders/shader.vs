#version 330 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
  vec3 _pos = vec3(aPos, 0.0f);
  gl_Position = projection * view * model * vec4(_pos, 1.0f);
  TexCoord = aTexCoord;
}
