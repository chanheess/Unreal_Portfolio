#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Weapons/IWeapon.h"
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

private:
	UPROPERTY(VisibleAnywhere)
		class USpringArmComponent* SpringArm;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
		TSubclassOf<class UCUserWidget_CrossHair> CrossHairClass;

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		class UCameraComponent* Camera;

	UFUNCTION(BlueprintImplementableEvent)
		void ZoomIn();

	UFUNCTION(BlueprintImplementableEvent)
		void ZoomOut();

public:
	FORCEINLINE class ACWeapon* GetWeapon() override { return Weapon; }
	FORCEINLINE	bool GetRunning() { return bRunning; }

private:
	void OnMoveForward(float Axis);
	void OnMoveRight(float Axis);
	void OnHorizontalLook(float Axis);
	void OnVerticalLook(float Axis);

	void OnRun();
	void OffRun();

	void OnWeapon(ACWeapon& weapons);
	void OnPistol();

	void OnAim();
	void OffAim();

	void OnFire();
	void OffFire();

public:
	void OnFocus() override;
	void OffFocus() override;
	void GetLocationAndDirection(FVector& OutStart, FVector& OutEnd, FVector& OutDirection) override;

private:
	class ACWeapon* Weapon;
	class ACPistol* Pistol;
	class UCUserWidget_CrossHair* Crosshair;
	//class UCUserWidget_AutoFire* AutoFire;

	bool bRunning;
};
