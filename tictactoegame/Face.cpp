#include "MyClasses.h"
#include "MyUtils.h"

Face::Face()
{
	for(int i = 0; i < 3; i ++)
		for(int j = 0; j < 3; j ++)
			grid[i][j] = 0;
	selRow = -1;
	selCol = -1;
	CT.clear();
	outline.clear();
	isComplete = false;
	holder = 0;
}

Face::Face(vector<Point> ol)
{
	Face();
	outline = ol;
}

bool Face::isEqual(char * list)
{
	return (list[0] == list[1] && list[0] == list[2] && list[0] != 0);
}

bool Face::checkCompleteness()
{
	bool three = true;
	char temp[3];
	for(int i = 0; i < 3; i ++)
	{
		if(isEqual(grid[i]))
		{
			holder = grid[i][0];
			isComplete = true;
			return true;
		}
		for(int j = 0; j < 3; j ++)
			temp[j] = grid[j][i];
		if(isEqual(temp))
		{
			holder = temp[0];
			isComplete = true;
			return true;
		}
	}

	temp[0] = grid[0][0];
	temp[1] = grid[1][1];
	temp[1] = grid[2][2];
	if(isEqual(temp))
	{
		holder = temp[0];
		isComplete = true;
		return true;
	}

	temp[0] = grid[0][2];
	temp[1] = grid[1][1];
	temp[1] = grid[2][0];
	if(isEqual(temp))
	{
		holder = temp[0];
		isComplete = true;
		return true;
	}

	return false;
}

bool Face::isOpen(int row, int col)
{
	return (grid[row][col] == 0);
}

bool Face::closerThan(Face other)
{
	return false;
}

void Face::draw()
{

}

void Face::setPoints(vector<Point> ol)
{
	outline = ol;
}

void Face::highlight(float x, float y)
{

}

void Face::clearHighlight()
{
	selRow = -1;
	selCol = -1;
}

void Face::rotate(float ax, float ay, float az)
{
	CT.rotate(ax, ay, az);
}

void Face::translate(float tx, float ty, float tz)
{
	CT.translate(tx, ty, tz);
}

void Face::scale(float sx, float sy, float sz)
{
	CT.scale(sx, sy, sz);
}