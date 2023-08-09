#include <glm/glm.hpp>
#include <vector>

struct ObJData {
public:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
};



class OBJLoader {
public:
	static ObJData* LoadObj(const char* path);
};

