#include<GL/glut.h>
#include <math.h>

// Medidas independientes
#define X0	1.5
#define Y0	1.5

#define B	1.0 // Borde
#define C	2.0

#define P1	2.5
#define P2	4.0
#define Q1	1.0
#define Q2	1.5

// Medidas dependientes
#define PX	B + P2 + B
#define QX	B + Q2 + B

#define H1	(B + C + B + C + B + C + B + C + B + C)
#define L	(B + C + P1 + C + P2 + C) + B + (C + P2 + C + P1 + C + B)

#define CANVA_X	L + 2 * X0

void fondo() {
	glBegin(GL_POLYGON);
	glColor3ub(160, 0, 0);
	glVertex2d(0, 28);
	glVertex2d(0, 26);
	glEnd();
}

void moverArriba(int& xAnterior, int& yAnterior, int movimiento)
{
	yAnterior += movimiento;
	glVertex2d(xAnterior, yAnterior);
}

void moverAbajo(int& xAnterior, int& yAnterior, int movimiento)
{
	yAnterior -= movimiento;
	glVertex2d(xAnterior, yAnterior);
}

void moverIzquierda(int& xAnterior, int& yAnterior, int movimiento)
{
	xAnterior -= movimiento;
	glVertex2d(xAnterior, yAnterior);
}

void moverDerecha(int& xAnterior, int& yAnterior, int movimiento)
{
	xAnterior += movimiento;
	glVertex2d(xAnterior, yAnterior);
}

void bloque1()
{
	// Linea 1
	int x = X0, y = Y0;
	glBegin(GL_LINE_STRIP);
	glColor3ub(0, 49, 253); // Color RGB ▲▼◄►

	// Inicio
	glVertex2d(x, y);
	moverDerecha(x, y, L);
	moverArriba(x, y, H1);

	// Gokú
	moverIzquierda(x, y, PX);
	moverAbajo(x, y, QX);
	moverDerecha(x, y, PX - B);

	moverAbajo(x, y, C + B + C);

	// Gohan
	moverIzquierda(x, y, C);
	moverAbajo(x, y, B);
	moverDerecha(x, y, C);

	// Vuelta
	moverAbajo(x, y, C + B + C);
	moverIzquierda(x, y, L - B - B);
	moverArriba(x, y, C + B + C);

	// Goten
	moverDerecha(x, y, C);
	moverArriba(x, y, B);
	moverIzquierda(x, y, C);

	// Vuelta
	moverArriba(x, y, C + B + C);

	// Vegeta
	moverDerecha(x, y, PX - B);
	moverArriba(x, y, QX);
	moverIzquierda(x, y, PX);

	moverAbajo(x, y, H1);

	glEnd();
}

void mapas()
{
	bloque1();
}

void dibujar() {

	// Previa
	glLoadIdentity();
	gluOrtho2D(0, CANVA_X, 0, 28);
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
	glutInitWindowSize(900, 723);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("T1");
	glutDisplayFunc(dibujar);
	glutMainLoop();

	return 0;
}
