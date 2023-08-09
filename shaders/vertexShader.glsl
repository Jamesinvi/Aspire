#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

uniform mat4 projMatrix;
uniform mat4 viewMatrix;
uniform mat4 rotMatrix;
uniform vec3 lightDir;
uniform vec3 backgroundCol;

out vec3 FragPos;
out vec3 Normal;

void main()
{
    FragPos = vec3(rotMatrix * vec4(aPos, 1.0));
    mat3 normalMatrix = transpose(inverse(mat3(rotMatrix)));
    Normal = normalize(normalMatrix * aNormal);
    gl_Position = projMatrix * viewMatrix * vec4(FragPos, 1.0);
}
