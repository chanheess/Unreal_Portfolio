#pragma once

#include "CoreMinimal.h"
#include "CWeapon.h"
#include "CPistol.generated.h"

UCLASS()
class FPS_ACTION_API ACPistol : public ACWeapon
{
	GENERATED_BODY()

public:
	ACPistol();

protected:
	virtual void BeginPlay() override;

public:
	void Begin_Aim();
	void End_Aim();

	static ACPistol* Spawn(class UWorld* InWorld, class ACharacter* InOwner);

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		class UCameraComponent* AimCamera;

	UPROPERTY(VisibleAnywhere)
		class USpringArmComponent* AimSpringArm;

};
