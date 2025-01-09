// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityComponet.h"
#include "AbilityBase.h"


// Sets default values for this component's properties
UAbilityComponet::UAbilityComponet()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAbilityComponet::BeginPlay()
{
	Super::BeginPlay();

	// ...
	GetWorld()->GetTimerManager().SetTimer(ExcuteTimer,this,&UAbilityComponet::TryExcuteAbility,ExcuteInterval,true);
}


// Called every frame
void UAbilityComponet::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAbilityComponet::GiveAbilityByClass(TSubclassOf<UAbilityBase> AbilityClass)
{
	if(AbilityClass==nullptr)
		return;
	UAbilityBase* Ability=NewObject<UAbilityBase>(AbilityClass);
	Ability->Init();
	Abilities.Add(Ability);
}

void UAbilityComponet::TryExcuteAbility()
{
	for(UAbilityBase* Ability:Abilities)
	{
		Ability->TryExcute(ExcuteInterval);
	}
}
