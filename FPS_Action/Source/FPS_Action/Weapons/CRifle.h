#pragma once

#include "CoreMinimal.h"
#include "CWeapon.h"
#include "CRifle.generated.h"

UCLASS()
class FPS_ACTION_API ACRifle : public ACWeapon
{
	GENERATED_BODY()

public:
	ACRifle();

protected:
	virtual void BeginPlay() override;

public:
	void Begin_Aim();
	void End_Aim();

	static ACRifle* Spawn(class UWorld* InWorld, class ACharacter* InOwner);
	
};
