#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "CBTService_Detect.generated.h"

UCLASS()
class FPS_ACTION_API UCBTService_Detect : public UBTService
{
	GENERATED_BODY()

public:
	UCBTService_Detect();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
};
