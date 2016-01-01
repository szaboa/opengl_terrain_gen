#include "Terrain.h"


Terrain::Terrain(int width, int length) : width(width), length(length)
{
	heights = new float*[length];
	for (int i = 0; i < length; i++) {
		heights[i] = new float[width];
	}

	normals = new Vec3f*[length];
	for (int i = 0; i < length; i++) {
		normals[i] = new Vec3f[width];
	}

	computedNormals = false;
}

int Terrain::getLength(){
	return length;
}

int Terrain::getWidth(){
	return width;
}

//Sets the height at (x, z) to y
void Terrain::setHeight(int x, int z, float y) {
	heights[z][x] = y;
	computedNormals = false;
}

//Returns the height at (x, z)
float Terrain::getHeight(int x, int z) {
	return heights[z][x];
}

void Terrain::computeNormals(){

}

Vec3f Terrain::getNormal(int x, int z){
	if (!computedNormals) {
		computeNormals();
	}
	return normals[z][x];
}

Terrain::~Terrain()
{
	for (int i = 0; i < length; i++) {
		delete[] heights[i];
	}
	delete[] heights;

	for (int i = 0; i < length; i++) {
		delete[] normals[i];
	}
	delete[] normals;
}
