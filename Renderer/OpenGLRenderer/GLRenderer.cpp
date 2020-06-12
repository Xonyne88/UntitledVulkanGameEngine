#ifdef OpenGL
#include "GLRenderer.h"

// Vertex Shader
static const char* vShader = "											\n\
#version 330															\n\
layout(location = 0) in vec3 pos;										\n\
uniform	mat4 model;														\n\
void main()																\n\
{																		\n\
	gl_Position = model * vec4(pos, 1.0);								\n\
																		\n\
}																		\n\
";

static const char* fShader =
"																		\n\
#version 330															\n\
out vec4 colour;														\n\
void main()																\n\
{																		\n\
	colour = vec4(1.0, 0.0, 0.0, 0.0);									\n\
																		\n\
}																		\n\
";

void GLRenderer::CreateTriangle()
{
	GLfloat vertices[] =
	{
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void GLRenderer::StartApplication()
{
	CreateTriangle();
	CompileShaders();
}

void GLRenderer::ApplicationLoop()
{
	if (direction)
	{
		triOffset += triIncrement;
	}
	else
	{
		triOffset -= triIncrement;
	}

	if (abs(triOffset) >= triMaxOffset)
	{
		direction = !direction;
	}

	curAngle += 0.01f;
	if (curAngle >= 360)
	{
		curAngle -= 360;
	}

	if (sizeDirection)
	{
		curSize += 0.01f;
	}
	else
	{
		curSize -= 0.01f;
	}

	if (curSize >= maxSize || curSize <= minSize)
	{
		sizeDirection = !sizeDirection;
	}

	// Clear window
	glClearColor(0.6f, 0.651f, 0.4f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(shader);

	glm::mat4 model(1.0f);
	model = glm::rotate(model, curAngle * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::translate(model, glm::vec3(triOffset, 0.4, 0.0f));
	model = glm::scale(model, glm::vec3(curSize, curSize, 0.0f));

	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);

	glUseProgram(0);
}

void GLRenderer::AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType)
{
	GLuint theShader = glCreateShader(shaderType);

	const GLchar* theCode[1];
	theCode[0] = shaderCode;

	GLint codeLenght[1];
	codeLenght[0] = strlen(shaderCode);

	glShaderSource(theShader, 1, theCode, codeLenght);
	glCompileShader(theShader);

	GLint result = 0;
	GLchar eLog[1024] = { 0 };

	glLinkProgram(shader);
	glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);



	if (!result)
	{
		glGetShaderInfoLog(theShader, sizeof(eLog), NULL, eLog);
		printf("Error compiling the %d shader: '%s'\n", shaderType, eLog);
		return;
	}
	glAttachShader(theProgram, theShader);
}

void GLRenderer::CompileShaders()
{
	shader = glCreateProgram();

	if (!shader)
	{
		printf("Error creating a shader program!\n");
		return;
	}

	AddShader(shader, vShader, GL_VERTEX_SHADER);
	AddShader(shader, fShader, GL_FRAGMENT_SHADER);

	GLint result = 0;
	GLchar eLog[1024] = { 0 };

	glLinkProgram(shader);
	glGetProgramiv(shader, GL_LINK_STATUS, &result);

	if (!result)
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("Error linking program: '%s'\n", eLog);
		return;
	}

	glValidateProgram(shader);
	glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);

	if (!result)
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("Error validating program: '%s'\n", eLog);
		return;
	}

	uniformModel = glGetUniformLocation(shader, "model");
}
#endif