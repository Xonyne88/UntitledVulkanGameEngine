#pragma once
#define GLFW_INCLUDE_VULKAN
#include "GLFW/x64/include/glfw3.h"
#include <stdexcept>
#include <vector>
#include <iostream>

class VulkanRenderer
{
public:
	VulkanRenderer();
	
	int init(GLFWwindow * newWindow);
	
	~VulkanRenderer();

private:
	GLFWwindow* window;

	VkInstance instance;

	void createInstance();

	bool checkInstanceExtensionSupport(std::vector<const char*>* checkExtensions);

};

