#include "CAnimNotifyState_Firing.h"
#include "../Utilities/Global.h"
//#include "../Weapons/IWeapon.h"
//#include "../Weapons/CWeapon.h"

FString UCAnimNotifyState_Firing::GetNotifyName_Implementation() const
{
	return "Firing";
}

void UCAnimNotifyState_Firing::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	CheckNull(MeshComp);

	//IIWeapon* weapon = Cast<IIWeapon>(MeshComp->GetOwner());
	//CheckNull(weapon);
	//
	//weapon->GetWeapon()->Begin_Firing_Montage();
}

void UCAnimNotifyState_Firing::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	CheckNull(MeshComp);

	//IIWeapon* weapon = Cast<IIWeapon>(MeshComp->GetOwner());
	//CheckNull(weapon);
	//
	//weapon->GetWeapon()->End_Firing_Montage();
}

