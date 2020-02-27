#include "Object.h"

Object::Object(std::string name, int id, Vector3f pos, Vector3 color) {
	m_name = new std::string(name);
	m_id = new int(id);
	m_position = new Vector3f(pos);
	m_color = new Vector3(color);
	m_model = new std::vector<Vector3f*>();
}

Object::~Object() {
	delete m_name;
	delete m_id;

	m_model->clear();
	delete m_model;
}
