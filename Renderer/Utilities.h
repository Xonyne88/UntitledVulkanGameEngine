#pragma once

//indeces of Queue families
struct QueueFamilyIndices
{
	int graphicsFamily = -1; //location of Graphics Queue Family

	//Check if queue families are valid
	bool isValid() 
	{
		return graphicsFamily >= 0;
	}
};