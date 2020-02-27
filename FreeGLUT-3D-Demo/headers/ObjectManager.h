#pragma once
#include "GLUT.h"

class Object;

class ObjectManager {
	private:
		std::vector<Object*>* m_objects;
		
		void RenderObject(Object* obj);

		void RemoveObj(Object* obj);
		Object* GetObj(int id);
		Object* CreateObj(std::string name, int id, Vector3f pos, Vector3 color);

	public:
		ObjectManager();
		~ObjectManager();
		
		void DrawObjects();
};