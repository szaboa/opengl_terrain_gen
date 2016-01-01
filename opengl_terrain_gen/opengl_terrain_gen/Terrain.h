#pragma once
#include "Vec3f.h"
class Terrain
{
private:
	int width; 
	int length;
	float** heights; 
	Vec3f** normals;
	bool computedNormals; //Whether normals is up-to-date
public:
	Terrain(int width, int length);
	int getWidth();
	int getLength();

	void setHeight(int x, int z, float y);
	float getHeight(int x, int z);
	void computeNormals();
	Vec3f getNormal(int x, int z);
	~Terrain();
};

