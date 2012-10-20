#include "MyUtils.h"

#include <iostream>

using namespace std;

void printMatrix(Matrix m)
{
	for(int r = 0; r < 4; r ++)
	{
		for(int c = 0; c < 3; c ++)
			cout << m.at(r,c) << ", ";
		cout << m.at(r,3) << endl;
	}
	cout << endl;
}

void printPoint(Point p)
{
	for(int i = 0; i < 3; i ++)
		cout << p[i] << ", ";
	cout << p[3] << endl << endl;;
}

void main()
{
	float r1[4];
	float r2[4];
	float r3[4];
	r1[0] = r1[1] = r1[2] = r1[3] = 1;
	r2[0] = r2[1] = r2[2] = r2[3] = 2;
	r3[0] = r3[1] = r3[2] = r3[3] = 0;


	Matrix m(r1, r2, r3, r3);
	Point p;
	p.set(1.0f, 2.0f, 3.0f);
	Matrix m2(r1, r2, r3, r3);

	printMatrix(m);
	printMatrix(m2);
	printPoint(p);
	printPoint(m*p);
	printMatrix(m*m2);
	
}