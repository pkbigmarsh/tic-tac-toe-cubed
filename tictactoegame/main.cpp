#include "MyUtils.h"
#include "GLUtils.h"
#include "MyClasses.h"

Cube cube;
float rotateSpeed;

void setWindow(GLdouble left, GLdouble right,
			   GLdouble bottom, GLdouble top,
			   GLdouble zNear, GLdouble zFar)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(left, right, bottom, top, zNear, zFar);
}

void setViewport(GLint left, GLint right,
				 GLint bottom, GLint top)
{
	glViewport(left, bottom, right - left, top - bottom);
}

void setCamera(GLdouble xEye, GLdouble yEye, GLdouble zEye,
			   GLdouble xLook, GLdouble yLook, GLdouble zLook,
			   GLdouble xUp, GLdouble yUp, GLdouble zUp)
{
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	gluLookAt(xEye, yEye, zEye, xLook, yLook, zLook, xUp, yUp, zUp);
}

void render()
{
	setWindow(-2.0 * 64.0/48.0, 2.0 * 64.0/48.0, -2.0, 2.0, 2, -100);
	setViewport(0,0,640,480);
	setCamera(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glEnable( GL_DEPTH_TEST );
	glDepthFunc( GL_LEQUAL );
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	glColor3d(0, 0, 0);

	cube.draw();

	glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == 'a')
		cube.rotatef(0, rotateSpeed, 0);
	if(key == 'd')
		cube.rotatef(0, -rotateSpeed, 0);
	if(key == 'w')
		cube.rotatef(rotateSpeed, 0, 0);
	if(key == 's')
		cube.rotatef(-rotateSpeed, 0, 0);
	if(key == 'e')
		exit(0);
	render();
}
void setTest()
{

}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Tic Tac Toe");

	rotateSpeed = 5;

	glutDisplayFunc(render);
	glutKeyboardFunc(keyboard);

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glutMainLoop();
}

