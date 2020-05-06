//48:10
#define GLFW_INCLUDE_VULKAN
#include "GLFW/x64/include/glfw3.h"
#include <stdexcept>
#include "VulkanRenderer.h"
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
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}