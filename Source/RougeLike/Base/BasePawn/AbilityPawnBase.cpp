#include "AbilityPawnBase.h"

#include "AbilityControllerBase.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "PaperFlipbookComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "RougeLike/Base/AbilityComponet.h"

AAbilityPawnBase::AAbilityPawnBase()
{

	CollisionComponent=CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	RootComponent = CollisionComponent;

	PaperFlipbookComponent=CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("PaperFlipbookComponent"));
	PaperFlipbookComponent->SetupAttachment(GetRootComponent());
	
	AbilityComponet=CreateDefaultSubobject<UAbilityComponet>(TEXT("AbilityComponent"));

	PawnMovementComponent=CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("PawnMovementComponent"));
	PawnMovementComponent->SetUpdatedComponent(CollisionComponent);

	SpringArmComponent=CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->SetRelativeRotation(FRotator(20.f,-90.f,0.f));
	
	CameraComponent=CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	//调整曝光
	CameraComponent->PostProcessSettings.AutoExposureMethod=AEM_Manual;
	CameraComponent->PostProcessSettings.AutoExposureBias=11.f;
	
}

void AAbilityPawnBase::BeginPlay()
{
	Super::BeginPlay();
}

void AAbilityPawnBase::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if(AAbilityControllerBase* ControllerBase=Cast<AAbilityControllerBase>(GetController()))
	{
		if(UEnhancedInputLocalPlayerSubsystem* Subsystem=ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(ControllerBase->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(MappingContext,0);
		}
	}

	if(UEnhancedInputComponent* EnhancedInputComponent=Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(SprintAction,ETriggerEvent::Started,this,&AAbilityPawnBase::Sprint_Implementation);
		EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&AAbilityPawnBase::Move_Implementation);
	}
}

void AAbilityPawnBase::UpdateAnim_Implementation()
{
}

void AAbilityPawnBase::Move_Implementation(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if(Controller!=nullptr)
	{

		// add movement 
		AddMovementInput(FVector(0,1,0), MovementVector.Y);
		AddMovementInput(FVector(1,0,0), MovementVector.X);
	}
}

void AAbilityPawnBase::Sprint_Implementation(const FInputActionValue& Value)
{
}
