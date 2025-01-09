#include "AbilityPawnBase.h"

#include "GameFramework/PawnMovementComponent.h"
#include "RougeLike/Base/AbilityComponet.h"

AAbilityPawnBase::AAbilityPawnBase()
{
	AbilityComponet=CreateDefaultSubobject<UAbilityComponet>(TEXT("AbilityComponent"));

	PawnMovementComponent=CreateDefaultSubobject<UPawnMovementComponent>(TEXT("PawnMovementComponent"));
}

void AAbilityPawnBase::BeginPlay()
{
	Super::BeginPlay();
}
