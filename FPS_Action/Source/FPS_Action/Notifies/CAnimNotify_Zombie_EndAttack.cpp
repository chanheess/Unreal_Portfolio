#include "CAnimNotify_Zombie_EndAttack.h"
#include "../Utilities/Global.h"
#include "../Characters/CEnemy_Zombie.h"

FString UCAnimNotify_Zombie_EndAttack::GetNotifyName_Implementation() const
{
	return "Zombie_EndAttack";
}

void UCAnimNotify_Zombie_EndAttack::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);
	CheckNull(MeshComp);
	CheckNull(MeshComp->GetOwner());

	//ACEnemy_Zombie* zombie = CHelpers::GetComponent<ACEnemy_Zombie>(MeshComp->GetOwner());
	//zombie->OnAttackMontageEnded(0, 0);

}
