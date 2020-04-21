#pragma once
#include <cmath>
#include <vector>
#include <string>
#include <GL/glut.h>

struct Vector3 {
	Vector3(GLint X = 0, GLint Y = 0, GLint Z = 0) { X = x; Y = y; Z = z; };
	GLint x = 0;
	GLint y = 0;
	GLint z = 0;
};

struct Vector3f {
	Vector3f(GLfloat X = 0, GLfloat Y = 0, GLfloat Z = 0) { X = x; Y = y; Z = z; };
	GLfloat x = 0;
	GLfloat y = 0;
	GLfloat z = 0;
};

struct Vector3fv {
	Vector3fv(Vector3f X, Vector3f Y, Vector3f Z) { X = x; Y = y; Z = z; };
	Vector3f x;
	Vector3f y;
	Vector3f z;
};

struct Vector2 {
	Vector2(GLint X = 0, GLint Y = 0) { X = x; Y = y;};
	GLint x = 0;
	GLint y = 0;
};

struct Vector2f {
	Vector2f(GLfloat X = 0, GLfloat Y = 0) { X = x; Y = y; };
	GLfloat x = 0;
	GLfloat y = 0;
};

struct Vector2fv {
	Vector2fv(Vector2f X, Vector2f Y) { X = x; Y = y; };
	Vector2f x;
	Vector2f y;
};


struct Color {
	Color(GLfloat R = 0, GLfloat G = 0, GLfloat B = 0) { R = r; G = g; B = b; };
	GLfloat r = 0;
	GLfloat g = 0;
	GLfloat b = 0;
};

struct Face {
	std::vector<Vector3f*> vert;
	std::vector<Vector2f*> texCoord;
	std::vector<Vector3f*> normal;
};

struct Camera {
	GLfloat angle;
	GLfloat fraction = 0.1f;
	GLfloat lx = 0.f, lz = -1.f;
	GLfloat x, z;
};

void drawSnowMan();
