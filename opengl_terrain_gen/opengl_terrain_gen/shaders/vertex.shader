#version 330 core
layout (location = 0) in vec3 position;

out vec4 mycolor;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * vec4(position, 1.0f);
	mycolor = vec4(1.0f,0.0f,0.0f,1.0f);
}