#include "CActionComponent.h"
#include "../Utilities/Global.h"

UCActionComponent::UCActionComponent()
{

}

void UCActionComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UCActionComponent::SetUnarmedMode()
{
	ChangeType(EActionType::Unarmed);
}

void UCActionComponent::SetPistolMode()
{
	SetMode(EActionType::Pistol);
}

void UCActionComponent::SetRifleMode()
{
	SetMode(EActionType::Rifle);
}

void UCActionComponent::SetMode(EActionType InType)
{
	if (Type == InType)
	{
		SetUnarmedMode();

		return;
	}

	ChangeType(InType);
}

void UCActionComponent::ChangeType(EActionType InNewType)
{
	EActionType prevType = Type;
	Type = InNewType;

	if (OnActionTypeChanged.IsBound())
		OnActionTypeChanged.Broadcast(prevType, InNewType);

}