#pragma once

#include "CoreMinimal.h"
#include "CEnemy.h"
#include "CEnemy_Zombie.generated.h"

UCLASS()
class FPS_ACTION_API ACEnemy_Zombie : public ACEnemy
{
	GENERATED_BODY()
	
public:
	ACEnemy_Zombie();

protected:
	virtual void BeginPlay() override;

private:
	Attack();
};
