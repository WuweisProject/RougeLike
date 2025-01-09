// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbilityComponet.generated.h"

class UAbilityBase;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ROUGELIKE_API UAbilityComponet : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAbilityComponet();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	void GiveAbilityByClass(TSubclassOf<UAbilityBase> AbilityClass);
protected:
	void TryExcuteAbility();
protected:
	FTimerHandle ExcuteTimer;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	float ExcuteInterval;

	TArray<UAbilityBase*> Abilities;
};
