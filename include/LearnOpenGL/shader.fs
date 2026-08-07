#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    //FragColor =  texture(ourTexture,TexCoord) * vec4(ourColor,1.0f);//第一个参数时纹理采样器，第二个是纹理坐标
    FragColor = mix(texture(texture1, TexCoord), texture(texture2, vec2(1.0f-TexCoord.x,TexCoord.y)), 0.2);
    //FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);
}