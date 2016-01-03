#include "Terrain.h"



Terrain::Terrain(const char* imagePath){
	createVertexData(imagePath);
	createIndexData();

	numElements = calculateNumElements();

	std::cout << "num elements: " << numElements << std::endl;


	vertexBuffer = new VertexBuffer(vertices);
	indexBuffer = new IndexBuffer(indexes);

	shader = new Shader("shaders/heightmap_vertex_shader.glsl", "shaders/heightmap_fragment_shader.glsl");

}

Shader* Terrain::getShader(){
	return shader;
}

void Terrain::setUniforms(glm::mat4 matrix){
	//std::cout << matrix.x;
	GLint u_MatrixLoc = glGetUniformLocation(shader->Program, "u_Matrix");
	glUniformMatrix4fv(u_MatrixLoc, 1, GL_FALSE, glm::value_ptr(matrix));
}

void Terrain::bindData(){

	// offset 0
	// second param location inside vertex shader
	// a vertex containing three coords
	vertexBuffer->setVertexAttribPointer(0, 0, 3, 3);
}

void Terrain::draw(){
	// use shader

	//glBindVertexArray(vertexBuffer->getVAO());
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer->getBufferId());
	glDrawElements(GL_TRIANGLES, indexes.size(), GL_UNSIGNED_SHORT, 0);
	//glDrawArrays(GL_TRIANGLES, 0, vertices.size());
	//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glDisableVertexAttribArray(0);
}

int Terrain::calculateNumElements(){
	return (width - 1)*(height - 1) * 2 * 3;
}
void Terrain::createVertexData(const char* imagePath){
	unsigned char* image = SOIL_load_image(imagePath, &width, &height, 0, SOIL_LOAD_RGB);
	std::cout << "Width: " << width << " Height: " << height << std::endl;

	for (int row = 0; row < height; row++){
		for (int col = 0; col < width; col++){
			unsigned char r = image[(col + row * width) * 3 + 0];
			unsigned char g = image[(col + row * width) * 3 + 1];
			unsigned char b = image[(col + row * width) * 3 + 2];
			int gValue = rgbToGrayscale((int)r, (int)g, (int)b);
			float xpos = ((float)col / (float)(width - 1)) - 0.5f;
			float ypos = (float)gValue / (float)255;
			float zpos = ((float)row / (float)(height - 1)) - 0.5f;

			vertices.push_back(Vec3f(xpos, ypos, zpos));
			//std::cout << Vec3f(xpos, ypos, zpos) << std::endl;
		}
	}

	delete image;
}

void Terrain::createIndexData(){
	for (int row = 0; row < height-1; row++){
		for (int col = 0; col < width-1; col++){
			short topLeftIndexNum = (short)(row*width + col);
			short topRightIndexNum = (short)(row*width + col + 1);
			short bottomLeftIndexNum = (short)((row+1)*width + col);
			short bottomRightIndexNum = (short)((row+1)*width + col + 1);

			// write out two triangles
			indexes.push_back(topLeftIndexNum);
			indexes.push_back(bottomLeftIndexNum);
			indexes.push_back(topRightIndexNum);

			indexes.push_back(topRightIndexNum);
			indexes.push_back(bottomLeftIndexNum);
			indexes.push_back(bottomRightIndexNum);
		}
	}
}


int Terrain::rgbToGrayscale(int r, int g, int b){
	//averaging comp
	return (r + g + b) / 3;

}

int Terrain::getHeight(){
	return height;
}

int Terrain::getWidth(){
	return width;
}
Terrain::~Terrain()
{
	delete vertexBuffer;
	delete indexBuffer;
	delete shader;
}
