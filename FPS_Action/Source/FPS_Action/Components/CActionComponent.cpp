#include "CActionComponent.h"
#include "../Utilities/Global.h"
#include "../Actions/CActionData.h"
#include "../Actions/CAttachment.h"
#include "../Actions/CEquipment.h"
#include "GameFramework/Character.h"

UCActionComponent::UCActionComponent()
{

}

void UCActionComponent::BeginPlay()
{
	Super::BeginPlay();

	ACharacter* character = Cast<ACharacter>(GetOwner());

	for (int32 i = 0; i < (int32)EActionType::Max; i++)
	{
		if (!!Datas[i])
			Datas[i]->BeginPlay(character);
	}
}

void UCActionComponent::SetUnarmedMode()
{
	if (!!Datas[(int32)Type])
		Datas[(int32)Type]->GetEquipment()->Unequip();
	
	Datas[(int32)EActionType::Unarmed]->GetEquipment()->Equip();
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

void UCActionComponent::SetMode(EActionType InType)	//¹«±â ÀåÂø
{
	if (Type == InType)
	{
		SetUnarmedMode();

		return;
	}
	else if (IsUnarmedMode() == false)
	{
		Datas[(int32)Type]->GetEquipment()->Unequip();
	}

	Datas[(int32)InType]->GetEquipment()->Equip();
	ChangeType(InType);
}

void UCActionComponent::ChangeType(EActionType InNewType)
{
	EActionType prevType = Type;
	Type = InNewType;

	if (OnActionTypeChanged.IsBound())
		OnActionTypeChanged.Broadcast(prevType, InNewType);
}