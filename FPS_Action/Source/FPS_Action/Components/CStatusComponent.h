#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStatusComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPS_ACTION_API UCStatusComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = "Health")
		float MaxHealth = 100;

	UPROPERTY(EditAnywhere, Category = "Speed")
		float WalkSpeed = 500;

	UPROPERTY(EditAnywhere, Category = "Speed")
		float RunSpeed = 700;

public:
	FORCEINLINE float GetMaxHealth() { return MaxHealth; }
	FORCEINLINE float GetHealth() { return Health; }

	FORCEINLINE float GetWalkSpeed() { return WalkSpeed; }
	FORCEINLINE float GetRunSpeed() { return RunSpeed; }

	FORCEINLINE bool IsCanMove() { return bCanMove; }
	FORCEINLINE bool IsReleased() { return bReleased; }

	FORCEINLINE void SetReleased(bool InReleased) { bReleased = InReleased; }

public:	
	UCStatusComponent();

	void AddHealth(float InAmount);
	void SubHealth(float InAmount);
	
	void SetMove();
	void SetStop();

protected:
	virtual void BeginPlay() override;

private:
	float Health;
	bool bCanMove = true;
	bool bReleased = false;
};
