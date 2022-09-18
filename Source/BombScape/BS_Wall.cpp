// Fill out your copyright notice in the Description page of Project Settings.


#include "BS_Wall.h"

#include "Components/BoxComponent.h"

// Sets default values
ABS_Wall::ABS_Wall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//init Collision
	//Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Component"));
	//RootComponent = Collision;
	//Collision->SetCollisionProfileName("OverlapAll");//definicion de tipo de colicion
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	//RootComponent = BoxCollision;
	BoxCollision->SetCollisionProfileName("OverlapAll");

	//Init Mesh
	Visual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Visual->SetupAttachment(BoxCollision);
	Visual->SetSimulatePhysics(true);

}

void ABS_Wall::GetDamage(int Damage)
{
	if(WallResistance != -1)
	{
		WallResistance -= Damage;
		if(WallResistance <= 0)
		{
			this->Destroy();
		}	
	}else
	{
		return;
	}
	
}

// Called when the game starts or when spawned
void ABS_Wall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABS_Wall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

