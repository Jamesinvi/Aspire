#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

class Camera {
public:
	enum CameraMode {
		Orthographic,
		Perspective
	};
	glm::vec3 position;
	glm::quat rotation;

	glm::vec3 target = glm::vec3(0.0f, 0.0f, 0.0f); // look-at point (center of the scene)
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f); // up vector

	Camera(CameraMode mode, const glm::vec3 position, const glm::quat rotation);
	glm::mat4 GetProjection();
};
