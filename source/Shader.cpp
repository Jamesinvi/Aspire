#include "headers/Shader.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const char* pathToVertex, const char* pathToFragment)
{

	std::ifstream vShaderFile, fShaderFile;
	std::string vShaderSource, fShaderSource;
	std::stringstream vShaderStream, fShaderStream;
	const char* vShaderCode;
	const char* fShaderCode;

	try {
		vShaderFile.open(pathToVertex);
		fShaderFile.open(pathToFragment);
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vShaderSource = vShaderStream.str();
		fShaderSource = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILES_NOT_SUCCESFULLY_READ" << std::endl;
	}
	vShaderCode = vShaderSource.c_str();
	fShaderCode = fShaderSource.c_str();

	unsigned int vertex, fragment;
	int success;
	char infoLog[512];

	// Create the vertex shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	// print compile errors if any
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	};

	// Create the fragment shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	// print compile errors if any
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	};

	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	// print linking errors if any
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	// delete the shaders as they're linked into our program now
	glDeleteShader(vertex);
	glDeleteShader(fragment);

}

void Shader::use()
{
	glUseProgram(ID);
}
void Shader::setMat4(const std::string& name, const glm::mat4& value) const
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}
void Shader::setVec3(const std::string& name, const glm::vec3& value) const
{
	glUniform3fv(glGetUniformLocation(ID, name.c_str()),1, glm::value_ptr(value));
}

void Shader::setBool(const std::string& name, const bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string& name, const int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, const float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}