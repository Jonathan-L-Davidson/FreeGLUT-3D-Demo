#include "GLUT.h"
#include "MasterManager.h"
#include "Callbacks.hpp" // This is where "mgr" is defined.

int main(int argc, char** argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(900, 900);
	glutCreateWindow("FreeGLUT Demo");

	//mgr->Initialise(argc, argv);

	glutDisplayFunc(Draw);
	glutReshapeFunc(ChangeSize);

	glutKeyboardFunc(KeyEvents);
	glutSpecialFunc(SpecialKeyEvents);

	glutIdleFunc(Update);

	glutMainLoop();

	return 1;
}