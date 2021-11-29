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
	UFUNCTION()
		void Firing();

	void Begin_Aim();
	void End_Aim();

	void Begin_Fire();
	void End_Fire();

	static ACPistol* Spawn(class UWorld* InWorld, class ACharacter* InOwner);

private:
	//UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	//	class USoundCue* FireSoundCue;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		TSubclassOf<class UCameraShake> CameraShakeClass;

public:
	FORCEINLINE	bool GetFiring() { return bFiring; }

private:
	bool bFiring;

};
