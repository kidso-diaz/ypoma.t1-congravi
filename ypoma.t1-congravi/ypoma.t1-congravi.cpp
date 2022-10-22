#include<GL/glut.h>
#include <math.h>

// Colores
#define COLOR_AZUL 0

// Direccion
#define ARRIBA 0
#define DERECHA 1
#define ABAJO 2
#define IZQUIERDA 3

// Medidas independientes
#define X0	1.5
#define Y0	1.5

#define B	1.0 // Borde
#define C	2.0 // Ancho de camino

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

void establecerColor(int color)
{
	switch (color)
	{
	case COLOR_AZUL:
		glColor3ub(0, 49, 253);
		break;
	}
}

void imprimirFondo() {
	glBegin(GL_POLYGON);
	glColor3ub(160, 0, 0);
	glVertex2d(0, 28);
	glVertex2d(0, 26);
	glEnd();
}

void iniciarPoligono(int x, int y)
{
	glBegin(GL_LINE_STRIP);
	glVertex2d(x, y);
}

void terminarPoligono()
{
	glEnd();
}

void moverArriba(int& x, int& y, int movimiento)
{
	y += movimiento;
	glVertex2d(x, y);
}

void moverAbajo(int& x, int& y, int movimiento)
{
	y -= movimiento;
	glVertex2d(x, y);
}

void moverIzquierda(int& x, int& y, int movimiento)
{
	x -= movimiento;
	glVertex2d(x, y);
}

void moverDerecha(int& x, int& y, int movimiento)
{
	x += movimiento;
	glVertex2d(x, y);
}

void crearRectanguloDesdeOrigen(int xOrigen, int yOrigen, int base, int altura)
{
	int x = xOrigen, y = yOrigen;
	iniciarPoligono(x, y);
	moverDerecha(x, y, base);
	moverArriba(x, y, altura);
	moverIzquierda(x, y, base);
	moverAbajo(x, y, altura);
	terminarPoligono();
}

void bloque1(int xOrigen, int yOrigen)
{
	// Linea 1
	int x = xOrigen, y = yOrigen;
	iniciarPoligono(x, y);

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

	terminarPoligono();
}

void islaTipoA1(int xOrigen, int yOrigen)
{
	// Linea 1
	int x = xOrigen, y = yOrigen;
	iniciarPoligono(x, y);
	moverDerecha(x, y, C + B + C + B + C);
	moverArriba(x, y, B);
	moverIzquierda(x, y, C);
	moverArriba(x, y, C + B);
	moverIzquierda(x, y, B);
	moverAbajo(x, y, B + C);
	moverIzquierda(x, y, C + B + C);
	moverAbajo(x, y, B);
	terminarPoligono();
}

void islaTipoA2(int xOrigen, int yOrigen)
{
	// Linea 1
	int x = xOrigen, y = yOrigen;
	iniciarPoligono(x, y);
	moverDerecha(x, y, C + B + C + B + C);
	moverArriba(x, y, B);
	moverIzquierda(x, y, C + B + C);
	moverArriba(x, y, C + B);
	moverIzquierda(x, y, B);
	moverAbajo(x, y, B + C);
	moverIzquierda(x, y, C);
	moverAbajo(x, y, B);
	terminarPoligono();
}

void imprimirMapas()
{
	bloque1(X0, Y0);
	crearRectanguloDesdeOrigen(X0 + B, Y0 + H1 - (Q2 + B), PX - 2 * B, Q2);
	crearRectanguloDesdeOrigen(X0 + L - (B + C + P1), Y0 + H1 - (Q2 + B), PX - 2 * B, Q2);
	islaTipoA1(X0 + B + C, Y0 + B + C);
	islaTipoA2(X0 + B + C + C + B + C + B + C + C + B + C, Y0 + B + C);
}

void dibujar()
{
	// Previa
	glLoadIdentity();
	gluOrtho2D(0, CANVA_X, 0, 28);
	glClear(GL_COLOR_BUFFER_BIT);

	// Figuras
	imprimirFondo();

	establecerColor(COLOR_AZUL);
	imprimirMapas();

	// Destruye
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(900, 900);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("T1");
	glutDisplayFunc(dibujar);
	glutMainLoop();

	return 0;
}
