#pragma once
#define GLFW_INCLUDE_VULKAN
#include "GLFW/x64/include/glfw3.h"
#include <set>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "Utilities.h"
#include <array>
#include <cstring>

class VulkanRenderer
{
public:
	VulkanRenderer();
	
	//Inits window
	int init(GLFWwindow * newWindow);
	void draw();

	//Destroys Instance
	void Cleanup();

	~VulkanRenderer();

private:
	GLFWwindow* window;

	int currentFrame = 0;

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
	VkSwapchainKHR swapchain;
	std::vector<SwapChainImage> swapChainImages;
	std::vector<VkFramebuffer> swapChainFrameBuffers;
	std::vector<VkCommandBuffer> commandBuffers;

	// Pools
	VkCommandPool graphicsCommandPool;

	// Pipeline
	VkPipeline graphicsPipeline; 
	VkPipelineLayout pipelineLayout;
	VkRenderPass renderPass;

	//Utility
	VkFormat swapChainImageFormat;
	VkExtent2D swapChainExtent;

	// Synchronisation
	std::vector<VkSemaphore> imageAvailable;
	std::vector<VkSemaphore> renderFinished;
	std::vector<VkFence> drawFences;

	//Create Functions
	void createInstance();
	void createLogicalDevice();
	void createSwapChain();
	void createSurface();
	void createRenderPass();
	void createGraphicsPipeline();
	void createFrameBuffers();
	void createCommandPool();
	void createCommandBuffers();
	void createSynchronisation();

	// Record Functions
	void recordCommands();

	//Get Functions
	void getPhysicalDevice();

	//Checker functions 
	bool checkInstanceExtensionSupport(std::vector<const char*>* checkExtensions);
	bool checkValidationLayerSupport();
	bool checkDeviceExtensionSupport(VkPhysicalDevice device);
	bool checkDeviceSuitable(VkPhysicalDevice device);
	

	//Getter functions
	QueueFamilyIndices getQueueFamilies(VkPhysicalDevice device);
	SwapChainDetails getSwapChainDetails(VkPhysicalDevice device);

    //Choose Functions
	VkSurfaceFormatKHR chooseBestSurfaceFormat(const std::vector<VkSurfaceFormatKHR> &formats);
	VkPresentModeKHR chooseBestPresentationMode(const std::vector<VkPresentModeKHR> presentationModes);
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR &surfaceCapabilities);

	//Create Functions Support basicallyt reusable
	VkImageView createImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags);
	VkShaderModule createShaderModule(const std::vector<char>& code);

	

};