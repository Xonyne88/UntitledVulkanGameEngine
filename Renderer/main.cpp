#ifdef Vulkan
#define GLFW_INCLUDE_VULKAN
#include "GLFW/x64/include/glfw3.h"
#include <stdexcept>
#include <vector>
#include <iostream>
#include "Vulkanrenderer/VulkanRenderer.h"

GLFWwindow* window;
VulkanRenderer vulkanRenderer;

void initWindow(std::string wName = "Test Window", const int width = 800, const int height = 600)
{
	// Initialise GLFW
	glfwInit();

	// Set GLFW to NOT work with OpenGL
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(width, height, wName.c_str(), nullptr, nullptr);
}

int main()
{
	// Create Window
	initWindow("Test Window", 800, 600);

	// Create Vulkan Renderer instance
	if (vulkanRenderer.init(window) == EXIT_FAILURE)
	{
		return EXIT_FAILURE;
	}

	float angle = 0.0f;
	float deltaTime = 0.0f;
	float lastTime = 0.0f;

	// Loop until closed
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		
		float now = glfwGetTime();
		deltaTime = now - lastTime;
		lastTime = now;

		angle += 10.f * deltaTime;
		
		if (angle > 360.0f)
		{
			angle -= 360.0f;
		}

		vulkanRenderer.updateModel(glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f)));
		vulkanRenderer.draw();
	}

	vulkanRenderer.cleanup();

	// Destroy GLFW window and stop GLFW
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
#elif OpenGL 
#include "OpenGLRenderer/GLRenderer.h"

int main()
{
	GLRenderer renderer;

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

	GLFWwindow* mainWindow = glfwCreateWindow(renderer.WIDTH, renderer.HEIGHT, "Test Window GL", NULL, NULL);
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

	renderer.StartApplication();

	// Loop until window closed
	while (!glfwWindowShouldClose(mainWindow))
	{
		// Get and handle user input events
		glfwPollEvents();

		renderer.ApplicationLoop();

		glfwSwapBuffers(mainWindow);
	}
	
	return 0;
}
#else 

#endif