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

bool UAttributeBase::SetAttributeCurrValue(FName AttributeName, float ChangeValue)
{
	FAttributeData* AttributeData=CastField<FStructProperty>(GetClass()->FindPropertyByName(AttributeName))->ContainerPtrToValuePtr<FAttributeData>(this);
	if(AttributeData)
	{
		OnCurrValueChangedBefore(AttributeData,ChangeValue);
		AttributeData->SetCurrValue(ChangeValue);
		return true;
	}
	return false;
}

bool UAttributeBase::SetAttributeBaseValue(FName AttributeName, float ChangeValue)
{
	FAttributeData* AttributeData=CastField<FStructProperty>(GetClass()->FindPropertyByName(AttributeName))->ContainerPtrToValuePtr<FAttributeData>(this);
	if(AttributeData)
	{
		OnBaseValueChangedAfter(AttributeData);
		return true;
	}
	return false;
}

bool UAttributeBase::GetAttributeCurrValue(FName AttributeName, float& GetValue)
{
	FAttributeData* AttributeData=CastField<FStructProperty>(GetClass()->FindPropertyByName(AttributeName))->ContainerPtrToValuePtr<FAttributeData>(this);
	if(AttributeData)
	{
		return true;
	}
	return false;
}

bool UAttributeBase::GetAttributeBaseValue(FName AttributeName, float& GetValue)
{
	FAttributeData* AttributeData=CastField<FStructProperty>(GetClass()->FindPropertyByName(AttributeName))->ContainerPtrToValuePtr<FAttributeData>(this);
	if(AttributeData)
	{
		return true;
	}
	return false;
}

void UAttributeBase::OnCurrValueChangedBefore(FAttributeData* AttributeData, float& ChangeValue)
{
}

void UAttributeBase::OnBaseValueChangedAfter(FAttributeData* AttributeData)
{
}
