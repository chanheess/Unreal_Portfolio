#include "CAnimNotifyState_Unequip.h"
#include "../Utilities/Global.h"
#include "../Weapons/IWeapon.h"
#include "../Weapons/CWeapon.h"

FString UCAnimNotifyState_Unequip::GetNotifyName_Implementation() const
{
	return "UnEquip";
}

void UCAnimNotifyState_Unequip::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	CheckNull(MeshComp);

	IIWeapon* weapon = Cast<IIWeapon>(MeshComp->GetOwner());
	CheckNull(weapon);

	weapon->GetWeapon()->Unequipped_Montage();
}

void UCAnimNotifyState_Unequip::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	CheckNull(MeshComp);
}
