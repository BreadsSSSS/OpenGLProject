#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;

void main()
{
    FragColor =  texture(ourTexture,TexCoord) * vec4(ourColor,1.0f);//第一个参数时纹理采样器，第二个是纹理坐标
}