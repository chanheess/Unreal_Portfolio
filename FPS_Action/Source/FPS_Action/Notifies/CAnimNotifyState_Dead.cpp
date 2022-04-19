#include "CAnimNotifyState_Dead.h"
#include "../Utilities/Global.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "../Components/CActionComponent.h"

FString UCAnimNotifyState_Dead::GetNotifyName_Implementation() const
{
	return "Dead";
}

void UCAnimNotifyState_Dead::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	CheckNull(MeshComp);
	CheckNull(MeshComp->GetOwner());
	
	UCActionComponent* action = CHelpers::GetComponent<UCActionComponent>(MeshComp->GetOwner());
	CheckNull(action);
	
	action->OffAllCollision();
	
	ACharacter* character = Cast<ACharacter>(MeshComp->GetOwner());
	if(!!character)
		character->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void UCAnimNotifyState_Dead::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);

	CheckNull(MeshComp);
	CheckNull(MeshComp->GetOwner());

	MeshComp->GetOwner()->Destroy();
}

