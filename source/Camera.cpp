#include "headers/Camera.hpp"

Camera::Camera(CameraMode mode, const glm::vec3 position, const glm::quat rotation)
{
	this->position = position;
	this->rotation = rotation;
}

glm::mat4 Camera::GetProjection() {
	return glm::perspective(glm::radians(30.0f), 720.0f / 720.0f, 0.03f, 100.0f);
}
