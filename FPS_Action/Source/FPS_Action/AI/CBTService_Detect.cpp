#include "CBTService_Detect.h"
#include "CAIController.h"
#include "../Characters/CPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"

UCBTService_Detect::UCBTService_Detect()
{
	NodeName = TEXT("Detect");
	Interval = 1.0f;
	RandomDeviation = 1.0f;
}

void UCBTService_Detect::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn) return;

	UWorld* World = ControllingPawn->GetWorld();
	FVector Center = ControllingPawn->GetActorLocation();
	float DetectRadius = 3000.0f;

	

	if (nullptr == World) return;
	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams CollisionQueryParam(NAME_None, false, ControllingPawn);
	bool bResult = World->OverlapMultiByChannel(	//이걸 linetracesingle로바꾼다.
		OverlapResults,
		Center,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(DetectRadius),
		CollisionQueryParam
	);

	if (bResult)
	{
		for (auto const& OverlapResult : OverlapResults)
		{
			ACPlayer* CPlayer = Cast<ACPlayer>(OverlapResult.GetActor());
			if (CPlayer && CPlayer->GetController()->IsPlayerController())
			{
				//OwnerComp.GetBlackboardComponent()->SetValueAsObject(ACAIController::TargetKey, CPlayer);
				//DrawDebugSphere(World, Center, DetectRadius, 16, FColor::Green, false, 0.2f);
				//DrawDebugLine(World, ControllingPawn->GetActorLocation(), CPlayer->GetActorLocation(), FColor::Blue, false, 0.2f);

				FHitResult hitResult;
				FCollisionQueryParams params;
				params.AddIgnoredActor(ControllingPawn);
				if (GetWorld()->LineTraceSingleByChannel(hitResult, ControllingPawn->GetActorLocation(), CPlayer->GetActorLocation(), ECollisionChannel::ECC_WorldDynamic, params))
				{
					DrawDebugLine(World, ControllingPawn->GetActorLocation(), hitResult.Location, FColor::Green, false, 5.0f);
					OwnerComp.GetBlackboardComponent()->SetValueAsObject(ACAIController::TargetKey, CPlayer);
					return;
				}
				//return;
			}
		}
	}

	DrawDebugSphere(World, Center, DetectRadius, 16, FColor::Red, false, 0.2f);
}