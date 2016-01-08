#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class VertexBuffer
{
private:
	GLuint VAO;
	GLuint bufferId;
public:
	VertexBuffer(std::vector<glm::vec3> vertices);
	void setVertexAttribPointer(int dataOffset, int attributeLocation, int componentCount, int stride);
	GLuint getBufferId();
	GLuint getVAO();
	~VertexBuffer();
};

