#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CActionComponent.generated.h"

UENUM(BlueprintType)
enum class EActionType : uint8
{
	Unarmed, Pistol, Rifle, Knife, Max
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FActionTypeChanged, EActionType, InPrevType, EActionType, InNewType);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPS_ACTION_API UCActionComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
		class UCActionData* Datas[(int32)EActionType::Max];

public:
	UFUNCTION(BlueprintPure)
		FORCEINLINE class UCActionData* GetCurrent() { return Datas[(int32)Type]; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsUnarmedMode() { return Type == EActionType::Unarmed; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsPistolMode() { return Type == EActionType::Pistol; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsRifleMode() { return Type == EActionType::Rifle; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsKnifeMode() { return Type == EActionType::Knife; }

public:	
	UCActionComponent();

	void SetUnarmedMode();
	void SetPistolMode();
	void SetRifleMode();
	void SetKnifeMode();

	void DoAction();

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
