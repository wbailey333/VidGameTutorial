#pragma once

#include <string>
#include <GL/glew.h>

class GLSProgram
{
public:
	GLSProgram();
	~GLSProgram();

	void compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);

	void linkShader();

	void addAttribute(const std::string& attributeName);

	void user();
	void unuse();

private:
	int _numAttributes;
	void compileShader(const std::string& filePath, GLuint id);

	GLuint _programID;
	GLuint _vertexShaderID;
	GLuint _fragmentShaderID;

};

