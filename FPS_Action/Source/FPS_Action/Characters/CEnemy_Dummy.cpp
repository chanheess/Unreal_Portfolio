#include "CEnemy_Dummy.h"
#include "../Utilities/Global.h"
#include "Materials/MaterialInstanceConstant.h"

ACEnemy_Dummy::ACEnemy_Dummy() : ACEnemy()
{
	CHelpers::GetAsset<USkeletalMesh>(&mesh, "SkeletalMesh'/Game/Soldier/Mesh/Soldier/SK_Soldier.SK_Soldier'");
	GetMesh()->SetSkeletalMesh(mesh);

	CHelpers::GetClass<UAnimInstance>(&animInstance, "AnimBlueprint'/Game/Enemies/ABP_Enemy.ABP_Enemy_C'");
	GetMesh()->SetAnimInstanceClass(animInstance);
}

void ACEnemy_Dummy::BeginPlay()
{
	UMaterialInstanceConstant* body;
	CHelpers::GetAssetDynamic<UMaterialInstanceConstant>(&body, "MaterialInstanceConstant'/Game/Soldier/Materials/Soldier/MI_Soldier_3.MI_Soldier_3'");
	BodyMaterial = UMaterialInstanceDynamic::Create(body, this);
	GetMesh()->SetMaterial(0, BodyMaterial);

	Super::BeginPlay();
}
