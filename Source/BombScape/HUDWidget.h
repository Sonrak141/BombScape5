// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class BOMBSCAPE_API UHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void NativeOnInitialized() override;

protected:
	UFUNCTION()
	void OnPlayerRecivedDamage(int currentLife);

	UFUNCTION(BlueprintImplementableEvent)
		void BP_OnPlayerRecivedDamage(int currentLife);

};
