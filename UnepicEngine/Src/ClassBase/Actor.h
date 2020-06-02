#pragma once
#include <string>

class Actor
{
public:
	int positionX;
	int positionY;
	
	std::string Name;
	

protected:

	virtual void BeginPlay();
	void FixedTick();
	void Tick();
	void BeginOverlap();
	void OnHit();
	
};
