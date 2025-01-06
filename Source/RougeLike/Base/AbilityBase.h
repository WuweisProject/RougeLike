// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilityBase.generated.h"

UCLASS()
class ROUGELIKE_API AAbilityBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAbilityBase();

private:
	
	
protected:
	UFUNCTION(BlueprintNativeEvent)
	void Excute();

	UFUNCTION(BlueprintCallable)
	void EndAbility();

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	float CurCooling;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	float MaxCooling;

	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	UDataTable* AbilityDateTable;
public:
	bool CanExcute(float Time);
	
	void ExcuteAbility();
};
