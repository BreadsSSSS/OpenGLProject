#version 330 core
layout (location = 0) in vec3 aPos;
//layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 ourColor;
out vec2 TexCoord;

uniform mat4 transform;

uniform float time;
uniform float xoffset;
uniform float yoffset;

void main()
{
    gl_Position = transform *vec4(aPos, 1.0);
    //ourColor = aColor;
    TexCoord = vec2(aTexCoord.x,aTexCoord.y);
    //gl_Position = vec4(aPos.x + xoffset, aPos.y + yoffset, aPos.z, 1.0);
    //gl_Position = vec4(aPos.x + sin(time) * 0.5, aPos.y, aPos.z, 1.0);
}