#include "CBTTask_TurnToTarget.h"
#include "CAIController.h"
#include "../Characters/CEnemy.h"
#include "../Characters/CPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"

UCBTTask_TurnToTarget::UCBTTask_TurnToTarget()
{
	NodeName = TEXT("Turn");
}

EBTNodeResult::Type UCBTTask_TurnToTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto Enemy = Cast<ACEnemy>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == Enemy) return EBTNodeResult::Failed;

	auto Target = Cast<ACPlayer>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(ACAIController::TargetKey));
	if (nullptr == Target) return EBTNodeResult::Failed;

	FVector LookVector = Target->GetActorLocation() - Enemy->GetActorLocation();
	LookVector.Z = 0.0f;
	FRotator TargetRot = FRotationMatrix::MakeFromX(LookVector).Rotator();
	Enemy->SetActorRotation(FMath::RInterpTo(Enemy->GetActorRotation(), TargetRot, GetWorld()->GetDeltaSeconds(), 2.0f));

	return EBTNodeResult::Succeeded;


}
