#ifndef RGBPIXMAP_H
#define RGBPIXMAP_H

#include "GLUtils.h"

class RGBpixmap
{
private:
	int nRows, nCols;

	bool inRange(int row, int col);

public:
	int maxRow;
	int maxCol;
	
	mRGB* pixel;

	RGBpixmap();
	RGBpixmap(int, int);
	~RGBpixmap();

	void outline();
	void outline(mRGB color);
	bool set(int row, int col, mRGB);
	mRGB at(int row, int col);
	void setTexture(int);
	void clear();
	void clear(mRGB);

	void drawLine(int sRow, int sCol, int eRow, int eCol, int width, mRGB);
	void drawCircle(int sRow, int sCol, int radius, int width, mRGB);
};

#endif