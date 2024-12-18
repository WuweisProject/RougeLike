// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityComponet.h"


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

	for(FAttributeInitInfo Info:AttributeInit)
	{
		if(Info.Data!=nullptr)
		{
			UAttributeBase* AttributeBase=NewObject<UAttributeBase>(Info.Data);
			if(Info.DataTable!=nullptr)
			{
				for(auto Data:Info.DataTable->GetRowMap())
				{
					FName DataName=Data.Key;
					FAttributeInitData* AttributeInitData=Cast<FAttributeInitData>(Data.Value);
					AttributeBase->SetAttributeBaseValue(DataName,AttributeInitData->BaseValue);
					AttributeBase->SetAttributeCurrValue(DataName,AttributeInitData->CurrValue);
				}
			}
			AttributeDataArray.Add(AttributeBase);
		}
	}
	
}


// Called every frame
void UAbilityComponet::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

