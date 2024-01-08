#pragma once

#include "CoreMinimal.h"
#include "CDoAction.h"
#include "CDoAction_Melee.generated.h"

UCLASS()
class FPS_ACTION_API ACDoAction_Melee : public ACDoAction
{
	GENERATED_BODY()

public:
	FORCEINLINE void EnableCombo() { bEnable = true; }
	FORCEINLINE void DisableCombo() { bEnable = false; }

public:
	virtual void DoAction() override;
	virtual void Begin_DoAction() override;
	virtual void End_DoAction() override;
	
	virtual void OnAttachmentBeginOverlap(class ACharacter* InAttacker, class AActor* InAttackCauser, class ACharacter* InOtherCharacter) override;
	virtual void OnAttachmentEndOverlap(class ACharacter* InAttacker, class AActor* InAttackCauser, class ACharacter* InOtherCharacter) override;

private:
	UFUNCTION()
		void RestoreGlobalDilation();

	int32 ComboNum;

	bool bEnable;
	bool bExist;
	bool bLast;

	TArray<class ACharacter*> HittedCharacter;
};
