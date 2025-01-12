// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityBase.h"


// Sets default values
UAbilityBase::UAbilityBase():
CurCooling(0.f)
{
	
}

void UAbilityBase::SetLevel(int32 NewLevel)
{
	if(AbilityDateTable)
	{
		for(auto it:AbilityDateTable->GetRowMap())
		{
			FAbilityData* Data=(FAbilityData*)it.Value;
			if(ID==Data->ID&&NewLevel==Data->Level)
			{
				Level=Data->Level;
				Describe=Data->Describe;
				MaxCooling=Data->MaxCooling;

				if(CurCooling>MaxCooling)
					CurCooling=MaxCooling;
			}
		}
	}
}

void UAbilityBase::Excute_Implementation()
{
}

void UAbilityBase::Init()
{
	SetLevel(1);
}

void UAbilityBase::TryExcute(float Time)
{
	CurCooling-=Time;
	if(CurCooling<=0.f)
	{
		CurCooling=MaxCooling;
		Excute_Implementation();
	}
}

void UAbilityBase::LevelUp()
{
	SetLevel(Level+1);
}

