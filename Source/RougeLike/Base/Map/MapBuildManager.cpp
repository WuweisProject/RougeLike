#include "MapBuildManager.h"

UMapBuildManager::UMapBuildManager()
{
}

void UMapBuildManager::Init()
{
	Map.Init(Width*Hight,-1);
}

int32 UMapBuildManager::BuildRules_Implementation(int32 _x, int32 _y)
{
	return -1;
}

