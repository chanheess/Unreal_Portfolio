#pragma once

#include "CoreMinimal.h"
#include "CDoAction.h"
#include "CDoAction_Gun.generated.h"

UCLASS()
class FPS_ACTION_API ACDoAction_Gun : public ACDoAction
{
	GENERATED_BODY()

public:
	ACDoAction_Gun();
	virtual void Tick(float DeltaTime) override;

public:
	virtual void DoAction() override;
	virtual void Begin_DoAction() override;
	virtual void End_DoAction() override;


private:
	UFUNCTION()
		void RestoreGlobalDilation();

	//UPROPERTY(EditDefaultsOnly)
	//	TSubclassOf<class ACBullet> BulletClass;

	void Firing();

private:
	TArray<class ACharacter*> HittedCharacter;
	FTimerHandle AutoFireTimer;

	float Pitch;
	
};
