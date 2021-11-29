#include "CAnimNotifyState_Equip.h"
#include "../Utilities/Global.h"
#include "../Weapons/IWeapon.h"
#include "../Weapons/CWeapon.h"

FString UCAnimNotifyState_Equip::GetNotifyName_Implementation() const
{
	return "Equip";
}

void UCAnimNotifyState_Equip::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	CheckNull(MeshComp);

	IIWeapon* weapon = Cast<IIWeapon>(MeshComp->GetOwner());
	CheckNull(weapon);
	
	weapon->GetWeapon()->Equipped_Montage();
}

void UCAnimNotifyState_Equip::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	CheckNull(MeshComp);
}
