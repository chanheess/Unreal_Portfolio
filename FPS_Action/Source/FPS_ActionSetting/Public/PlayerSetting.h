#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlayerSetting.generated.h"

UCLASS(config=FPS_ACTION)
class FPS_ACTIONSETTING_API UPlayerSetting : public UObject
{
	GENERATED_BODY()
	
public:
	UPlayerSetting();

	UPROPERTY(config)
		TArray<FSoftObjectPath> CharacterAssets;
};
