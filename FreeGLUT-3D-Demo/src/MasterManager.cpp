#include "MasterManager.h"
#include "RenderManager.h"
#include "ObjectManager.h"
#include "CameraManager.h"
#include <iostream>

MasterManager::MasterManager() {
	m_camera = new Camera();

	m_objectManager = new ObjectManager();
	m_renderManager = new RenderManager(this, m_objectManager);
}

MasterManager::~MasterManager() {

}


void MasterManager::Update() {


	Draw();
}

void MasterManager::Draw() {
	m_renderManager->Display();
}

void MasterManager::ChangeSize(int& w, int& h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = 1.0 * w / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45, ratio, 1, 1000);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void MasterManager::KeyEvents(unsigned char& key, int& x, int& y)
{
	switch (key) {
	case '\x1B':    exit(EXIT_SUCCESS); break;
	}
}

void MasterManager::SpecialKeyEvents(int& key, int& _x, int& _y) {
	Move(key);
}

void MasterManager::Move(int key) {
	switch (key) {
	case GLUT_KEY_LEFT:
		m_camera->angle -= 0.01f;
		m_camera->lx = sin(m_camera->angle);
		m_camera->lz = -cos(m_camera->angle);
		break;
	case GLUT_KEY_RIGHT:
		m_camera->angle += 0.01f;
		m_camera->lx = sin(m_camera->angle);
		m_camera->lz = -cos(m_camera->angle);
		break;
	case GLUT_KEY_UP:
		m_camera->x += m_camera->lx * m_camera->fraction;
		m_camera->z += m_camera->lz * m_camera->fraction;
		break;
	case GLUT_KEY_DOWN:
		m_camera->x -= m_camera->lx * m_camera->fraction;
		m_camera->z -= m_camera->lz * m_camera->fraction;
		break;
	}
}