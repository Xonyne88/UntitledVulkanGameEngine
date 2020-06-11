#ifdef OpenGL
#pragma once
#include <string>
#include <stdio.h>
#include <glew.h>
#include <cmath>
#include <stdlib.h>
#include "../GLFW/x64/include/glfw3.h"
#include "../GLM/glm.hpp"
#include "../GLM/gtc/matrix_transform.hpp"
#include "../GLM/gtc/type_ptr.hpp"

class GLRenderer 
{
public:
	// Window dimensions
	const GLint WIDTH = 800, HEIGHT = 600;
	const float toRadians = 3.14159265 / 180.0f;
	GLuint VAO, VBO, shader, uniformModel;

	// Variables related to movement
	bool direction = true;
	float triOffset = 0.0f;
	float triMaxOffset = 0.7f;
	float triIncrement = 0.01f;
	float curAngle = 0.0f;
	bool sizeDirection = true;
	float curSize = 0.4f;
	float maxSize = 0.8f;
	float minSize = 0.1f;

	// Shader related
	void CompileShaders();
	void CreateTriangle();

	// Application Related
	void StartApplication();
	void ApplicationLoop();

private:
	void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);
	
};
#endif