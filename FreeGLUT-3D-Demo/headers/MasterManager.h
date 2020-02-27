#pragma once
#include "GLUT.h"
class ObjectManager;
class RenderManager;

// Manages the entire program from initialisation and to the end of the program.
// Can be modified to include a launcher or alternative windows to load.

class MasterManager {
private:
	ObjectManager* m_objectManager;
	RenderManager* m_renderManager;

	Camera* m_camera;

public:
	MasterManager();
	~MasterManager();
	
	void Initialise(int argc, char** argv);


	void Update();
	void Draw();
	void ChangeSize(int& w, int& h);
	void KeyEvents(unsigned char& key, int& x, int& y);
	void SpecialKeyEvents(int& key, int& _x, int& _y);

	Camera* GetCamera() const { return m_camera; };

	void Move(int key);

};