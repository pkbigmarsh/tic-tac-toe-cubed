#include "Matrix.h"

Matrix::Matrix()
{
	for(int i = 0; i < 4; i ++)
		for(int j = 0; j < 4; j ++)
			m[i][j] = 0;
	Matrix::setTransformation();
}

Matrix::Matrix(float * r0, float * r1, float * r2, float * r3)
{
	for(int i = 0; i < 4; i ++)
	{
		m[0][i] = r0[i];
		m[1][i] = r1[i];
		m[2][i] = r2[i];
		m[3][i] = r3[i];
	}
}

Matrix::Matrix(float a0, float b0, float c0, float d0, 
			   float a1, float b1, float c1, float d1, 
			   float a2, float b2, float c2, float d2, 
			   float a3, float b3, float c3, float d3)
{
	m[0][0] = a0;
	m[0][1] = b0;
	m[0][2] = c0;
	m[0][3] = d0;

	m[1][0] = a1;
	m[1][1] = b1;
	m[1][2] = c1;
	m[1][3] = d1;

	m[2][0] = a2;
	m[2][1] = b2;
	m[2][2] = c2;
	m[2][3] = d2;

	m[3][0] = a3;
	m[3][1] = b3;
	m[3][2] = c3;
	m[3][3] = d3;
}

float Matrix::at(int row, int col)
{
	return m[row][col];
}

bool Matrix::set(int row, int col, float val)
{
	if(row < 0 || col < 0 || row > 3 || col > 3)
		return false;
	m[row][col] = val;
	return true;
}

void Matrix::setTransformation()
{
	Matrix::clear();
	m[0][0] = 1;
	m[1][1] = 1;
	m[2][2] = 1;
	m[3][3] = 1;
}

void Matrix::clear()
{
	for(int i = 0; i < 4; i ++)
		for(int j = 0; j < 4; j ++)
			m[i][j] = 0;
}

Matrix Matrix::operator *(Matrix m2)
{
	Matrix result;
	result.clear();
	float sum;
	for(int r = 0; r < 4; r ++)
	{
		for(int c = 0; c < 4; c ++)
		{
			sum = 0;
			for(int i = 0; i < 4; i ++)
				sum += m[r][i] * m2.at(i, c);
			result.set(r, c, sum);
		}
	}
	return result;
}

Point Matrix::operator*(Point p)
{
	Point result;
	float sum;
	for(int r = 0; r < 4; r ++)
	{
		sum = 0;
		for(int c = 0; c < 4; c++)
		{
			sum += m[r][c] * p[c];
		}
		result.set(sum, r);
	}
	return result;
}