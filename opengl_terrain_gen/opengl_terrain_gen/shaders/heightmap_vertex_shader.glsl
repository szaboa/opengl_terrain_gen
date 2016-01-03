#version 330 core
layout (location = 0) in vec3 position;

uniform mat4 view;
uniform mat4 projection;
uniform mat4 model;
varying vec3 v_Color;

void main()
{
	v_Color = vec3(1.0f,1.0f,1.0f);
	gl_Position = projection * view * vec4(position, 1.0f);
}