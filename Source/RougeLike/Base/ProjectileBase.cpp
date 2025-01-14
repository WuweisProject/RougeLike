#include "ProjectileBase.h"

#include "EnemyBase.h"
#include "PaperSpriteComponent.h"

AProjectileBase::AProjectileBase()
{
	SpriteComponent=CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
	RootComponent=SpriteComponent;
	SpriteComponent->SetCollisionProfileName("NoCollision");

	if(CollisionComponentClass!=nullptr)
	{
		CollisionComponent=CreateDefaultSubobject<UPrimitiveComponent>(TEXT("CollisionComponent"));
		CollisionComponent->SetCollisionResponseToAllChannels(ECR_Overlap);
		CollisionComponent->SetGenerateOverlapEvents(true);
		CollisionComponent->OnComponentHit.AddDynamic(this,&AProjectileBase::OnHit);
	}
}

void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AProjectileBase::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	AEnemyBase* Enemy=Cast<AEnemyBase>(OtherActor);
	if(Enemy)
	{
		if(Penetrate>0)
		{
			--Penetrate;
			PenetrateEvent_Implementation(Enemy);
		}
		else if(Bounce>0)
		{
			--Bounce;
			BounceEvent_Implementation(Enemy);
		}
		else
		{
			ProjectileEnd_Implementation();
			ProjectileDestroy();
		}
		
	}
}

void AProjectileBase::ProjectileDestroy()
{
}

void AProjectileBase::ProjectileEnd_Implementation()
{
}

void AProjectileBase::BounceEvent_Implementation(AEnemyBase* Target)
{
}

void AProjectileBase::PenetrateEvent_Implementation(AEnemyBase* Target)
{
}



