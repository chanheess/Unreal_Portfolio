#include "CBullet.h"
#include "../Utilities/Global.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Components/SphereComponent.h"

ACBullet::ACBullet()
{
	CHelpers::CreateComponent(this, &Mesh, "Mesh");
	CHelpers::CreateActorComponent(this, &Projectile, "Projectile");

	RootComponent = Mesh;

	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/Weapons/Meshs/SM_Sphere.SM_Sphere'");
	Mesh->SetStaticMesh(mesh);

	UMaterialInstanceConstant* material;
	CHelpers::GetAsset<UMaterialInstanceConstant>(&material, "MaterialInstanceConstant'/Game/Weapons/Materials/M_Bullet_Inst.M_Bullet_Inst'");
	Mesh->SetMaterial(0, material);
	Mesh->SetRelativeScale3D(FVector(1.0f, 0.025f, 0.025f));
	Mesh->SetCollisionProfileName("NoCollision");

	Projectile->InitialSpeed = 2000;
	Projectile->MaxSpeed = 5000;
	//Projectile->InitialSpeed = 2e+4f;
	//Projectile->MaxSpeed = 2e+4f;
	Projectile->ProjectileGravityScale = 0.0f;
	Projectile->bRotationFollowsVelocity = true;
	Projectile->bShouldBounce = true;
}

void ACBullet::BeginPlay()
{
	Super::BeginPlay();

	SetLifeSpan(3.0f);
}

void ACBullet::FireInDirection(const FVector& ShootDirection)
{
	Projectile->Velocity = ShootDirection * Projectile->InitialSpeed;
}

