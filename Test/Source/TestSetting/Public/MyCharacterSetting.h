#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyCharacterSetting.generated.h"

UCLASS(config=Test)
class TESTSETTING_API UMyCharacterSetting : public UObject
{
	GENERATED_BODY()
	
public:
	UMyCharacterSetting();

	UPROPERTY(config)
		TArray<FSoftObjectPath> CharacterAssets;
};
