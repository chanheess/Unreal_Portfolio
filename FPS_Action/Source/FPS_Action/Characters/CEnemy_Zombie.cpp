#include "CEnemy_Zombie.h"
#include "../Utilities/Global.h"
#include "Materials/MaterialInstanceConstant.h"

ACEnemy_Zombie::ACEnemy_Zombie() : ACEnemy()
{
	CHelpers::GetAsset<USkeletalMesh>(&mesh, "SkeletalMesh'/Game/Zombie/Mesh/SK_Zombie.SK_Zombie'");
	GetMesh()->SetSkeletalMesh(mesh);

	CHelpers::GetClass<UAnimInstance>(&animInstance, "AnimBlueprint'/Game/Enemies/ABP_Enemy_Zombie.ABP_Enemy_Zombie_C'");
	GetMesh()->SetAnimInstanceClass(animInstance);
}

void ACEnemy_Zombie::BeginPlay()
{
	UMaterialInstanceConstant* body;
	CHelpers::GetAssetDynamic<UMaterialInstanceConstant>(&body, "MaterialInstanceConstant'/Game/Zombie/Materials/MI_Zombie_1.MI_Zombie_1'");
	BodyMaterial = UMaterialInstanceDynamic::Create(body, this);
	GetMesh()->SetMaterial(0, BodyMaterial);

	Super::BeginPlay();
}
