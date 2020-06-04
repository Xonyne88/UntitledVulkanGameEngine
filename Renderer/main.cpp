#ifdef Vulkan
#include "vulkan/vulkan.h"
#include "GLFW/x64/include/glfw3.h"
#include <stdexcept>
#include "Vulkanrenderer/VulkanRenderer.h"
//#define GLM_FORCE_RADIANTS
//#define GLM_FORCE_DEPTH_ZERO_TO_ONE
//#include "GLM/glm.hpp"
//#include "GLM/mat4x4.hpp"

#include <iostream>

GLFWwindow* window;
VulkanRenderer vulkanRenderer;

void initWindow(std::string wName = "Test Window", const int width = 800, const int height = 600)
{
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(width, height, wName.c_str(), nullptr, nullptr);
}

int main()
{
	initWindow("Test Window", 800, 600);

	if(vulkanRenderer.init(window)== EXIT_FAILURE)
	{
		return EXIT_FAILURE;
	}
	
	while (!glfwWindowShouldClose(window)) 
	{
		glfwPollEvents();
		vulkanRenderer.draw();
	}

	vulkanRenderer.Cleanup();

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
#elif OpenGL 
#include <stdio.h>
#include <iostream>
#include <glew.h>
#include "GLFW/x64/include/glfw3.h"

// Window dimensions
const GLint WIDTH = 800, HEIGHT = 600;

int main()
{
	// Init GLFW
	if (!glfwInit())
	{
		printf("GLFW initialisation failed!");
		glfwTerminate();
		return 1;
	}

	//Setup GLFW window properties
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Core profile - no backwards compatibility
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test WIndow GL", NULL, NULL);
	if (!mainWindow)
	{
		printf("GLFW window creation failed!");
		glfwTerminate();
		return 1;
	}

	// Get buffer size information
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	// Set context for GLEW to use
	glfwMakeContextCurrent(mainWindow);

	// Allow modern extension features
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		printf("GLEW initialisation failed!");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	// Setup viewport size
	glViewport(0, 0, bufferWidth, bufferHeight);

	// Loop until window closed
	while (!glfwWindowShouldClose(mainWindow))
	{
		// Get and handle user input events
		glfwPollEvents();

		// Clear window
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);
	}
	
	return 0;
}
#else 

#endif