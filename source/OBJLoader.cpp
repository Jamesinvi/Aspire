#include "headers/OBJLoader.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <glm/glm.hpp>

ObJData* OBJLoader::LoadObj(const char* path) {
	std::ifstream file(path);
	ObJData* output = new ObJData;
    // Checking whether the file is open.
	if (!file.is_open()) {
		std::cerr << "could not open file: " << path << std::endl;
		return output;
	}
    std::vector<glm::vec3> objNormals;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string lineStart;
        iss >> lineStart;

        if (lineStart == "#") {
            std::cout << "found comment" << "\n";
            continue;
        }
        else if (lineStart == "v") {
            glm::vec3 vertex;
            iss >> vertex.x;
            iss >> vertex.y;
            iss >> vertex.z;
            std::cout << "vertex: " << std::fixed << std::setprecision(1) << vertex.x << " " << vertex.y << " " << vertex.z << "\n";
            output->vertices.push_back(vertex);
            output->normals.push_back(vertex);
        }
        else if (lineStart == "vn") {
            glm::vec3 normal;
            iss >> normal.x;
            iss >> normal.y;
            iss >> normal.z;
            std::cout << "normal: " << std::fixed << std::setprecision(1) << normal.x << " " << normal.y << " " << normal.z << "\n";
            objNormals.push_back(normal);
        }
        else if (lineStart == "f") {
            int vertexIndex, normalIndex;
            for (int i = 0; i < 4; i++) {
                iss >> vertexIndex;
                iss.ignore();
                iss.ignore();
                iss >> normalIndex;
                vertexIndex -= 1;
                normalIndex -= 1;
                output->normals[vertexIndex] = objNormals[normalIndex];
            }
        }
        // Add more conditions for other line types as needed
    }




	return output;

}