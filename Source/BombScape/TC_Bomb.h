// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TC_Bomb.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UParticleSystemCompnent;
class ABombScapeCharacter;

UCLASS()
class BOMBSCAPE_API ATC_Bomb : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ATC_Bomb();
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ExplodeTime = 2.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ExplosionTime = 1.f;
    
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USphereComponent* SphereCollision = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* SphereVisual = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UParticleSystemComponent* ExplosionParticles = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float InitialForce = 9.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int BombDamage;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void OnExplode();
	UFUNCTION()
		void OnParticleSystemFinished(UParticleSystemComponent* PSystem);
	UFUNCTION()
		void OnComponentBeginOverlapInBomb(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnFinishExplosion();




private:
	FTimerHandle ExplodeTimeHandler;
	FTimerHandle ExplosionTimeHandler;


};
