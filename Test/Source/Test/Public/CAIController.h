#pragma once

#include "Test.h"
#include "AIController.h"
#include "CAIController.generated.h"

UCLASS()
class TEST_API ACAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ACAIController();

	virtual void OnPossess(APawn* InPawn) override;

private:
	UPROPERTY()
		class UBehaviorTree* BTAsset;

	UPROPERTY()
		class UBlackboardData* BBAsset;

public:
	static const FName HomePosKey;
	static const FName PatrolPosKey;
	static const FName TargetKey;
};
