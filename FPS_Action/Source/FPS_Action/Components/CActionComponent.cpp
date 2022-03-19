#include "CActionComponent.h"
#include "../Utilities/Global.h"
#include "../Actions/CActionData.h"
#include "../Actions/CAttachment.h"
#include "../Actions/CEquipment.h"
#include "../Actions/CDoAction.h"
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

void UCActionComponent::SetPistolMode()
{
	SetMode(EActionType::Pistol);
}

void UCActionComponent::SetRifleMode()
{
	SetMode(EActionType::Rifle);
}

void UCActionComponent::SetKnifeMode()
{
	SetMode(EActionType::Knife);
}

void UCActionComponent::DoAction()
{
	if (!!Datas[(int32)Type])
	{
		ACDoAction* action = Datas[(int32)Type]->GetDoAction();

		if (!!action)
			action->DoAction();
	}
}

void UCActionComponent::SetMode(EActionType InType)	//무기 장착
{
	//Todo 
	//equip일때 같은 무기일 때는 가만히, 아니면 unequip
	//action->GetCurrent()->GetEquipment()->Unequip();
	if (Type == InType) return;

	Datas[(int32)Type]->GetEquipment()->Unequip();
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