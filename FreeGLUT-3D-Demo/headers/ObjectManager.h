#pragma once
#include "GLUT.h"

class Object;

class ObjectManager {
	private:

		int m_maxID = 0;

		std::vector<Object*>* m_objects;
		
		void RenderObject(Object* obj);

		void RemoveObj(Object* obj);
		Object* GetObj(int id);
		Object* CreateObj(std::string name, Vector3f pos);

	public:
		ObjectManager();
		~ObjectManager();
		
		void DrawObjects();
};