#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "../Components/CActionComponent.h"
#include "CAnimInstance.generated.h"

UCLASS()
class FPS_ACTION_API UCAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Animation")
		float Speed;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Animation")
		float Direction;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Animation")
		float Pitch;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		EActionType ActionType;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Animation")
		bool bEquipped;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Animation")
		bool bAiming;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Animation")
		bool bRunning;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Animation")
		bool bFiring;



private:
	UFUNCTION()
		void OnActionTypeChanged(EActionType InPrevType, EActionType InNewType);

	ACharacter* OwnerCharacter;
};
