// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeBase.h"

void FAttributeData::SetCurrValue(float NewValue)
{
	FAttributeCallbackInfoBase AttributeCallbackInfoBase(NewValue,CurrValue);
	CurrValue=NewValue;
	OnCurrValueChanged.Broadcast(AttributeCallbackInfoBase);
}

void FAttributeData::SetBaseValue(float NewValue)
{
	FAttributeCallbackInfoBase AttributeCallbackInfoBase(NewValue,CurrValue);
	CurrValue=NewValue;
	OnBaseValueChanged.Broadcast(AttributeCallbackInfoBase);
}

void UAttributeBase::SetAttributeCurrValue(FName AttributeName, float ChangeValue)
{
	FAttributeData* AttributeData=Cast<FAttributeData>(GetClass()->FindPropertyByName(AttributeName));
	if(AttributeData)
	{
		OnCurrValueChangedBefore(AttributeData,ChangeValue);
		AttributeData->SetCurrValue(ChangeValue);
	}
}

void UAttributeBase::SetAttributeBaseValue(FName AttributeName, float ChangeValue)
{
	FAttributeData* AttributeData=Cast<FAttributeData>(GetClass()->FindPropertyByName(AttributeName));
	if(AttributeData)
	{
		AttributeData->SetBaseValue(ChangeValue);
		OnBaseValueChangedAfter(AttributeData);
	}
}

void UAttributeBase::OnCurrValueChangedBefore(FAttributeData* AttributeData, float& ChangeValue)
{
}

void UAttributeBase::OnBaseValueChangedAfter(FAttributeData* AttributeData)
{
}
