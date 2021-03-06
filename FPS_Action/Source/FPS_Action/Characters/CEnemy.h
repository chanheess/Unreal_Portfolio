#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ICharacter.h"
#include "../Components/CStateComponent.h"
#include "CEnemy.generated.h"

UCLASS()
class FPS_ACTION_API ACEnemy : public ACharacter, public IICharacter
{
	GENERATED_BODY()

public:
	ACEnemy();
	virtual void Tick(float DeltaTime) override;
	virtual void PostInitializeComponents() override;

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleDefaultsOnly)
		class UWidgetComponent* NameWidget;

	UPROPERTY(VisibleDefaultsOnly)
		class UWidgetComponent* HealthWidget;

	UPROPERTY(VisibleDefaultsOnly)
		class UCActionComponent* Action;

	UPROPERTY(VisibleDefaultsOnly)
		class UCMontagesComponent* Montages;
	
	UPROPERTY(VisibleDefaultsOnly)
		class UCStatusComponent* Status;

	UPROPERTY(VisibleDefaultsOnly)
		class UCStateComponent* State;

	//UPROPERTY()
	//	class UCAnimInstance_Zombie* animInstance;

	UFUNCTION()
		void OnStateTypeChanged(EStateType InPrevType, EStateType InNewType);

	UFUNCTION()
		void RestoreColor();

public:
	UFUNCTION()
		UCStateComponent* GetState() { return State; }

public:
	virtual void ChangeColor(FLinearColor InColor) override;
	virtual void GetLocationAndDirection(FVector& OutStart, FVector& OutEnd, FVector& OutDirection) override {  }

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	void OnWidget();
	void OffWidget();

private:
	void Hitted();
	void Dead();

public:
	void OnDoAction();


protected:
	USkeletalMesh* mesh;

	class UMaterialInstanceDynamic* BodyMaterial;
	class AController* DamageInstigator; 
	float DamageValue;

};
