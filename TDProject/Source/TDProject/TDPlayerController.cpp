#include "TDPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Characters/TDCharacterBase.h"
#include "Engine/World.h"
#include "Engine/LocalPlayer.h"

// Sets default values
ATDPlayerController::ATDPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	CachedDestination = FVector::ZeroVector;
	FollowTime = 0.f;
}

// Called when the game starts or when spawned
void ATDPlayerController::BeginPlay()
{
	Super::BeginPlay();


}

void ATDPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	
}
