#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "Vec3f.h"
class VertexBuffer
{
private:
	GLuint VAO;
	GLuint bufferId;
public:
	VertexBuffer(std::vector<Vec3f> vertices);
	void setVertexAttribPointer(int dataOffset, int attributeLocation, int componentCount, int stride);

	GLuint getVAO();
	~VertexBuffer();
};

