#version 330 core
layout (location = 0) in vec3 position;

uniform mat4 u_Matrix;
out vec4 v_Color;

void main()
{

	v_Color = vec4(0.0f, 1.0f, 0.0f, 1.0f);
	gl_Position = u_Matrix * vec4(position, 1.0f);
}