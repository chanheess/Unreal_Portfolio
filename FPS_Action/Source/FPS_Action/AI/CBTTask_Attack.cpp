#include "CBTTask_Attack.h"
#include "../Utilities/Global.h"
#include "CAIController.h"
#include "../Characters/CEnemy.h"

UCBTTask_Attack::UCBTTask_Attack()
{
	bNotifyTick = true;
}

EBTNodeResult::Type UCBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto CEnemy = Cast<ACEnemy>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == CEnemy) return EBTNodeResult::Failed;

	CEnemy->OnDoAction();

	return EBTNodeResult::InProgress;
}

void UCBTTask_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	auto CEnemy = Cast<ACEnemy>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == CEnemy) return;

	if (!CEnemy->GetState()->IsActionMode())
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}