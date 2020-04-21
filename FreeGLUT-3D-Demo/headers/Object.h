#pragma once
#include "GLUT.h"

class Object {
	private:
		std::string* m_name;
		int* m_id;

		Vector3f* m_position;

		std::vector<Vector3f*>* m_modelVertices;
		std::vector<Vector2f*>* m_modelTexCoords;
		std::vector<Vector3f*>* m_modelNormals;
		std::vector<Face*>* m_modelFaces;

		std::vector<Color*>* m_color;

	public:
		Object(std::string name, int id, Vector3f pos);
		~Object();

		int* GetID() const { return m_id; };
		std::string* GetName() const { return m_name; };

		Vector3f* GetPos() const { return m_position; };

		std::vector<Face*>* GetModel() const { return m_modelFaces; };
		std::vector<Color*>* GetColor() const { return m_color; };

		void LoadModel(std::string modelPath);
};