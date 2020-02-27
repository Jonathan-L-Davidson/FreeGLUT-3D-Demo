#pragma once
#include "GLUT.h"
class MasterManager;
class ObjectManager;


class RenderManager {
	private:
		MasterManager* m_masterManager;
		ObjectManager* m_objectManager;

		Camera* m_camera;

	public:
		RenderManager(MasterManager* mstMgr, ObjectManager* objMgr);
		~RenderManager();

		void Display();
};