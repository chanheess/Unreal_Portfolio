#include "MyCharacterWidget.h"
#include "MyCharacterStatComponent.h"
#include "Components/ProgressBar.h"


void UMyCharacterWidget::BindCharacterStat(UMyCharacterStatComponent* NewCharacterStat)
{
	ABCHECK(!!NewCharacterStat);

	CurrentCharacterStat = NewCharacterStat;
	NewCharacterStat->OnHpChanged.AddUObject(this, &UMyCharacterWidget::UpdateHpWidget);
}

void UMyCharacterWidget::NativeConstruct()
{
	Super::NativeConstruct();
	HpProgressBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("PB_HpBar")));
	ABCHECK(!!HpProgressBar);
	UpdateHpWidget();
}

void UMyCharacterWidget::UpdateHpWidget()
{
	if (CurrentCharacterStat.IsValid())
	{
		if (!!HpProgressBar)
		{
			HpProgressBar->SetPercent(CurrentCharacterStat->GetHpRatio());
		}
	}
}
