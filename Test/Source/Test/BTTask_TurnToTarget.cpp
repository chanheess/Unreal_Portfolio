#include "BTTask_TurnToTarget.h"
#include "CAIController.h"
#include "MyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_TurnToTarget::UBTTask_TurnToTarget()
{
	NodeName = TEXT("Turn");
}

EBTNodeResult::Type UBTTask_TurnToTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto MyCharacter = Cast<AMyCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (NULL == MyCharacter) return EBTNodeResult::Failed;

	auto Target = Cast<AMyCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(ACAIController::TargetKey));
	if (NULL == Target) return EBTNodeResult::Failed;

	FVector LookVector = Target->GetActorLocation() - MyCharacter->GetActorLocation();
	LookVector.Z = 0.0f;
	FRotator TargetRot = FRotationMatrix::MakeFromX(LookVector).Rotator();
	MyCharacter->SetActorRotation(FMath::RInterpTo(MyCharacter->GetActorRotation(), TargetRot, GetWorld()->GetDeltaSeconds(), 2.0f));

	return EBTNodeResult::Succeeded;


}
