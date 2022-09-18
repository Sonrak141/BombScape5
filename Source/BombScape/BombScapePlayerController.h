// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUDWidget.h"
#include "GameFramework/PlayerController.h"
#include "BombScapePlayerController.generated.h"



class UUserWidget;
UCLASS()
class BOMBSCAPE_API ABombScapePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UHUDWidget>HUDClassWidget = nullptr;
protected:
	UHUDWidget* HUD;
};
