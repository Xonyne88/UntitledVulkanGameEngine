#pragma once
#include <string>
//Starts When the game is created
void BeginPlay();

//Actions in the Tick functions happen every second
void Tick(float DeltaTime);

//Sets the game version. 
//definition: type = 0 is a testing version, 
//major is the major version (mostly in big updates)
//minor is a small update that fixes bug or adds features that are not as large scale
//patch is a hotfix a.k.a. fixing bugs after a release
void SetGameVersion(int type, int major, int minor, int patch);
void SetEngineVersion(int type, int major, int minor, int patch);
void SetGameName(const char* Name);
void SetAPIVersion(int type, int major, int minor, int patch);
