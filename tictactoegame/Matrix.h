#ifndef MATIRX_H
#define MATRIX_H

#include "Point.h"

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

	void translate(float, float, float);
	void rotate(float, float, float);
	void scale(float, float, float);

	Matrix operator*(Matrix);
	Point operator*(Point);
	void operator*=(Matrix);
	void operator=(Matrix);
};

#endif