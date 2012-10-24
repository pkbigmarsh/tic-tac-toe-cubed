#ifndef RGBPIXMAP_H
#define RGBPIXMAP_H

#include "GLUtils.h"

class RGBpixmap
{
private:
	int nRows, nCols;
	RGB* pixel;

	bool inRange(int row, int col);

public:
	int maxRow;
	int maxCol;

	RGBpixmap();
	RGBpixmap(int, int);
	~RGBpixmap();

	bool set(int row, int col, RGB);
	RGB at(int row, int col);
	void setTexture(int);
	void clear();
	void clear(RGB);

	void drawLine(int sRow, int sCol, int eRow, int eCol, int width, RGB);
	void drawCircle(int sRow, int sCol, int radius, int width, RGB);
};

#endif