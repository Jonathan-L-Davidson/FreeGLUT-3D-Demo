#include "GLUT.h"
#include "Object.h"
#include "ObjectManager.h"


ObjectManager::ObjectManager() {
	m_objects = new std::vector<Object*>;
}

ObjectManager::~ObjectManager() {
	m_objects->clear();
	delete m_objects;
}


void ObjectManager::RenderObject(Object* obj) {
	glPushMatrix();

	glTranslatef(
		obj->GetPos()->x,
		obj->GetPos()->y,
		obj->GetPos()->z);

	glColor3f(
		obj->GetColor()->x,
		obj->GetColor()->y,
		obj->GetColor()->z);

	glBegin(GL_QUADS);
	for (int i = 0; i < obj->GetModel()->size(); i++) {
		Vector3f* v3 = obj->GetModel()->at(i);
		glVertex3f(v3->x, v3->y, v3->z);
	}
	glEnd();
	glPopMatrix();
}

void ObjectManager::RemoveObj(Object* obj) {
	for (int i = 0; i < m_objects->size(); i++) {
		if (m_objects->at(i)->GetID() == obj->GetID()) {
			m_objects->erase(m_objects->begin() + i);
		}
	}
}

Object* ObjectManager::GetObj(int id) {
	for (int i = 0; i < m_objects->size(); i++) {
		if (*(m_objects->at(i)->GetID()) == id) {
			return m_objects->at(i);
		}
	}
}

Object* ObjectManager::CreateObj(std::string name, int id, Vector3f pos, Vector3 color) {
	Object* obj = new Object(name, id, pos, color);
	m_objects->push_back(obj);

	return obj;
}

void ObjectManager::DrawObjects() {
	for (int i = 0; i < m_objects->size(); i++) {
		RenderObject(m_objects->at(i));
	}
}