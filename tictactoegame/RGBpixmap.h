#ifndef RGBPIXMAP_H
#define RGBPIXMAP_H

#include "GLUtils.h"

class RGBpixmap
{
private:
	int nRows, nCols;
	RGB* pixel;

public:
	RGBpixmap();
	RGBpixmap(int, int);
	~RGBpixmap();

	bool set(int row, int col, RGB);
	RGB at(int row, int col);
	void setTexture(int);
	void clear(RGB);

	void drawLine(int, int, int, int, int, RGB);
	void drawCircle(int, int, int, int, RGB);
};

#endif