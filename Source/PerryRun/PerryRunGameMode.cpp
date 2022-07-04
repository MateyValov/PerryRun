// Copyright Epic Games, Inc. All Rights Reserved.

#include "PerryRunGameMode.h"
#include "PerryRunCharacter.h"
#include "UObject/ConstructorHelpers.h"

APerryRunGameMode::APerryRunGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
