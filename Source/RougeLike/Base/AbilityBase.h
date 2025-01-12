// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilityBase.generated.h"

USTRUCT(BlueprintType)
struct FAbilityData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FString Describe;
	
	UPROPERTY(EditAnywhere)
	int32 Level;

	UPROPERTY(EditAnywhere)
	int32 ID;
	
	UPROPERTY(EditAnywhere)
	float MaxCooling;

	FAbilityData():Level(0),ID(0),MaxCooling(0.f),Describe("")
	{
		
	}
};

UCLASS()
class ROUGELIKE_API UAbilityBase : public UObject
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	UAbilityBase();
private:
	
	
protected:
	UFUNCTION(BlueprintNativeEvent)
	void Excute();

	void SetLevel(int32 NewLevel);

protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	int32 ID;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	float MaxCooling;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	float CurCooling;

	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	UDataTable* AbilityDateTable;

	UPROPERTY(BlueprintReadWrite)
	FString AbilityName;
	
	UPROPERTY(BlueprintReadWrite)
	FString Describe;

	UPROPERTY(BlueprintReadWrite)
	int32 Level;
public:
	void Init();
	
	void TryExcute(float Time);

	void LevelUp();
};
