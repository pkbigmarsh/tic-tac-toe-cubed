#ifndef POINT_H
#define POINT_H

class Point
{
private:
	float p[4];//{x, y, z, 1}

public:
	
	Point();
	Point(float, float, float);

	float at(int);
	void set(float x, float y, float z);
	bool set(float, int);

	float operator[](const int);
};

#endif