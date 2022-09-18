// Fill out your copyright notice in the Description page of Project Settings.


#include "TC_Bomb.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "BombScapeCharacter.h"
#include "BS_Wall.h"

// Sets default values
ATC_Bomb::ATC_Bomb()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//init Sphere Comp
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Component"));
	RootComponent = SphereCollision;
	SphereCollision->InitSphereRadius(0.f);
	SphereCollision->SetCollisionProfileName("NoCollision");//definicion de tipo de colicion

	//Init Mesh
	SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SphereVisual->SetupAttachment(SphereCollision);
	SphereVisual->SetSimulatePhysics(true);

	//Init Particles
	ExplosionParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Explosion Paticles"));
	ExplosionParticles->SetupAttachment(SphereVisual);
	ExplosionParticles->bAutoActivate = false;

}

// Called when the game starts or when spawned
void ATC_Bomb::BeginPlay()
{
	//aplicacion de fuerza inicial de la bomba
	const FVector Impulse = SphereVisual->GetForwardVector() * InitialForce;
	SphereVisual->AddImpulse(Impulse);

	Super::BeginPlay();
	if (ExplodeTime < 0.f)
		return;



	GetWorldTimerManager().SetTimer(ExplodeTimeHandler, this, &ATC_Bomb::OnExplode, ExplodeTime, false); //este es el uso del time manager del mundo
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ATC_Bomb::OnComponentBeginOverlapInBomb);
	
}


void ATC_Bomb::OnExplode()
{
	SphereCollision->SetCollisionProfileName("OverlapAll");
	//Evento de fin de particulas
	SphereCollision->SetSphereRadius(60.f, true); // con el true hago qu se inicie el overlap de nuevo
	ExplosionParticles->OnSystemFinished.AddDynamic(this, &ATC_Bomb::OnParticleSystemFinished);
	GetWorldTimerManager().SetTimer(ExplosionTimeHandler, this, &ATC_Bomb::OnFinishExplosion, ExplosionTime, false);
	ExplosionParticles->Activate(true);
	SphereVisual->SetSimulatePhysics(false);
	SphereVisual->SetHiddenInGame(true);
	
	
    

}

void ATC_Bomb::OnParticleSystemFinished(UParticleSystemComponent* PSystem)
{
	this->Destroy();
	
}

void ATC_Bomb::OnComponentBeginOverlapInBomb(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// es cast se hace porque el componente no detecta que tipo tiene el objeto que ah entrado, entonces tenemos que bsucar que sea un GameCharacter
	if (ABombScapeCharacter* Character = Cast<ABombScapeCharacter>(OtherActor))
	{
		//Si entra es que es Character
		Character->GetDamage(BombDamage);


	}
	if(ABS_Wall* Wall = Cast<ABS_Wall>(OtherActor))
	{
		Wall->GetDamage(BombDamage);
	}
	
}

void ATC_Bomb::OnFinishExplosion()
{
	this->Destroy();
}




