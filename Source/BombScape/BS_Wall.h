// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "BS_Wall.generated.h"

class UStaticMeshComponent;
class USphereComponent;
class UBoxComponent;
UCLASS()
class BOMBSCAPE_API ABS_Wall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABS_Wall();
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float WallResistance = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* Visual = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USphereComponent* Collision = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UBoxComponent* BoxCollision = nullptr;

	void GetDamage(int Damage);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
