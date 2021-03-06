#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStateComponent.h"
#include "Engine/DataTable.h"
#include "CMontagesComponent.generated.h"

USTRUCT(BlueprintType)
struct FMontageData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		EStateType Type;

	UPROPERTY(EditAnywhere)
		class UAnimMontage* AnimMontage;

	UPROPERTY(EditAnywhere)
		float PlayRatio = 1.0f;

	UPROPERTY(EditAnywhere)
		FName StartSection;

	UPROPERTY(EditAnywhere)
		bool bCanMove;

};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPS_ACTION_API UCMontagesComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category = "DataTable")
		UDataTable* DataTable;
public:	
	UCMontagesComponent();

	void PlayAction();
	void PlayAim();
	void PlayHitted();
	void PlayDead();

protected:
	virtual void BeginPlay() override;

private:
	void PlayAnimMontage(EStateType InStateType);

private:	
	FMontageData* Datas[(int32)EStateType::Max];

};
