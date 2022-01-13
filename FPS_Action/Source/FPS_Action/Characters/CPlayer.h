#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Components/CStateComponent.h"
#include "../Weapons/IWeapon.h"
#include "CPlayer.generated.h"

UCLASS()
class FPS_ACTION_API ACPlayer : public ACharacter, public IIWeapon
{
	GENERATED_BODY()

public:
	ACPlayer();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:	//Scene Component
	UPROPERTY(VisibleDefaultsOnly)
		class USpringArmComponent* SpringArm;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
		TSubclassOf<class UCUserWidget_CrossHair> CrossHairClass;

protected:
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
		class UCameraComponent* Camera;

	UFUNCTION(BlueprintImplementableEvent)
		void ZoomIn();

	UFUNCTION(BlueprintImplementableEvent)
		void ZoomOut();

private:	//Actor Component
	UPROPERTY(VisibleDefaultsOnly)
		class UCStatusComponent* Status;

	UPROPERTY(VisibleDefaultsOnly)
		class UCOptionComponent* Option;

	UPROPERTY(VisibleDefaultsOnly)
		class UCStateComponent* State;

	UPROPERTY(VisibleDefaultsOnly)
		class UCMontagesComponent* Montages;

	UPROPERTY(VisibleDefaultsOnly)
		class UCActionComponent* Action;

public:
	FORCEINLINE class ACWeapon* GetWeapon() override { return Weapon; }
	FORCEINLINE	bool GetRunning() { return bRunning; }

private:
	void OnMoveForward(float InAxis);
	void OnMoveRight(float InAxis);
	void OnHorizontalLook(float InAxis);
	void OnVerticalLook(float InAxis);

	void OnRun();
	void OffRun();

	void OnWeapon(ACWeapon& weapons);
	void OnPistol();
	void OnRifle();

	void OnAim();
	void OffAim();

	void OnFire();
	void OffFire();

	UFUNCTION()
		void OnStateTypeChanged(EStateType InPrevType, EStateType InNewType);

public:
	void OnFocus() override;
	void OffFocus() override;
	void GetLocationAndDirection(FVector& OutStart, FVector& OutEnd, FVector& OutDirection) override;

private:
	class ACWeapon* Weapon;
	class ACPistol* Pistol;
	class ACRifle* Rifle;
	class UCUserWidget_CrossHair* Crosshair;
	//class UCUserWidget_AutoFire* AutoFire;

	bool bRunning;
};
