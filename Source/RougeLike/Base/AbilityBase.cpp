// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityBase.h"


// Sets default values
AAbilityBase::AAbilityBase()
{
}

void AAbilityBase::Excute_Implementation()
{
}


void AAbilityBase::EndAbility()
{
}

bool AAbilityBase::CanExcute(float Time)
{
	bool canExcute = false;

	CurCooling-=Time;
	if(CurCooling<=0)
	{
		canExcute=true;
		CurCooling=MaxCooling;
	}

	return canExcute;
}

void AAbilityBase::ExcuteAbility()
{
}

