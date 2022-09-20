// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDWidget.h"
#include "Kismet/GameplayStatics.h"
#include <BombScape/BombScapeCharacter.h>

void UHUDWidget::NativeOnInitialized()
{
	Super::OnInitialized();

	//con esto puedo obtener el personaje
	ACharacter* Character = UGameplayStatics::GetPlayerCharacter(this, 0);
	if (ABombScapeCharacter* BSCharacter = Character ? Cast<ABombScapeCharacter>(Character) : nullptr) {
		BSCharacter->OnPLayerReviceDamageC.AddDynamic(this, &UHUDWidget::OnPlayerRecivedDamage);
	}
	
}

void UHUDWidget::OnPlayerRecivedDamage(int currentLife)
{
	BP_OnPlayerRecivedDamage(currentLife);
}
