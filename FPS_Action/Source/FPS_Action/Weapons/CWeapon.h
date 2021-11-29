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
	void Equip();
	void Unequip();

	void Equipped_Montage();
	void Unequipped_Montage();

public:
	FORCEINLINE	bool GetEquipped() { return bEquipped; }
	FORCEINLINE	bool GetAiming() { return bAiming; }

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		float LimitPitch;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		FName HolsterSocket;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		FName HandSocket;

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
		class UAnimMontage* EquippedMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
		class UAnimMontage* UnequippedMontage;

	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Mesh;

	class ACharacter* OwnerCharacter;

	bool bEquipped;
	bool bAiming;

	float Pitch;
};

