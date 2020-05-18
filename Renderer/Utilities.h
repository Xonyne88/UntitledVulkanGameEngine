#pragma once
#include <vector>
#include <fstream>

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

struct SwapChainImage 
{
	VkImage image;
	VkImageView imageView;
};

static std::vector<char> readFile(const std::string& filename)
{
	// Open stream from given file
	// std::ios::binary tells the stream to read file as binary
	// std::ios::ate tells stream to start reading from end of the file
	std::ifstream file(filename, std::ios::binary | std::ios::ate);

	// Check if file stream successfully opened
	if (!file.is_open())
	{
		throw std::runtime_error("Failed to open a file!");
	}

	// Get current read position and use to resize file buffer
	size_t fileSize = (size_t)file.tellg();
	std::vector<char> fileBuffer(fileSize);

	// Move read position to the start of the file
	file.seekg(0);

	// Reads the file
	file.read(fileBuffer.data(), fileSize);

	return fileBuffer;
}