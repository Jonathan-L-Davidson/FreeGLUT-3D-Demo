#include "GLUT.h"

MasterManager* mgr = new MasterManager();

void Draw() { mgr->Draw(); };
void ChangeSize(int w, int h) { mgr->ChangeSize(w, h); };

void KeyEvents(unsigned char key, int x, int y) { mgr->KeyEvents(key, x, y); };
void SpecialKeyEvents(int key, int _x, int _y) { mgr->SpecialKeyEvents(key, _x, _y); };

void Update() { mgr->Update(); };
