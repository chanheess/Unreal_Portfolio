#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CWeapon.generated.h"

UCLASS()
class FPS_ACTION_API ACWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	ACWeapon();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION()
		void Fired();

	void Equip();
	void Unequip();
	void Equipped_Montage();
	void Unequipped_Montage();

	void Begin_Fire();
	void End_Fire();
	void Begin_Firing_Montage();
	void End_Firing_Montage();

public:
	FORCEINLINE	bool GetEquipped() { return bEquipped; }
	FORCEINLINE	bool GetAiming() { return bAiming; }
	FORCEINLINE	bool GetFiring() { return bFiring; }
	FORCEINLINE	float GetMaxRunSpeed() { return MaxRunSpeed; }

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		float LimitPitch;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		FName HolsterSocket;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		FName HandSocket;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		class USoundCue* FireSoundCue;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		class UParticleSystem* FlashParticle;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		class UParticleSystem* EjectParticle;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		class UParticleSystem* ImpactParticle;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		class UMaterialInstanceConstant* DecalMaterial;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		TSubclassOf<class UCameraShake> CameraShakeClass;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		TSubclassOf<class ACBullet> BulletClass;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Montages")
		class UAnimMontage* EquippedMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
		class UAnimMontage* UnequippedMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
		class UAnimMontage* FiringMontage;

	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Mesh;

	class ACharacter* OwnerCharacter;

protected:
	bool bEquipped;
	bool bAiming;
	bool bFiring;

	float Pitch;
	float MaxRunSpeed = 700;
};

