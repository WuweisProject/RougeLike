// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "AbilityPawnBase.generated.h"

class UFloatingPawnMovement;
class UPaperFlipbook;
class UPaperFlipbookComponent;
class USpringArmComponent;
struct FInputActionValue;
class UInputMappingContext;
class UInputAction;
class UAbilityComponet;
class USphereComponent;

UENUM(BlueprintType)
enum EAnimType
{
	EAT_Idle,
	EAT_Run,
	EAT_Sprint,
	EAT_Max
};

UCLASS()
class ROUGELIKE_API AAbilityPawnBase:public APawn
{
	GENERATED_BODY()

public:
	AAbilityPawnBase();
protected:
	virtual void BeginPlay() override;
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category="Ability")
	UAbilityComponet* AbilityComponet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UFloatingPawnMovement* PawnMovementComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCameraComponent* CameraComponent;

	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="Input")
	UInputMappingContext* MappingContext;
	
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="Input")
	UInputAction* MoveAction;
	
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="Input")
	UInputAction* SprintAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category="Collision")
	USphereComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPaperFlipbookComponent* PaperFlipbookComponent;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Anim")
	UPaperFlipbook* IdleAnim;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Anim")
	UPaperFlipbook* RunningAnim;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Anim")
	UPaperFlipbook* SprintAnim;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Sprint")
	float SprintTime;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Sprint")
	float SprintDistance;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Sprint")
	UCurveFloat* SprintCurve;

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UFUNCTION(BlueprintNativeEvent)
	void Sprint(const FInputActionValue& Value);

	UFUNCTION(BlueprintNativeEvent)
	void Move(const FInputActionValue& Value);

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	void UpdateAnim();
};