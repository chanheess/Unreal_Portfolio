#include "CBTDecorator_InAttackRange.h"
#include "../Utilities/Global.h"
#include "CAIController.h"
#include "../Characters/CPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"


UCBTDecorator_InAttackRange::UCBTDecorator_InAttackRange()
{
	NodeName = TEXT("CanAttack");
}

bool UCBTDecorator_InAttackRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn) return false;

	auto Target = Cast<ACPlayer>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(ACAIController::TargetKey));
	if (nullptr == Target) return false;

	bResult = (Target->GetDistanceTo(ControllingPawn) <= 200.0f);
	return bResult;
}