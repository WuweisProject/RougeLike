#pragma once
#include "CoreMinimal.h"
#include "MapBuildManager.generated.h"

class UImage;

USTRUCT(BlueprintType)
struct FTileData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	UImage* Tile;

	UPROPERTY(EditAnywhere)
	float Weight;
	
	FTileData():
	Tile(nullptr),Weight(0.f)
	{
		
	}
};

UCLASS()
class ROUGELIKE_API UMapBuildManager:public UObject
{
	GENERATED_BODY()
public:
	UMapBuildManager();
protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TArray<FTileData> Tiles;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 Hight;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 Width;

	UPROPERTY(BlueprintReadWrite)
	TArray<int32> Map;
protected:
	UFUNCTION(BlueprintNativeEvent)
	int32 BuildRules(int32 _x,int32 _y);


public:
	UFUNCTION(BlueprintCallable)
	void Init();
};
