#ifndef CUBE_H
#define CUBE_H

#include "Point.h"
#include "Matrix.h"
#include "Face.h"

class Cube
{
private:
	Face * faces;
	Point vertices[2][2][2];
	mRGB faceColors[6];
	//Matrix CT;
	float x, y, z;

	double scale[3]; //0 == x 1 == y 2 == z
	double translate[3];
	double rotate[3];

public:
	char winner;

	Cube();
	~Cube();

	bool isComplete();
	void draw();

	void rotatef(float ax, float ay, float az);
	void translatef(float tx, float ty, float tz);
	void scalef(float sx, float sy, float sz);

	bool hover(float x, float y);
	bool select(float x, float y);
};

#endif