#include "MyCharacterStatComponent.h"
#include "CGameInstance.h"
#include "CLog.h"

UMyCharacterStatComponent::UMyCharacterStatComponent()
{
	bWantsInitializeComponent = true;

	Level = 1;
}

void UMyCharacterStatComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UMyCharacterStatComponent::InitializeComponent()
{
	Super::InitializeComponent();

	SetNewLevel(Level);
}

void UMyCharacterStatComponent::SetNewLevel(int32 NewLevel)
{
	auto MyGameInstance = Cast<UCGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (nullptr == MyGameInstance) return;

	CurrentStatData = MyGameInstance->GetMyCharacterData(NewLevel);
	if (!!CurrentStatData)
	{
		Level = NewLevel;
		SetHp(CurrentStatData->MaxHp);
	}
	else
	{
		CLog::Print(NewLevel + TEXT(" data doesn't exist"));
	}
}

void UMyCharacterStatComponent::SetDamage(float NewDamage)
{
	ABCHECK(!!CurrentStatData);
	SetHp(FMath::Clamp<float>(CurrentHp - NewDamage, 0.0f, CurrentStatData->MaxHp));
}

void UMyCharacterStatComponent::SetHp(float NewHp)
{
	CurrentHp = NewHp;
	OnHpChanged.Broadcast();
	if (CurrentHp < KINDA_SMALL_NUMBER)
	{
		CurrentHp = 0.0f;
		OnHpIsZero.Broadcast();
	}
}

float UMyCharacterStatComponent::GetAttack()
{
	ABCHECK(!!CurrentStatData, 0.0f);
	return CurrentStatData->Attack;
}

float UMyCharacterStatComponent::GetHpRatio()
{
	ABCHECK(!!CurrentStatData, 0.0f);

	return (CurrentStatData->MaxHp < KINDA_SMALL_NUMBER) ? 0.0f : (CurrentHp / CurrentStatData->MaxHp);
}
