#pragma once

#include "Test.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnAttackEndDelegate);

UCLASS()
class TEST_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMyCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PostInitializeComponents() override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator, AActor* DamageCauser) override;
	virtual void PossessedBy(AController* NewController) override;

public:
	UPROPERTY(VisibleAnywhere, Category = "Camera")
		class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
		class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Category = "Weapon")
		class ACWeapon* CurrentWeapon;

	UPROPERTY(VisibleAnywhere, Category = "Stat")
		class UMyCharacterStatComponent* CharacterStat;

	UPROPERTY(VisibleAnywhere, Category = "UI")
		class UWidgetComponent* HpBarWidget;

public:
	bool CanSetWeapon();
	void SetWeapon(class ACWeapon* NewWeapon);

	void Attack();

	FOnAttackEndDelegate OnAttackEnd;

private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
	void LookUp(float NewAxisValue);
	void Turn(float NewAxisValue);

	void ViewChange();

	void AttackStartComboState();
	void AttackEndComboState();
	void AttackCheck();

	UFUNCTION()
		void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);


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

	UPROPERTY()
		class UCAnimInstance* CAnim;

protected:
	enum class EControlMode
	{
		TPS,
		TOPDOWN,
		NPC
	};

	void SetControlMode(EControlMode NewControlMode);

	EControlMode CurrentControlMode = EControlMode::TOPDOWN;
	FVector DirectionToMove = FVector::ZeroVector;

	FRotator ArmRotationTo = FRotator::ZeroRotator;
	float ArmLengthTo = 0.0f;
	float ArmLengthSpeed = 0.0f;
	float ArmRotationSpeed = 0.0f;
};
