#include "GLUT.h"

int main(int argc, char** argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(900, 900);
	glutCreateWindow("Lighthouse3D- GLUT Tutorial");

	// register callbacks
	glutDisplayFunc(display);
	glutReshapeFunc(changeSize);

	glutSpecialFunc(ProcessKeyEvents);


	// here is the idle func registration
	glutIdleFunc(display);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}