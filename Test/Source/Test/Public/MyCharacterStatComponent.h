#pragma once

#include "Test.h"
#include "Components/ActorComponent.h"
#include "MyCharacterStatComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnHpIsZeroDelegate);
DECLARE_MULTICAST_DELEGATE(FOnHpChangedDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEST_API UMyCharacterStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UMyCharacterStatComponent();

protected:
	virtual void BeginPlay() override;
	virtual void InitializeComponent() override;

public:
	void SetNewLevel(int32 NewLevel);
	void SetDamage(float NewDamage);
	void SetHp(float NewHp);

	float GetAttack();
	float GetHpRatio();

	FOnHpIsZeroDelegate OnHpIsZero;
	FOnHpChangedDelegate OnHpChanged;

private:
	struct FMyCharacterData* CurrentStatData = nullptr;

	UPROPERTY(EditInstanceOnly, Category = "stat", Meta = (AllowPrivateAccess = true))
		int32 Level;

	UPROPERTY(EditInstanceOnly, Transient, Category = "stat", meta = (AllowPrivateAccess = true))
		float CurrentHp;
};
