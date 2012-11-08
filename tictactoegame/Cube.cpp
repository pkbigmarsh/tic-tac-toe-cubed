#include "MyUtils.h"
#include "GLUtils.h"
#include "MyClasses.h"

Cube::Cube()
{
	/********** Setting up the faces **********/
	faces = new Face[6];
	
	/********** Face Color **********/
	faces[0].outlineColor.r = 128;
	faces[0].outlineColor.g = 255;
	faces[0].outlineColor.b = 255;

	faces[1].outlineColor.r = 0;
	faces[1].outlineColor.g = 255;
	faces[1].outlineColor.b = 255;

	faces[2].outlineColor.r = 0;
	faces[2].outlineColor.g = 64;
	faces[2].outlineColor.b = 128;

	faces[3].outlineColor.r = 0;
	faces[3].outlineColor.g = 0;
	faces[3].outlineColor.b = 255;

	faces[4].outlineColor.r = 0;
	faces[4].outlineColor.g = 0;
	faces[4].outlineColor.b = 128;

	faces[5].outlineColor.r = 64;
	faces[5].outlineColor.g = 128;
	faces[5].outlineColor.b = 128;



	for(int i = 0; i < 6; i ++)
		faces[i].setName(10 + i);
	//CT.clear();
	x = y = z = 0;
	winner = 0;

	Point temp;

	for(int i = 0; i < 3; i ++)
	{
		scale[i] = 1;
		translate[3] = 0;
		rotate[3] = 0;
	}

	temp.set(-.5, .5, -.5);
	vertices[0][0][0] = temp;
	temp.set(.5, .5, -.5);
	vertices[0][0][1] = temp;
	temp.set(-.5, -.5, -.5);
	vertices[0][1][0] = temp;
	temp.set(.5, -.5, -.5);
	vertices[0][1][1] = temp;

	temp.set(-.5, .5, +.5);
	vertices[1][0][0] = temp;
	temp.set(.5, .5, +.5);
	vertices[1][0][1] = temp;
	temp.set(-.5, -.5, +.5);
	vertices[1][1][0] = temp;
	temp.set(.5, -.5, +.5);
	vertices[1][1][1] = temp;
}

Cube::~Cube()
{
	delete faces;
}

void Cube::rotatef(float ax, float ay, float az)
{
	rotate[0] += ax;
	rotate[1] += ay;
	rotate[2] += az;
}

void Cube::draw()
{
	
	glEnable( GL_TEXTURE_2D );
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();

	for(int i = 0; i < 6; i ++)
		faces[i].draw();

	
	

	/********** Transformations **********/
	glTranslated(translate[0], translate[1], translate[2]);

	glScaled(scale[0], scale[1], scale[2]);

	glRotated(rotate[0], 1.0, 0.0, 0.0);
	glRotated(rotate[1], 0.0, 1.0, 0.0);
	glRotated(rotate[2], 0.0, 0.0, 1.0);
	
	/********** Declaring the outline points **********/

	Point temp;

	Point p1 = vertices[0][1][0];
	Point p2 = vertices[0][0][0];
	Point p3 = vertices[0][0][1];
	Point p4 = vertices[0][1][1];
	Point p5 = vertices[1][1][0];
	Point p6 = vertices[1][0][0];
	Point p7 = vertices[1][0][1];
	Point p8 = vertices[1][1][1];

	//glutSolidCube(1);
	//glColor3d(0, 0, 0);
	//glutWireCube(1.1);
	
	/********** Face 0 **********/
	glBindTexture(GL_TEXTURE_2D, faces[0].getName());
	glBegin(GL_QUADS);
		temp = p1;
		glTexCoord2f(0, 0); glVertex3f(temp[0], temp[1], temp[2]);
		temp = p2;
		glTexCoord2f(0, 1); glVertex3f(temp[0], temp[1], temp[2]);
		temp = p3;
		glTexCoord2f(1, 1); glVertex3f(temp[0], temp[1], temp[2]);
		temp = p4;
		glTexCoord2f(1, 0); glVertex3f(temp[0], temp[1], temp[2]);
	glEnd();

	/********** Face 1 **********/
	glBindTexture(GL_TEXTURE_2D, faces[1].getName());
	glBegin(GL_QUADS);
		temp = p2;
		glTexCoord2f(0, 0); glVertex3f(temp[0], temp[1], temp[2]);
		temp = p6;
		glTexCoord2f(0, 1); glVertex3f(temp[0], temp[1], temp[2]);
		temp = p7;
		glTexCoord2f(1, 1); glVertex3f(temp[0], temp[1], temp[2]);
		temp = p3;
		glTexCoord2f(1, 0); glVertex3f(temp[0], temp[1], temp[2]);
	glEnd();

	/********** Face 2 **********/
	glBindTexture(GL_TEXTURE_2D, faces[2].getName());
	glBegin(GL_QUADS);
		temp = p6;
		glTexCoord2f(0, 0); glVertex3f(temp[0], temp[1], temp[2]);
		temp = p5;
		glTexCoord2f(0, 1); glVertex3f(temp[0], temp[1], temp[2]);
		temp = p8;
		glTexCoord2f(1, 1); glVertex3f(temp[0], temp[1], temp[2]);
		temp = p7;
		glTexCoord2f(1, 0); glVertex3f(temp[0], temp[1], temp[2]);
	glEnd();

	/********** Face 3 **********/
	glBindTexture(GL_TEXTURE_2D, faces[3].getName());
	glBegin(GL_QUADS);
		temp = p5;
		glTexCoord2f(0, 0); glVertex3f(temp[0], temp[1], temp[2]);
		temp = p1;
		glTexCoord2f(0, 1); glVertex3f(temp[0], temp[1], temp[2]);
		temp = p4;
		glTexCoord2f(1, 1); glVertex3f(temp[0], temp[1], temp[2]);
		temp = p8;
		glTexCoord2f(1, 0); glVertex3f(temp[0], temp[1], temp[2]);
	glEnd();

	/********** Face 4 **********/
	glBindTexture(GL_TEXTURE_2D, faces[4].getName());
	glBegin(GL_QUADS);
		temp = p7;
		glTexCoord2f(0, 0); glVertex3f(temp[0], temp[1], temp[2]);
		temp = p8;
		glTexCoord2f(0, 1); glVertex3f(temp[0], temp[1], temp[2]);
		temp = p4;
		glTexCoord2f(1, 1); glVertex3f(temp[0], temp[1], temp[2]);
		temp = p3;
		glTexCoord2f(1, 0); glVertex3f(temp[0], temp[1], temp[2]);
	glEnd();

	/********** Face 5 **********/
	glBindTexture(GL_TEXTURE_2D, faces[5].getName());
	glBegin(GL_QUADS);
		temp = p2;
		glTexCoord2f(0, 0); glVertex3f(temp[0], temp[1], temp[2]);
		temp = p1;
		glTexCoord2f(0, 1); glVertex3f(temp[0], temp[1], temp[2]);
		temp = p5;
		glTexCoord2f(1, 1); glVertex3f(temp[0], temp[1], temp[2]);
		temp = p6;
		glTexCoord2f(1, 0); glVertex3f(temp[0], temp[1], temp[2]);
	glEnd();
	
	glPopMatrix();
}
