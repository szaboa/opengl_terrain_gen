#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
class IndexBuffer
{
private:
	GLuint bufferId;
public:
	IndexBuffer(std::vector<short> indexes);
	void setVertexAttribPointer(int dataOffset, int attributeLocation, int componentCount, int stride);
	GLuint getBufferId();
	~IndexBuffer();
};

