#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStateComponent.generated.h"

UENUM(BlueprintType)
enum class EStateType : uint8
{
	Idle, Aim, Equip, Action, Hitted, Dead, Peinit, Loading, Ready, Max
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FStateTypeChanged, EStateType, InPrevType, EStateType, InNewType);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPS_ACTION_API UCStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsIdleMode() { return Type == EStateType::Idle; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsAimMode() { return Type == EStateType::Aim; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsEquipMode() { return Type == EStateType::Equip; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsActionMode() { return Type == EStateType::Action; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsHittedMode() { return Type == EStateType::Hitted; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsDeadMode() { return Type == EStateType::Dead; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsPeinitMode() { return Type == EStateType::Dead; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsLoadingMode() { return Type == EStateType::Dead; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsReadyMode() { return Type == EStateType::Dead; }

public:	
	UCStateComponent();

	void SetIdleMode();
	void SetAimMode();
	void SetEquipMode();
	void SetActionMode();
	void SetHittedMode();
	void SetDeadMode();

	EStateType GetCurrentState() const;

protected:
	virtual void BeginPlay() override;

private:
	void ChangeType(EStateType InNewType);

public:
	UPROPERTY(BlueprintAssignable)
		FStateTypeChanged OnStateTypeChanged;

private:
	EStateType Type;

};
