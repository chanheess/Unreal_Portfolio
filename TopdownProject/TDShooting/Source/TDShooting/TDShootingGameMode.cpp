// Copyright Epic Games, Inc. All Rights Reserved.

#include "TDShootingGameMode.h"
#include "TDShootingPlayerController.h"
#include "TDShootingCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATDShootingGameMode::ATDShootingGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATDShootingPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}