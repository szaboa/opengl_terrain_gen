#version 330 core
layout (location = 0) in vec3 position;

uniform mat4 u_Matrix;
varying vec3 v_Color;

void main()
{
	v_Color = mix(vec3(0.180, 0.467, 0.153), // A dark green
				  vec3(0.660, 0.670, 0.680), // A stony gray
				  position.y);
	gl_Position = vec4(position, 1.0f);
}