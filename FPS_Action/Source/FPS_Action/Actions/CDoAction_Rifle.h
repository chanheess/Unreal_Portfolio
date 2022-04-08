// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CDoAction.h"
#include "CDoAction_Rifle.generated.h"

/**
 * 
 */
UCLASS()
class FPS_ACTION_API ACDoAction_Rifle : public ACDoAction
{
	GENERATED_BODY()
	
public:
	virtual void DoAction() override;
	virtual void Begin_DoAction() override;
	virtual void End_DoAction() override;

public:
	FORCEINLINE void EnableCombo() { bEnable = true; }
	FORCEINLINE void DisableCombo() { bEnable = false; }

private:
	UFUNCTION()
		void RestoreGlobalDilation();

	UPROPERTY(EditDefaultsOnly)
		float LimitPitch = 0.25f;

	void Firing();

private:
	TArray<class ACharacter*> HittedCharacter;
	FTimerHandle AutoFireTimer;

	float Pitch;
	int32 BulletNum;

	bool bEnable;
	bool bExist;
	bool bLast;

};
