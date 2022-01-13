#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CActionComponent.generated.h"

UENUM(BlueprintType)
enum class EActionType : uint8
{
	Unarmed, Pistol, Rifle, Max
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FActionTypeChanged, EActionType, InPrevType, EActionType, InNewType);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPS_ACTION_API UCActionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsUnarmedMode() { return Type == EActionType::Unarmed; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsPistolMode() { return Type == EActionType::Pistol; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsRifleMode() { return Type == EActionType::Rifle; }

public:	
	UCActionComponent();

	void SetUnarmedMode();
	void SetPistolMode();
	void SetRifleMode();

private:
	void SetMode(EActionType InType);
	void ChangeType(EActionType InNewType);	//타입이 바뀌면 델리게이션 콜

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintAssignable)
		FActionTypeChanged OnActionTypeChanged;
private:
	EActionType Type;
		
};
