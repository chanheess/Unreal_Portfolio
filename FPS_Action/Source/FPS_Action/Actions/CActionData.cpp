#include "CActionData.h"
#include "../Utilities/Global.h"
#include "CAttachment.h"
#include "CEquipment.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"

void UCActionData::BeginPlay(ACharacter* InOwnerCharacter)
{
	FTransform transform;

	if (!!AttachmentClass)
	{
		Attachment = InOwnerCharacter->GetWorld()->SpawnActorDeferred<ACAttachment>(AttachmentClass, transform, InOwnerCharacter);
		Attachment->SetActorLabel(GetLabelName(InOwnerCharacter, "Attachment"));
		UGameplayStatics::FinishSpawningActor(Attachment, transform);
	}

	if (!!EquipmentClass)	//���� �������� �� ����
	{
		Equipment = InOwnerCharacter->GetWorld()->SpawnActorDeferred<ACEquipment>(EquipmentClass, transform, InOwnerCharacter);
		Equipment->AttachToComponent(InOwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true));
		Equipment->SetActorLabel(GetLabelName(InOwnerCharacter, "Equipment"));
		Equipment->SetData(EquipmentData);
		Equipment->SetColor(EquipmentColor);
		UGameplayStatics::FinishSpawningActor(Equipment, transform);
	}
}

FString UCActionData::GetLabelName(class ACharacter* InOwnerCharacter, FString InName)
{
	FString name;
	name.Append(InOwnerCharacter->GetActorLabel());
	name.Append("_");
	name.Append(InName);
	name.Append("_");
	name.Append(GetName().Replace(L"DA_", L""));

	return name;
}
