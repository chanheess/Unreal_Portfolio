#pragma once

#include "CoreMinimal.h"
#include "CEnemy.h"
#include "CEnemy_Zombie.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnAttackEndDelegate);

UCLASS()
class FPS_ACTION_API ACEnemy_Zombie : public ACEnemy
{
	GENERATED_BODY()
	
public:
	ACEnemy_Zombie();
	virtual void PostInitializeComponents() override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(BlueprintReadOnly, VisibleInstanceOnly, Category = "Attack", Meta = (AllowPrivateAccess = true))
		bool IsAttacking = false;

	UPROPERTY(BlueprintReadOnly, VisibleInstanceOnly, Category = "Attack", Meta = (AllowPrivateAccess = true))
		bool CanNextCombo;

	UPROPERTY(BlueprintReadOnly, VisibleInstanceOnly, Category = "Attack", Meta = (AllowPrivateAccess = true))
		bool IsComboInputOn;

	UPROPERTY(BlueprintReadOnly, VisibleInstanceOnly, Category = "Attack", Meta = (AllowPrivateAccess = true))
		int32 CurrentCombo;

	UPROPERTY(BlueprintReadOnly, VisibleInstanceOnly, Category = "Attack", Meta = (AllowPrivateAccess = true))
		int32 MaxCombo;

	UPROPERTY(BlueprintReadOnly, VisibleInstanceOnly, Category = "Attack", Meta = (AllowPrivateAccess = true))
		float AttackRange;

	UPROPERTY(BlueprintReadOnly, VisibleInstanceOnly, Category = "Attack", Meta = (AllowPrivateAccess = true))
		float AttackRadius;

	void AttackStartComboState();
	void AttackEndComboState();
	void AttackCheck();

public:
	UFUNCTION()
		void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	FOnAttackEndDelegate OnAttackEnd;

	void Attack();

protected:
	FRotator ArmRotationTo = FRotator::ZeroRotator;
	float ArmLengthTo = 0.0f;
	float ArmLengthSpeed = 0.0f;
	float ArmRotationSpeed = 0.0f;

	UPROPERTY()
		class UCAnimInstance_Zombie* animInstance;
};
