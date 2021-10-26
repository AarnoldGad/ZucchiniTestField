#version 330

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 iTexCoord;

void main()
{
   gl_Position = projection * view * model * vec4(pos.xyz, 1.0);
   iTexCoord = texCoord;
}
