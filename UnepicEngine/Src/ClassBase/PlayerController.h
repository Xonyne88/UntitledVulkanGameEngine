#pragma once
#include <iostream>

static struct PCData
{
	//The ID and Name are set by the game developer
	//An ID is a way to identify the player and can be generated automatically or can be made manually by the developer
	//The name of the player controller can be set by the developer manually, by a player or can stay at the default state 
	std::string ID;
	std::string Name = "Default";

	//The player number corresponds to the number of playable PCs in the level. 
	//The bool bIsLocallyControlled is a bool that stated stat if the player controller 
	int PlayerNumber;
	bool bIsLocallyControlled;

	//Defined by default by the game mode. This is the first Character/Pawn the player posesses. If a number is higher than 1 the player will posess the PC bound to that number
	static const int CurrentPlayer = 1;

};

void Possess()
{	
	if ( PCData::CurrentPlayer > 1)
	{
		
	}
}