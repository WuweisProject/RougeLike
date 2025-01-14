#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"

class AEnemyBase;
class UBoxComponent;
class UPaperSpriteComponent;

UCLASS()
class ROUGELIKE_API AProjectileBase : public AActor
{
	GENERATED_BODY()
public:
	AProjectileBase();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	UPaperSpriteComponent* SpriteComponent;

	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	TSubclassOf<UPrimitiveComponent> CollisionComponentClass;

	UPROPERTY(BlueprintReadOnly)
	UPrimitiveComponent* CollisionComponent;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Property",DisplayName="穿透")
	int32 Penetrate;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Property",DisplayName="反弹")
	int32 Bounce;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Property",DisplayName="速度")
	float Speed;
protected:

	UFUNCTION()
	virtual void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	virtual void PenetrateEvent(AEnemyBase* Target);

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	virtual void BounceEvent(AEnemyBase* Target);

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	virtual void ProjectileEnd();

	void ProjectileDestroy();
};
