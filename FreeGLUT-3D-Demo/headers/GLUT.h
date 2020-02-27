#pragma once
#include <cmath>
#include <vector>
#include <string>
#include <GL/glut.h>

struct Vector3 {
	Vector3(int X = 0, int Y = 0, int Z = 0) { X = x; Y = y; Z = z; };
	int x = 0;
	int y = 0;
	int z = 0;
};

struct Vector3f {
	Vector3f(float X = 0, float Y = 0, float Z = 0) { X = x; Y = y; Z = z; };
	float x = 0;
	float y = 0;
	float z = 0;
};

struct Camera {
	float angle;
	float fraction = 0.1f;
	float lx = 0.f, lz = -1.f;
	float x, z;
};

void drawSnowMan();
