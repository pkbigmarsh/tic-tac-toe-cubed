#include "Point.h"

Point::Point()
{
	p[0] = p[1] = p[2] = 0.0f;
	p[3] = 1;
}

Point::Point(float x, float y, float z)
{
	p[0] = x;
	p[1] = y;
	p[2] = z;
	p[3] = 1;
}

float Point::at(int index)
{
	return p[index];
}

void Point::set(float x, float y, float z)
{
	p[0] = x;
	p[1] = y;
	p[2] = z;
}

bool Point::set(float value, int index)
{
	if(index < 0 || index > 3)
		return false;
	p[index] = value;
	return true;
}

float Point::operator [](const int index)
{
	return p[index];
}