#ifndef MATIRX_H
#define MATRIX_H

#ifndef POINT_H
#include "Point.h"
#endif

class Matrix
{
private:
	float m[4][4];

public:
	Matrix();
	Matrix(float *, float *, float *, float *);
	Matrix(float, float, float, float,
		float, float, float, float,
		float, float, float, float,
		float, float, float, float);
	
	float at(int row, int col);
	bool set(int row, int col, float);
	void setTransformation();
	void clear();

	Matrix operator*(Matrix);
	Point operator*(Point);
};

#endif