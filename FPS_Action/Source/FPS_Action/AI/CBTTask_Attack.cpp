#include "CBTTask_Attack.h"
#include "CAIController.h"
#include "../Characters/CEnemy.h"

UCBTTask_Attack::UCBTTask_Attack()
{
	bNotifyTick = true;
	IsAttacking = false;
}

EBTNodeResult::Type UCBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto CEnemy = Cast<ACEnemy>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == CEnemy) return EBTNodeResult::Failed;

	CEnemy->OnDoAction();

	/*MyCharacter->Attack();
	IsAttacking = true;
	MyCharacter->OnAttackEnd.AddLambda([this]() -> void {
		IsAttacking = false;
		});*/

	return EBTNodeResult::InProgress;
}

void UCBTTask_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
	if (!IsAttacking)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}