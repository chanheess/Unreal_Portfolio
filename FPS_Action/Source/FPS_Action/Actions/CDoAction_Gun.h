#pragma once

#include "CoreMinimal.h"
#include "CDoAction.h"
#include "CDoAction_Gun.generated.h"

UCLASS()
class FPS_ACTION_API ACDoAction_Gun : public ACDoAction
{
	GENERATED_BODY()

public:
	virtual void DoAction() override;
	virtual void Begin_DoAction() override;
	virtual void End_DoAction() override;

	virtual void OnAttachmentBeginOverlap(class ACharacter* InAttacker, class AActor* InAttackCauser, class ACharacter* InOtherCharacter) override;
	virtual void OnAttachmentEndOverlap(class ACharacter* InAttacker, class AActor* InAttackCauser, class ACharacter* InOtherCharacter) override;

private:
	UFUNCTION()
		void RestoreGlobalDilation();

	UPROPERTY(EditDefaultsOnly)
		float LimitPitch = 0.25f;

	void Firing();

private:
	TArray<class ACharacter*> HittedCharacter;

	float Pitch;
	
};
