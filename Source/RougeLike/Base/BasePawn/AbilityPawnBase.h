// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityBase.generated.h"

class UAbilityComponet;

UCLASS()
class ROUGELIKE_API AAbilityPawnBase:public APawn
{
	GENERATED_BODY()

public:
	AAbilityPawnBase();
protected:
	virtual void BeginPlay() override;
protected:
	UPROPERTY(BlueprintReadOnly)
	UAbilityComponet* AbilityComponet;

	UPROPERTY(BlueprintReadOnly)
	UPawnMovementComponent* PawnMovementComponent;
};