#version 330 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform mat3 model;
uniform mat3 view;
uniform mat4 projection;

void main()
{
  vec3 _pos = view * model * vec3(aPos, 1.0f);
  gl_Position = projection * vec4(_pos, 1.0f);
  TexCoord = aTexCoord;
}
