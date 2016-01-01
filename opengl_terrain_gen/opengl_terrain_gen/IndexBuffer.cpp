#include "IndexBuffer.h"


IndexBuffer::IndexBuffer(std::vector<short> indexes)
{
	glGenBuffers(1, &bufferId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexes.size()*sizeof(short), &indexes.front(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::setVertexAttribPointer(int dataOffset, int attributeLocation, int componentCount, int stride){
	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	glVertexAttribPointer(attributeLocation, componentCount, GL_FLOAT, GL_FALSE, stride, (GLvoid*)dataOffset);
	glEnableVertexAttribArray(attributeLocation);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

GLuint IndexBuffer::getBufferId(){
	return bufferId;
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &bufferId);
}
