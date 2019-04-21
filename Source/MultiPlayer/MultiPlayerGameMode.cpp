// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "MultiPlayerGameMode.h"
#include "MultiPlayerCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "MyPlayerController.h"
#include "MyGameSession.h"

AMultiPlayerGameMode::AMultiPlayerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	PlayerControllerClass = AMyPlayerController::StaticClass();
	GameSessionClass = AMyGameSession::StaticClass();
}
