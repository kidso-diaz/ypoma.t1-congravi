#include<GL/glut.h>
#include <math.h>

void fondo() {
	glBegin(GL_POLYGON);
	glColor3ub(160, 0, 0);
	glVertex2d(0, 28);
	glVertex2d(0, 26);
	glEnd();
}

void mapas()
{
}

void dibujar() {

	// Previa
	glLoadIdentity();
	gluOrtho2D(0, 26, 0, 28);
	glClear(GL_COLOR_BUFFER_BIT);

	// Figuras
	fondo();
	mapas();

	// Destruye
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(678, 723);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("T1");
	glutDisplayFunc(dibujar);
	glutMainLoop();

	return 0;
}
