#pragma once

#include <GL/glut.h>

struct Vector3 {
	Vector3(int X = 0, int Y = 0, int Z = 0) { X = x; Y = y; Z = z; };
	int x = 0;
	int y = 0;
	int z = 0;
};

void keyboard(unsigned char key, int x, int y);
void display();
void ProcessKeyEvents(int key, int _x, int _y);
void drawSnowMan();
void changeSize(int w, int h);