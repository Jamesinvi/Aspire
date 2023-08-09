#include <glm/glm.hpp>
#include <vector>

class Mesh {

public:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;

	Mesh();
	Mesh(const char* path);
	~Mesh();

};