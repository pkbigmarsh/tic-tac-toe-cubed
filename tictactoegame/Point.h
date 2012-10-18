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
	void set(float, float, float);
	bool set(float, int);

	float operator[](const int index);
};

#endif