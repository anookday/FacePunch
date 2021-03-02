// Copyright Epic Games, Inc. All Rights Reserved.

#include "FacePunchGameMode.h"
#include "FacePunchCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFacePunchGameMode::AFacePunchGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_PunchMan"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
