#include "GLUT.h"
#include "Object.h"
#include "ObjectManager.h"
#include <iostream>

ObjectManager::ObjectManager() {
	m_objects = new std::vector<Object*>;

	CreateObj("monkey", Vector3f(1.f, 1.f, 0.f));

}

ObjectManager::~ObjectManager() {
	m_objects->clear();
	delete m_objects;
}


void ObjectManager::RenderObject(Object* obj) {
	glPushMatrix();

	glEnableClientState(GL_VERTEX_ARRAY);

	glTranslatef(
		obj->GetPos()->x,
		obj->GetPos()->y,
		obj->GetPos()->z);
	
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < obj->GetModel()->size(); i++) {

		// For every model. 

		for (int j = 0; j < obj->GetModel()->at(i)->vert.size(); j++) {
			//std::cout << obj->GetModel()->at(i)->vert.size() << std::endl;

			Vector2f* UV = obj->GetModel()->at(i)->texCoord.at(j); // I hardcoded this to make it so it will only use the text coordinates with the vertices of the face.
			Vector3f* norm = obj->GetModel()->at(i)->normal.at(j); // Same with this.
			Vector3f* vert = obj->GetModel()->at(i)->vert.at(j);

			//glTexCoord2d(UV->x, UV->y);
			//glNormal3f(norm->x, norm->y, norm->z);
			//glVertex3f(vert->x, vert->y, vert->z);

			glVertexPointer(3, GL_FLOAT, 0, &obj->GetModel()->at(i)->vert[0]);



		}
	}
	glEnd();

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableClientState(GL_NORMAL_ARRAY);

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

Object* ObjectManager::CreateObj(std::string name, Vector3f pos) {
	Object* obj = new Object(name, m_maxID, pos);
	
	obj->LoadModel("./resources/models/");
	
	m_objects->push_back(obj);

	m_maxID++;
	return obj;
}

void ObjectManager::DrawObjects() {
	for (int i = 0; i < m_objects->size(); i++) {
		RenderObject(m_objects->at(i));
	}
}