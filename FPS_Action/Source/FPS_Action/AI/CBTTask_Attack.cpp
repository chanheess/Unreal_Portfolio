#include "CBTTask_Attack.h"
#include "../Utilities/Global.h"
#include "CAIController.h"
#include "../Characters/CEnemy_Zombie.h"

UCBTTask_Attack::UCBTTask_Attack()
{
	bNotifyTick = true;
	IsAttacking = false;
}

EBTNodeResult::Type UCBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto CEnemy = Cast<ACEnemy_Zombie>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == CEnemy) return EBTNodeResult::Failed;

	CEnemy->Attack();
	IsAttacking = true;
	CEnemy->OnAttackEnd.AddLambda([this]() -> void {
		IsAttacking = false;
		CLog::Print("EndAttack");
		});
	
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







//EBTNodeResult::Type UCBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
//{
//	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);
//
//	auto CEnemy = Cast<ACEnemy>(OwnerComp.GetAIOwner()->GetPawn());
//	if (nullptr == CEnemy) return EBTNodeResult::Failed;
//
//	CEnemy->OnDoAction();
//
//	return EBTNodeResult::InProgress;
//}
//
//void UCBTTask_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
//{
//	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
//
//	auto CEnemy = Cast<ACEnemy>(OwnerComp.GetAIOwner()->GetPawn());
//	if (nullptr == CEnemy) return;
//
//	if (!CEnemy->GetState()->IsActionMode())
//	{
//		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
//	}
//}