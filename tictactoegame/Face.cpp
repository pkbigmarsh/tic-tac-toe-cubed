#include "MyClasses.h"
#include "MyUtils.h"

Face::Face()
{
	for(int i = 0; i < 3; i ++)
		for(int j = 0; j < 3; j ++)
			grid[i][j] = 0;
	selRow = -1;
	selCol = -1;
	isComplete = false;
	holder = 'X';
	textLoc = 2000;
	pic = new RGBpixmap(128, 128);
}

Face::Face(int loc)
{
	Face();
	textLoc = loc;
}

Face::~Face()
{
	delete pic;
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

bool Face::set(int row, int col, char player)
{
	if(!isOpen(row,col))
		return false;
	grid[row][col] = player;
	checkCompleteness();
	return true;
}

void Face::drawHighlight()
{
	RGB color;
	color.r = color.g = 255;
	color.b = 0;
	int ur = pic->maxRow;
	int uc = pic->maxCol;
	if(selRow == 0 && selCol == 0)
	{
		pic->drawLine(ur - 0, 40, ur - 44, 40, 4, color); // Top Left Vertical
		pic->drawLine(ur - 44, 0, ur - 44, 44, 4, color); // Top Left horizontal
	}
	else if(selRow == 0 && selCol == 1)
	{
		pic->drawLine(ur - 0, 40, ur - 44, 40, 4, color); // Top Left Vertical
		pic->drawLine(ur - 0, 84, ur - 44, 84, 4, color); // Top Right Vertical
		pic->drawLine(ur - 44, 40, ur - 40, 88, 4, color); // Top Middle Horizontal
	}
	else if(selRow == 0 && selCol == 2)
	{
		pic->drawLine(ur - 0, 84, ur - 44, 84, 4, color); // Top Right Vertical
		pic->drawLine(ur - 44, 84, ur - 44, uc, 4, color); // Top Right Horizontal
	}
	else if(selRow == 1 && selCol == 0)
	{
		pic->drawLine(ur - 44, 0, ur - 44, 44, 4, color); // Top Left horizontal
		pic->drawLine(40, 0, 40, 44, 4, color); // Lower Left horizontal
		pic->drawLine(40, 40, 88, 40, 4, color); // Middle Left Vertical
	}
	else if(selRow == 1 && selCol == 1)
	{
		pic->drawLine(ur - 44, 40, ur - 40, 88, 4, color); // Top Middle Horizontal
		pic->drawLine(40, 40, 88, 40, 4, color); // Middle Left Vertical
		pic->drawLine(40, 40, 40, 88, 4, color); // Lower Middle Horizontal
		pic->drawLine(40, 84, 88, 84, 4, color); // Middle Right Vertical
	}
	else if(selRow == 1 && selCol == 2)
	{
		pic->drawLine(ur - 44, 84, ur - 44, uc, 4, color); // Top Right Horizontal
		pic->drawLine(40, 84, 88, 84, 4, color); // Middle Right Vertical
		pic->drawLine(40, 84, 40, uc, 4, color); // Lower Right Horizontal
	}
	else if(selRow == 2 && selCol == 0)
	{
		pic->drawLine(40, 0, 40, 44, 4, color); // Lower Left horizontal
		pic->drawLine(0, 40, 44, 40, 4, color); // Lower Left Vertical
	}
	else if(selRow == 2 && selCol == 1)
	{	
		pic->drawLine(0, 40, 44, 40, 4, color); // Lower Left Vertical
		pic->drawLine(40, 40, 40, 88, 4, color); // Lower Middle Horizontal
		pic->drawLine(0, 84, 44, 84, 4, color); // Lower Right Vertical
	}
	else if(selRow == 2 && selCol == 2)
	{
		pic->drawLine(0, 84, 44, 84, 4, color); // Lower Right Vertical
		pic->drawLine(40, 84, 40, uc, 4, color); // Lower Right Horizontal	
	}
}

void Face::draw()
{
	pic->clear();
	RGB black;
	RGB blue;
	RGB green;

	black.r = black.g = black.b = 0;

	green.r = green.b = 0;
	green.g = 255;

	blue.r = blue.g = 0;
	blue.b = 255;

	if(!isComplete)
	{
		
		/***** Draw the Tic Tac Toe Board *****/
		int buffer = 0;
		for(int i = 0; i < 2; i ++)
		{
			buffer = (i+1) * 40 + (i*4);
			pic->drawLine(0, buffer, pic->maxRow, buffer, 4, black); // Vertical
			pic->drawLine(buffer, 0, buffer, pic->maxCol, 4, black); // Horizontal
		}

		/***** Draw the Players boxes *****/
		for(int r = 0; r < 3; r ++)
		{
			for(int c = 0; c < 3; c ++)
			{
				int ulr = (2 - r) * 44;
				int ulc = c * 44;
				if(grid[r][c] == 'X')
				{
					pic->drawLine(ulr - 5, ulc + 5, ulr - 35, ulc + 35, 2, blue);
					pic->drawLine(ulr - 35, ulc + 5, ulr - 5, ulc + 35, 2, blue);
				}
				else if(grid[r][c] == 'O')
				{
					pic->drawCircle(ulr - 20, ulc + 20, 15, 2, green);
				}
			}
		}
	} /***** Draw the Winner of the Face if there is One *****/
	else if(holder == 'X') 
	{
		pic->drawLine(pic->maxRow - 5, 5, 5, pic->maxCol - 5, 4, blue);
		pic->drawLine(5, 5 ,pic->maxRow - 5, pic->maxCol - 5, 4, blue);
	}
	else if(holder == 'O')
	{
		int r = pic->maxRow / 2;
		int c = pic->maxCol / 2;
		pic->drawCircle(r,c,((r < c) ? r - 5 : c - 5), 4, green); 
	}
	

	bind();
}


void Face::highlight(float x, float y)
{
	int r3 = pic->maxRow / 3;
	int c3 = pic->maxCol / 3;

	if(x < c3)
		selCol = 0;
	else if(x < c3 * 2)
		selCol = 1;
	else
		selCol = 2;
	if(y < r3 )
		selRow = 0;
	else if(y < r3 * 2)
		selRow = 1;
	else
		selRow = 2;
}

void Face::clearHighlight()
{
	selRow = -1;
	selCol = -1;
}

void Face::setName(int name)
{
	textLoc = name;
}

void Face::bind()
{
	pic->setTexture(textLoc);
}

int Face::getName()
{
	return textLoc;
}
