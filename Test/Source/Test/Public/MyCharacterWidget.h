#pragma once

#include "Test.h"
#include "Blueprint/UserWidget.h"
#include "MyCharacterWidget.generated.h"

UCLASS()
class TEST_API UMyCharacterWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void BindCharacterStat(class UMyCharacterStatComponent* NewCharacterStat);

protected:
	virtual void NativeConstruct() override;
	void UpdateHpWidget();

private:
	TWeakObjectPtr<class UMyCharacterStatComponent> CurrentCharacterStat;

	UPROPERTY()
		class UProgressBar* HpProgressBar;
};
