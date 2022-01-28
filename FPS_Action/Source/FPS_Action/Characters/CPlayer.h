#pragma once

#include "CoreMinimal.h"
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

public:
	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
		USkeletalMeshComponent* ArmMesh;

protected:
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
		class UCameraComponent* Camera;

	UFUNCTION(BlueprintImplementableEvent)
		void ZoomIn();

	UFUNCTION(BlueprintImplementableEvent)
		void ZoomOut();

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

	//Scene Component
	UPROPERTY(VisibleDefaultsOnly)
		class USpringArmComponent* SpringArm;

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
	void OnSprint();
	void OffSprint();

	void OnPistol();
	void OnRifle();
	void OnKnife();

	void OnDoAction();

	//void OnAim();
	//void OffAim();
	//
	//void OnFire();
	//void OffFire();

	UFUNCTION()
		void OnStateTypeChanged(EStateType InPrevType, EStateType InNewType);

public:	//ICharacter
	virtual void OnFocus() override;
	virtual void OffFocus() override;
	virtual void ChangeColor(FLinearColor InColor) override;
	virtual void GetLocationAndDirection(FVector& OutStart, FVector& OutEnd, FVector& OutDirection) override;

private:
	class UCUserWidget_CrossHair* Crosshair;
	class UMaterialInstanceDynamic* BodyMaterial;
	//class UCUserWidget_AutoFire* AutoFire;
};
