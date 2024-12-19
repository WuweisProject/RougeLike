// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AttributeBase.generated.h"

/**
 * 
 */
#define ATTRIBUTE_SUCCESS(PropertyName)\
ATTRIBUTE_SETTER(PropertyName)\
ATTRIBUTE_GETTER(PropertyName)\
ATTRIBUTE_INIT(PropertyName)

#define ATTRIBUTE_SETTER(PropertyName)\
void Set##PropertyName##BaseValue(float NewValue)\
{\
	OnCurrValueChangedBefore(&PropertyName,NewValue);\
	PropertyName.BaseValue=NewValue;\
}\
void Set##PropertyName##CurrValue(float NewValue)\
{\
	PropertyName.CurrValue=NewValue;\
	OnBaseValueChangedAfter(&PropertyName);\
}

#define ATTRIBUTE_GETTER(PropertyName)\
float Get##PropertyName##BaseValue()\
{\
	return PropertyName.BaseValue;\
}\
float Get##PropertyName##CurrValue()\
{\
	return PropertyName.CurrValue;\
}\

#define ATTRIBUTE_INIT(PropertyName)\
void Init##PropertyName##(float NewCurrValue,float NewBaseValue)\
{\
	Set##PropertyName##BaseValue(NewBaseValue);\
	Set##PropertyName##CurrValue(NewCurrValue);\
}

USTRUCT()
struct FAttributeCallbackInfoBase
{
	GENERATED_BODY()

public:
	FAttributeCallbackInfoBase():
	NewValue(0.f),OldValue(0.f){}

	FAttributeCallbackInfoBase(float _NewValue,float _OldValue):
	NewValue(_NewValue),OldValue(_OldValue){}
	
	UPROPERTY(BlueprintReadWrite)
	float NewValue;
	UPROPERTY(BlueprintReadWrite)
	float OldValue;
};

USTRUCT(BlueprintType)
struct FAttributeInitData
{
	GENERATED_BODY()

public:
	FAttributeInitData():
	CurrValue(0.f),BaseValue(0.f){}
	
	UPROPERTY(BlueprintReadWrite)
	float CurrValue;
	UPROPERTY(BlueprintReadWrite)
	float BaseValue;
};

DECLARE_MULTICAST_DELEGATE_OneParam(FOnAttributeChanged,FAttributeCallbackInfoBase);

USTRUCT(BlueprintType)
struct FAttributeData
{
	GENERATED_BODY()
public:
	FAttributeData():
	CurrValue(0.f),BaseValue(0.f){}

	FAttributeData(float CurrNewValue,float BaseNewValue):
	CurrValue(CurrNewValue),BaseValue(BaseNewValue){}
	
	float GetCurrValue(){return CurrValue;}
	float GetBaseValue(){return BaseValue;}
	void SetCurrValue(float NewValue);
	void SetBaseValue(float NewValue);
	FOnAttributeChanged GetCurrValueChanged(){return OnCurrValueChanged;}
	FOnAttributeChanged GetBaseValueChanged(){return OnBaseValueChanged;}

private:
	float CurrValue;
	float BaseValue;
	FOnAttributeChanged OnCurrValueChanged;
	FOnAttributeChanged OnBaseValueChanged;
};


UCLASS()
class ROUGELIKE_API UAttributeBase : public UObject
{
	GENERATED_BODY()


public:
	bool SetAttributeCurrValue(FName AttributeName,float ChangeValue);
	bool SetAttributeBaseValue(FName AttributeName,float ChangeValue);
	bool GetAttributeCurrValue(FName AttributeName,float& GetValue);
	bool GetAttributeBaseValue(FName AttributeName,float& GetValue);

private:
	//CurrValue值改变之前
	virtual void OnCurrValueChangedBefore(FAttributeData* AttributeData,float& ChangeValue);
	virtual void OnBaseValueChangedAfter(FAttributeData* AttributeData);
};
