#ifndef FACE_H
#define FACE_H

#include <vector>
using namespace std;

class Face
{
private:
	char grid[3][3];
	Matrix CT;
	vector<Point> outline;
	int selRow;
	int selCol;

	bool isEqual(char *);

public:
	bool isComplete;
	char holder;

	Face();
	Face(vector<Point>);

	bool checkCompleteness();
	bool isOpen(int row, int col);
	bool closerThan(Face);

	void draw();
	void setPoints(vector<Point>);
	void highlight(float x, float y);
	void clearHighlight();

	void rotate(float, float, float);
	void translate(float, float, float);
	void scale(float, float, float);

};


#endif