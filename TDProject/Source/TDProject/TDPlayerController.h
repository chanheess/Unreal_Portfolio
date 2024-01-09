#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/PlayerController.h"
#include "TDPlayerController.generated.h"

/** Forward declaration to improve compiling times */
class UNiagaraSystem;
class UInputMappingContext;
class UInputAction;

UCLASS()
class TDPROJECT_API ATDPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Sets default values for this empty's properties
	ATDPlayerController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	FVector CachedDestination;
	bool bIsTouch; // Is it a touch device
	float FollowTime; // For how long it has been pressed

protected:
	uint32 bMoveToMouseCursor : 1;

};
