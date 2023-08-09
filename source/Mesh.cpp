#include "headers/Mesh.hpp"
#include "headers/OBJLoader.hpp"
#include <iostream>

Mesh::Mesh() {
}
Mesh::Mesh(const char* path) {
	ObJData* t=OBJLoader::LoadObj(path);

	vertices = t->vertices;
	normals = t->vertices;

	delete t;
}