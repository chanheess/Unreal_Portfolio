#pragma once

#include "EngineMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "CBTDecorator_InAttackRange.generated.h"

UCLASS()
class FPS_ACTION_API UCBTDecorator_InAttackRange : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UCBTDecorator_InAttackRange();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
