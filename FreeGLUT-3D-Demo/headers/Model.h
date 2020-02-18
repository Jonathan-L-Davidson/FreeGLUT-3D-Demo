#pragma once
#include "GLUT.h"
#include <string>
#include <vector>

class Model {

	private:
		Vector3* position;
		

	public:
		Model();
		~Model();
		void Load();
		void Draw();

		std::vector<int> list;

};