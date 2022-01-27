#include "CMontagesComponent.h"
#include "../Utilities/Global.h"
#include "GameFramework/Character.h"

UCMontagesComponent::UCMontagesComponent()
{

}

void UCMontagesComponent::BeginPlay()
{
	Super::BeginPlay();

	CheckNull(DataTable);

	TArray<FMontageData*> datas;
	DataTable->GetAllRows<FMontageData>("", datas);

	for (int32 i = 0; i < (int32)EStateType::Max; i++)
	{
		for (FMontageData* data : datas)
		{
			if ((EStateType)i == data->Type)
			{
				Datas[i] = data;

				continue;
			}
		}
	}

	/*for (const FMontageData* data : Datas)
	{
		if (!!data)
			CLog::Log(data->AnimMontage->GetPathName());
	}*/
}

void UCMontagesComponent::PlayFire()
{
	PlayAnimMontage(EStateType::Fire);
}

void UCMontagesComponent::PlayAim()
{
	PlayAnimMontage(EStateType::Aim);
}

void UCMontagesComponent::PlayHitted()
{
	PlayAnimMontage(EStateType::Hitted);
}

void UCMontagesComponent::PlayAnimMontage(EStateType InStateType)
{
	ACharacter* character = Cast<ACharacter>(GetOwner());
	
	const FMontageData* data = Datas[(int32)InStateType];
	if (!!data)
	{
		if (!!data->AnimMontage)
			character->PlayAnimMontage(data->AnimMontage, data->PlayRatio, data->StartSection);
	}
}