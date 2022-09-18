// Copyright Epic Games, Inc. All Rights Reserved.

#include "BombScapeGameMode.h"
#include "BombScapeCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABombScapeGameMode::ABombScapeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
