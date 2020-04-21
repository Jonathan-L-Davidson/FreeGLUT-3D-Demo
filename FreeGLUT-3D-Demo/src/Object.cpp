#include "Object.h"
#include <fstream>
#include <cstdio>
#include <sstream>
#include <iostream>

Object::Object(std::string name, int id, Vector3f pos) {
	m_name = new std::string(name);
	m_id = new int(id);
	m_position = new Vector3f(pos);

	m_modelVertices = new std::vector<Vector3f*>();
	m_modelTexCoords = new std::vector<Vector2f*>();
	m_modelNormals = new std::vector<Vector3f*>();
	m_modelFaces = new std::vector<Face*>();

	m_color = new std::vector<Color*>();

}

Object::~Object() {
	delete m_name;
	delete m_id;

	m_modelVertices->clear();
	delete m_modelVertices;

	m_modelTexCoords->clear();
	delete m_modelTexCoords;

	m_modelNormals->clear();
	delete m_modelNormals;

	m_modelFaces->clear();
	delete m_modelFaces;

	m_color->clear();
	delete m_color;
}


void Object::LoadModel(std::string modelPath) {

	std::stringstream ss;


	ss << modelPath + *m_name + ".obj";
	
	
	
	FILE* modelFile = fopen(ss.str().c_str(), "r");

	if (modelFile == NULL) {
		std::cout << "Error opening model!\n";
		return;
	}

	std::cout << ss.str() << " LOADED\n";

	while(true) {
		// Get the string entered on the line.
		char lineString[256];

		int result = fscanf(modelFile, "%s", lineString);

		if (result == EOF) {
			break; // finished scanning the model file.
		}


		if (strcmp(lineString, "v") == 0) {
			
			Vector3f vertexVec;

			fscanf(modelFile, "%f %f %f\n", &vertexVec.x, &vertexVec.y, &vertexVec.z); // Cannot make the vertexVec a pointer, I have to pass the vector3f by reference.

			//std::cout << "Vertex: X - " << vertexVec.x << " | Y - " << vertexVec.y << " | Z - " << vertexVec.z << std::endl;
			
			m_modelVertices->push_back(new Vector3f(vertexVec));

		}
		else if (strcmp(lineString, "vt") == 0) {
			
			Vector2f texCoordVec;

			fscanf(modelFile, "%f %f\n", &texCoordVec.x, &texCoordVec.y);

			//std::cout << "UV: X - " << texCoordVec.x << " | Y - " << texCoordVec.y << std::endl;
			
			m_modelTexCoords->push_back(new Vector2f(texCoordVec));
		}
		else if (strcmp(lineString, "vn") == 0) {

			Vector3f normalVec;

			fscanf(modelFile, "%f %f %f\n", &normalVec.x, &normalVec.y, &normalVec.z); // Cannot make the vertexVec a pointer, I have to pass the vector3f by reference.

			//std::cout << "Normal: X - " << normalVec.x << " | Y - " << normalVec.y << " | Z - " << normalVec.z << std::endl;

			m_modelNormals->push_back(new Vector3f(normalVec));
		} // Now for the hardest part!
		else if (strcmp(lineString, "f") == 0) {

			unsigned int indexVertice[3], indexUV[3], indexNormal[3];

			fscanf(modelFile, "%d/%d/%d %d/%d/%d %d/%d/%d\n",	&indexVertice[0], &indexUV[0], &indexNormal[0],
																&indexVertice[1], &indexUV[1], &indexNormal[1],
																&indexVertice[2], &indexUV[2], &indexNormal[2]);


			//std::cout << "Face: " <<	indexVertice[0] << "/" << indexUV[0] << "/" << indexNormal[0] << " | " <<
			//							indexVertice[1] << "/" << indexUV[1] << "/" << indexNormal[1] << " | " <<
			//							indexVertice[2] << "/" << indexUV[2] << "/" << indexNormal[2] << std::endl;
			
			Face* face = new Face;

			face->vert.push_back(m_modelVertices->at(indexVertice[0] - 1));
			face->vert.push_back(m_modelVertices->at(indexVertice[1] - 1));
			face->vert.push_back(m_modelVertices->at(indexVertice[2] - 1));

			face->texCoord.push_back(m_modelTexCoords->at(indexUV[0] - 1));
			face->texCoord.push_back(m_modelTexCoords->at(indexUV[1] - 1));
			face->texCoord.push_back(m_modelTexCoords->at(indexUV[2] - 1));

			face->normal.push_back(m_modelNormals->at(indexNormal[0] - 1));
			face->normal.push_back(m_modelNormals->at(indexNormal[1] - 1));
			face->normal.push_back(m_modelNormals->at(indexNormal[2] - 1));

			m_modelFaces->push_back(face);
		}
	}



}