// Fill out your copyright notice in the Description page of Project Settings.


#include "BombScapePlayerController.h"

void ABombScapePlayerController::BeginPlay()
{
	Super::BeginPlay();
	HUD = CreateWidget<UHUDWidget>(this, HUDClassWidget);
	if(!HUD)
		return;
	HUD->AddToViewport();
}
