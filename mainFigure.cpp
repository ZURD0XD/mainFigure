/*
* GRAFICACION - UNIDAD 3
* INTEGRANTES:
* IVAN FRANCO DELGADO
* JESUS EDUARDO SOSA DIAZ
* JOSUE TORRES AVALOS
*/

#include <GL/glut.h>
#include "PrismHexagonal.h"
#include "PrismPentagonal.h"
#include "PrismCuadrangular.h"
#include "PrismTriangular.h"
#include "PyramidPentagonal.h"
#include "PyramidTriangular.h"
#include "PyramidHexagonal.h"
#include "Cube.h"

#define HEIGHT 720
#define WIDTH 1280
int count = 0;

PrismHexagonal prH(-0, 0, 0, 100, 50, 2);
PyramidPentagonal pyP(-60, 0, 0, 100,50);
PyramidTriangular pyT(400, 0, 0, 10, 14);
PyramidHexagonal pyH(600, 0, 0, 10, 14);
PrismPentagonal prP(120, 0, 0, 10, 15, 1);
PrismCuadrangular prC(150, 0, 0, 10, 14, 9);
PrismTriangular prT(180, 0, 0, 20, 10);
Cube cubito(210, 0, 0, 15, 1);
float angle = 0.0;

void initializer(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0); // COLOR CANVAS
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-350.0, 350.0, -350.0, 350.0, -150.0, 150.0);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
}

void idle_cb() {
	angle += 0.05;
	glutPostRedisplay();
}

void displayScreen(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glViewport(150, 150, 300, 300);

	cubito.drawFigure();
	pyT.drawFigure();
	pyH.drawFigure();
	pyP.drawFigure();
	prP.drawFigure();
	prT.drawFigure();
	prC.drawFigure();
	/*glPushMatrix();
		glTranslatef(-250,0,0);
		glRotatef(50.0, 1.0, 1.0, 1.0);
		prH.drawFigure();
	glPopMatrix();*/

	glutSwapBuffers();
}

void teclado_cb(GLubyte key, GLint x, GLint y) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(150, 150, 300, 300);
	switch (key) {
	case 27:
		//exit(1);
		break;
	case 'x':
		// aqu  se procesar a la tecla <x>
		glRotatef(1.0, 1.0, 0.0, 0.0);
		break;
	case 'y':
		// aqu  se procesar a la tecla <y>
		glRotatef(1.0, 0.0, 1.0, 0.0);
		break;
	case 'z':
		// aqu  se procesar a la tecla <z>
		glRotatef(1.0, 0.0, 0.0, 1.0);
		break;
	case 'e':
		// aqu  se procesar a la tecla <e>
		glRotatef(5.0, 1.0, 1.0, 1.0);
		break;
	case 'r':
		// aqu  se procesar a la tecla <r>
		glLoadIdentity();
		angle = 0.0;
		break;
	case 'a':
		// aqu  se procesar a la tecla <a>
		angle += 5;
		break;
	default:
		break;

	}
	glutPostRedisplay();
	glutSwapBuffers();
}

void timeValue(int value) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	if (count!=0)
	{
		glPushMatrix();
			glTranslatef(0, 0, 0);
			glRotatef(5.0, 1.0, 1.0, 1.0);
			prH.drawFigure();
		glPopMatrix();
	}
	else {
		glPushMatrix();
			glTranslatef(-250, 0, 0);
			glRotatef(5.0, 1.0, 1.0, 1.0);
			prH.drawFigure();
		glPopMatrix();
		count++;
	}
	glutPostRedisplay();
	glutSwapBuffers();
	glutTimerFunc(1000, timeValue, 0);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT); // ESTABLECE EL TAMANO DE LA VENTANA
	glutCreateWindow("CUBO 3D");

	initializer(); // INICIALIZA LA VENTANA
	glutDisplayFunc(displayScreen); // ACTUALIZA LA PANTALLA DE TRAZADO
	glutKeyboardFunc(teclado_cb);
	glutTimerFunc(1000,timeValue,0);
	glutIdleFunc(idle_cb);

	glutMainLoop(); // GENERA EL LOOP

	return 0;
}