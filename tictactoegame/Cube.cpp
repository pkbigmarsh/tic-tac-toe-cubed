#include "MyUtils.h"
#include "GLUtils.h"
#include "MyClasses.h"

Cube::Cube()
{
	faces = new Face[6];
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

	temp.set(-.5, .5, .5);
	vertices[1][0][0] = temp;
	temp.set(.5, .5, .5);
	vertices[1][0][1] = temp;
	temp.set(-.5, -.5, .5);
	vertices[1][1][0] = temp;
	temp.set(.5, -.5, .5);
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
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();

	for(int i = 0; i < 6; i ++)
		faces[i].draw();

	//glTranslated(translate[0], translate[1], translate[2]);

	//glScaled(scale[0], scale[1], scale[2]);

	//glRotated(rotate[0], 1.0, 0.0, 0.0);
	//glRotated(rotate[1], 0.0, 1.0, 0.0);
	//glRotated(rotate[2], 0.0, 0.0, 1.0);
	
	Point temp;

	glBindTexture(GL_TEXTURE_2D, faces[0].getName());
	glBegin(GL_QUADS);
		temp = vertices[0][1][0];
		glTexCoord2f(0, 0); glVertex3f(temp[0], temp[1], temp[2]);
		temp = vertices[0][0][0];
		glTexCoord2f(0, 1); glVertex3f(temp[0], temp[1], temp[2]);
		temp = vertices[0][0][1];
		glTexCoord2f(1, 1); glVertex3f(temp[0], temp[1], temp[2]);
		temp = vertices[0][1][1];
		glTexCoord2f(1, 0); glVertex3f(temp[0], temp[1], temp[2]);
	glEnd();
	
	glPopMatrix();
}
