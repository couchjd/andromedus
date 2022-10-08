#version 330 core
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0

in vec4 FragColor;
out vec4 vertexColor; // specify a color output to the fragment shader

void main()
{
    vertexColor = FragColor; // set the output variable to a dark-red color
}