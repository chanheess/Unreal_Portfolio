#pragma once

#include "CoreMinimal.h"
#include "CEnemy.h"
#include "CEnemy_Dummy.generated.h"

UCLASS()
class FPS_ACTION_API ACEnemy_Dummy : public ACEnemy
{
	GENERATED_BODY()

public:
	ACEnemy_Dummy();

protected:
	virtual void BeginPlay() override;
	
};
