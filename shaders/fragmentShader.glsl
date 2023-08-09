#version 330 core
out vec4 FragColor;
in vec3 Normal;
uniform vec3 lightDir;
uniform vec3 backgroundCol;

void main()
{

    vec3 norm = normalize(Normal);
    vec4 col = vec4(1.0f, 1.0f, 0.2f, 1.0f);
    vec4 diffuse = col * dot(norm, normalize(lightDir)) ;
    FragColor = diffuse+ vec4(backgroundCol * .7,1);
   
}