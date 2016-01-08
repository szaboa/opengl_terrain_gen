#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(std::vector<glm::vec3> vertices)
{
	
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &bufferId);
	
	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(glm::vec3), &vertices.front(), GL_STATIC_DRAW);
	
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);
}

void VertexBuffer::setVertexAttribPointer(int dataOffset, int attributeLocation, int componentCount, int stride){
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	glVertexAttribPointer(attributeLocation, componentCount, GL_FLOAT, GL_FALSE, stride * sizeof(float), (GLvoid*)dataOffset);
	//glEnableVertexAttribArray(0);
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);
}

GLuint VertexBuffer::getVAO(){
	return VAO;
}

GLuint VertexBuffer::getBufferId(){
	return bufferId;
}
VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &bufferId);
}
