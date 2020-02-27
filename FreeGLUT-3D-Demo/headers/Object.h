#pragma once
#include "GLUT.h"

class Object {
	private:
		std::string* m_name;
		int* m_id;

		Vector3f* m_position;
		Vector3* m_color;

		std::vector<Vector3f*>* m_model;

	public:
		Object(std::string name, int id, Vector3f pos, Vector3 color);
		~Object();
		
		
		int* GetID() const { return m_id; };
		Vector3f* GetPos() const { return m_position; };
		Vector3* GetColor() const { return m_color; };

		std::vector<Vector3f*>* GetModel() const { return m_model; };

};