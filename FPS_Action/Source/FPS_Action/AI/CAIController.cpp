#include "CAIController.h"
#include "../Utilities/Global.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

const FName ACAIController::HomePosKey(TEXT("HomePos"));
const FName ACAIController::PatrolPosKey(TEXT("PatrolPos"));
const FName ACAIController::TargetKey(TEXT("Target"));


ACAIController::ACAIController()
{
	CHelpers::GetAsset<UBlackboardData>(&BBAsset, "BlackboardData'/Game/AI/BB_AICharacter.BB_AICharacter'");
	CHelpers::GetAsset<UBehaviorTree>(&BTAsset, "BehaviorTree'/Game/AI/BT_AICharacter.BT_AICharacter'");
}

void ACAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (UseBlackboard(BBAsset, Blackboard))
	{
		Blackboard->SetValueAsVector(HomePosKey, InPawn->GetActorLocation());

		if (!RunBehaviorTree(BTAsset))
		{
			CLog::Print("AIController couldn't run behavior tree!");
		}
	}
}