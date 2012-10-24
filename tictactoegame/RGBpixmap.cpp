#include "MyClasses.h"
#include "GLUtils.h"
#include "MyUtils.h"

RGBpixmap::RGBpixmap()
{
	nRows = nCols = maxRow = maxCol = 0;
	pixel = 0;
}

RGBpixmap::RGBpixmap(int nR, int nC)
{
	nRows = nR;
	nCols = nC;
	maxRow = nR - 1;
	maxCol = nC - 1;
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

void RGBpixmap::clear()
{
	RGB color;
	color.r = color.b = color.g = 255;
	clear(color);
}

bool RGBpixmap::inRange(int row, int col)
{
	return !(row < 0 || row >= nRows || col < 0 || col >= nCols);
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
	if(!inRange(sRow, sCol))
		return;
	if(!inRange(eRow, eCol))
		return;
	width --;
	if(eRow < sRow)
	{
		int temp = sRow;
		eRow = sRow;
		sRow = temp;
	}
	if(eCol  < sCol)
	{
		int temp = sCol;
		eCol = sCol;
		sCol = temp;
	}
	double dy = (double) (eCol - sCol);
	double dx = (double) (eRow - sRow);
	if(dy == 0)
	{
		for(int i = sRow; i < eRow; i ++)
			for(int j = sCol; j + width; j ++)
				set(i, j, color);
	}
	else if(dx == 0)
	{
		for(int i = sCol; i < eCol; i ++)
			for(int j = sRow; j + eRow; j ++)
				set(j, i, color);
	}
	else
	{
		double slope = dy / dx;
		if(abs(atan(slope)) < (PI / 4))
		{
			double y = sRow;
			for(int i = sCol; i < eCol; i ++, y += slope)
				for(int j = y; j < y + width; j ++)
					set(j, i, color);
		}
		else
		{
			double y = sRow;
			for(int i = sCol; i < eCol; i ++, y += slope)
				for(int j = i; j < i + width; i ++)
					set(y, j, color);
		}
	}
}

void RGBpixmap::drawCircle(int sRow, int sCol, int radius, int width, RGB color)
{
	if(!inRange(sRow, sCol))
		return;
	if(!inRange(sRow + radius, sCol + radius))
		return;
	if(!inRange(sRow - radius, sCol - radius))
		return;
	int nr, nc = 0;
	int pr, pc = 0;
	pr = sRow;
	pc = sCol + radius;
	for(float angle = 3; angle <= 360; angle += 3)
	{
		nr = sRow + radius * sin(angle);
		nc = sCol + radius * cos(angle);
		drawLine(pr, pc, nr, nc, width, color);
		pr = nr;
		pc = nc;
	}
}