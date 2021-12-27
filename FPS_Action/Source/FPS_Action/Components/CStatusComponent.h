#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStatusComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPS_ACTION_API UCStatusComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = "Speed")
		float WalkSpeed = 200;

	UPROPERTY(EditAnywhere, Category = "Speed")
		float RunSpeed = 400;

	UPROPERTY(EditAnywhere, Category = "Speed")
		float SprintSpeed = 600;

public:
	FORCEINLINE float GetWalkSpeed() { return WalkSpeed; }
	FORCEINLINE float GetRunSpeed() { return RunSpeed; }
	FORCEINLINE float GetSprintSpeed() { return SprintSpeed; }

	FORCEINLINE bool IsCanMove() { return bCanMove; }

public:	
	UCStatusComponent();
	
	void SetMove();
	void SetStop();

protected:
	virtual void BeginPlay() override;

private:
	bool bCanMove = true;
		
};
