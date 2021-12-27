#include "CStateComponent.h"
#include "../Utilities/Global.h"

UCStateComponent::UCStateComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UCStateComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UCStateComponent::SetIdleMode()
{
	ChangeType(EStateType::Idle);
}

void UCStateComponent::SetRollMode()
{
	ChangeType(EStateType::Roll);
}

void UCStateComponent::SetBackstepMode()
{
	ChangeType(EStateType::Backstep);
}


void UCStateComponent::ChangeType(EStateType InNewType)
{
	EStateType prevType = Type;
	Type = InNewType;

	if (OnStateTypeChanged.IsBound())
		OnStateTypeChanged.Broadcast(prevType, InNewType);
}