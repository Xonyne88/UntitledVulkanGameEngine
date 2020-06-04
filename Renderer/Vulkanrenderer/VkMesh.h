#pragma once
#include "vulkan/vulkan.h"
#include <vector>
#include "VulkanUtilities.h"

class Mesh
{
public:
	Mesh();
	Mesh(VkPhysicalDevice newPhysicalDevice, VkDevice newDevice, std::vector<Vertex> * vertices);

	int getVertexCount();
	VkBuffer getVertexBuffer();

	void destroyVertexBuffer();

	~Mesh();
private:
	int vertexCount;
	VkBuffer vertexBuffer;
	VkDeviceMemory vertexBufferMemory;

	VkPhysicalDevice physicalDevice;
	VkDevice device;

	VkBuffer createVertexBuffer(std::vector<Vertex> * vertices);
	uint32_t findMemoryTypeIndex(uint32_t allowedTypes, VkMemoryPropertyFlags properties);
};

