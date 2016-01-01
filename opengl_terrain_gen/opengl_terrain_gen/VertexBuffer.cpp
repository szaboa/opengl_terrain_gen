#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(std::vector<Vec3f> vertices)
{

	
	std::cout << "Number of vertices: " << vertices.size() << std::endl;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &bufferId);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(Vec3f), &vertices.front(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void VertexBuffer::setVertexAttribPointer(int dataOffset, int attributeLocation, int componentCount, int stride){
	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	glVertexAttribPointer(attributeLocation, componentCount, GL_FLOAT, GL_FALSE, stride*sizeof(GLfloat), (GLvoid*)dataOffset);
	glEnableVertexAttribArray(attributeLocation);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

GLuint VertexBuffer::getVAO(){
	return VAO;
}
VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &bufferId);
}
