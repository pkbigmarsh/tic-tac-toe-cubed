#include "MyClasses.h"
#include "GLUtils.h"
#include "MyUtils.h"

RGBpixmap::RGBpixmap()
{
	nRows = nCols = 0;
	pixel = 0;
}

RGBpixmap::RGBpixmap(int nR, int nC)
{
	nRows = nR;
	nCols = nC;
	pixel = new RGB[nRows * nCols];
}

RGBpixmap::~RGBpixmap()
{
	delete pixel;
}

bool RGBpixmap::set(int row, int col, RGB p)
{
	if(row < 0 || row >= nRows || col < 0 || col >= nCols)
		return false;
	pixel[row * nCols + col] = p;
	return true;
}

RGB RGBpixmap::at(int row, int col)
{
	return pixel[row * nCols + col];
}

void RGBpixmap::clear(RGB color)
{
	int pos = 0;
	for(int i = 0; i < nRows; i ++)
		for(int j = 0; j < nCols; j ++)
			pixel[pos ++] = color;
}

void RGBpixmap::setTexture(int name)
{
	glBindTexture(GL_TEXTURE_2D, name);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, nCols, nRows, 0, GL_RGB, GL_UNSIGNED_BYTE, pixel);
}

void RGBpixmap::drawLine(int sRow, int sCol, int eRow, int eCol, int width, RGB color)
{
	width --;
	double slope = ((double) (eRow - sRow)) / ((double) (eCol - sCol));
	double y = sCol;
	for(int i = sCol; i < eCol; i ++, y += slope)
		for(int j = y - width; j < y + width; j ++)
			set(j, i, color);
}

void RGBpixmap::drawCircle(int sRow, int sCol, int radius, int width, RGB color)
{
	int r,c = 0;
	for(float angle = 0; angle <= 360; angle ++)
	{
		r = radius * sin(angle);
		c = radius * cos(angle);
		for(int j = r - width; j < r + width; j ++)
			set(j, c, color);
	}
}