#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "CBTTask_TurnToTarget.generated.h"

UCLASS()
class FPS_ACTION_API UCBTTask_TurnToTarget : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UCBTTask_TurnToTarget();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};
