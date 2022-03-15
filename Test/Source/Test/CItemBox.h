#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CItemBox.generated.h"

UCLASS()
class TEST_API ACItemBox : public AActor
{
	GENERATED_BODY()
	
public:	
	ACItemBox();

protected:
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

public:
	UPROPERTY(VisibleAnywhere, Category = Box)
		class UBoxComponent* Trigger;

	UPROPERTY(VisibleAnywhere, Category = Box)
		UStaticMeshComponent* Box;

	UPROPERTY(EditAnywhere, Category = "Box")
		TSubclassOf<class ACWeapon> WeaponItemClass;

	UPROPERTY(VisibleAnywhere, Category = Effect)
		class UParticleSystemComponent* Effect;

private:
	UFUNCTION()
		void OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnEffectFinished(class UParticleSystemComponent* PSystem);
};
