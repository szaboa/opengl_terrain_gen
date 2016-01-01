#pragma once
#include "Vec3f.h"
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include <iostream>
#include <SOIL.h>
#include "Shader.h"

class Terrain
{
private:
	int width; 
	int height;
	int numElements;
	VertexBuffer *vertexBuffer;
	IndexBuffer *indexBuffer;
	Shader *shader;
	std::vector<Vec3f> vertices;
	std::vector<short> indexes;
	int calculateNumElements();
	int rgbToGrayscale(int r, int g, int b);
	void createVertexData(const char* imagePath);
	void createIndexData();

public:
	Terrain(const char* imagePath);
	void bindData();
	void draw();
	int getWidth();
	int getHeight();
	Shader* getShader();
	void setUniforms(glm::mat4 matrix);
	~Terrain();
};

