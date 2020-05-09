#pragma once
#include <vector>

const std::vector <const char*> deviceExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };

//indices of Queue families
struct QueueFamilyIndices
{
	int graphicsFamily = -1; //location of Graphics Queue Family
	int presentationFamily = -1; // Location of the presentation queue family

	//Check if queue families are valid
	bool isValid() 
	{
		return graphicsFamily >= 0 && presentationFamily >= 0;
	}
};

struct SwapChainDetails
{
	VkSurfaceCapabilitiesKHR surfaceCapabilities; //Surface properties
	std::vector<VkSurfaceFormatKHR>formats; //Surfave image formats
	std::vector<VkPresentModeKHR> presentationModes; //How images should be presented to the screen
};