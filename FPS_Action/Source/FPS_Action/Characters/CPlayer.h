#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Character.h"
#include "../Components/CStateComponent.h"
#include "ICharacter.h"
#include "CPlayer.generated.h"

UCLASS()
class FPS_ACTION_API ACPlayer : public ACharacter, public IICharacter
{
	GENERATED_BODY()

public:
	ACPlayer();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

protected:
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Camera")
		class UCameraComponent* Camera;

	UFUNCTION(BlueprintImplementableEvent)
		void ZoomIn();

	UFUNCTION(BlueprintImplementableEvent)
		void ZoomOut();

private:
	//Scene Component
	UPROPERTY(VisibleDefaultsOnly, Category = "Camera")
		class USpringArmComponent* SpringArm;

private:
	//Actor Component
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

private:
	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
		USkeletalMeshComponent* ArmMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
		TSubclassOf<class UCUserWidget_CrossHair> CrossHairClass;

private:
	void OnMoveForward(float InAxis);
	void OnMoveRight(float InAxis);
	void OnHorizontalLook(float InAxis);
	void OnVerticalLook(float InAxis);

	void OnJump();
	void OffJump();

	void OnWalk();
	void OffWalk();

	void OnDoAction();

	void Hitted();
	void Dead();

	//void OnAim();
	//void OffAim();

	UFUNCTION()
		void OnStateTypeChanged(EStateType InPrevType, EStateType InNewType);

	UFUNCTION()
		void RestoreColor();
public:
	void OnPistol();
	void OnRifle();
	void OnKnife();


public:	//ICharacter
	virtual void OnFocus() override;
	virtual void OffFocus() override;
	virtual void ChangeColor(FLinearColor InColor) override;
	virtual void GetLocationAndDirection(FVector& OutStart, FVector& OutEnd, FVector& OutDirection) override;

private:
	class UCUserWidget_CrossHair* Crosshair;
	class UMaterialInstanceDynamic* BodyMaterial;
	//class UCUserWidget_AutoFire* AutoFire;

	class AController* DamageInstigator;
	float DamageValue;
};
