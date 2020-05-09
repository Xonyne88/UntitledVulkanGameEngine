#pragma once
#define GLFW_INCLUDE_VULKAN
#include "GLFW/x64/include/glfw3.h"
#include <set>
#include <stdexcept>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "Utilities.h"

class VulkanRenderer
{
public:
	VulkanRenderer();
	
	//Inits window
	int init(GLFWwindow * newWindow);
	
	//Destroys Instance
	void Cleanup();

	~VulkanRenderer();

private:
	GLFWwindow* window;

	//Vulkan components
	VkInstance instance;

	struct 
	{
		VkPhysicalDevice physicalDevice;
		VkDevice logicalDevice;
	}mainDevice;
	VkQueue GraphicsQueue;
	VkQueue presentationQueue;
	VkSurfaceKHR surface;

	//Create Functions
	void createInstance();
	void createLogicalDevice();
	void createSurface();

	//Get Functions
	void getPhysicalDevice();

	//Checker functions 
	bool checkInstanceExtensionSupport(std::vector<const char*>* checkExtensions);
	bool checkDeviceExtensionSupport(VkPhysicalDevice device);
	bool checkDeviceSuitable(VkPhysicalDevice device);


	//Getter functions
	QueueFamilyIndices getQueueFamilies(VkPhysicalDevice device);
	SwapChainDetails getSwapChainDetails(VkPhysicalDevice device);
};