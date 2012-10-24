#ifndef FACE_H
#define FACE_H

#include "RGBpixmap.h"

class Face
{
private:
	char grid[3][3];
	int selRow;
	int selCol;

	int textLoc;
	RGBpixmap * pic;

	bool isEqual(char *);
	void drawHighlight();


public:
	bool isComplete;
	char holder;

	Face();
	Face(int);
	~Face();

	bool checkCompleteness();
	bool isOpen(int row, int col);
	bool set(int row, int col, char player);

	void draw();
	void bind();
	int getName();
	void highlight(float x, float y);
	void clearHighlight();

};


#endif