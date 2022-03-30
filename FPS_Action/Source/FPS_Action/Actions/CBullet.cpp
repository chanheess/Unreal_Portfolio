#include "CBullet.h"
#include "../Utilities/Global.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Components/SphereComponent.h"

ACBullet::ACBullet()
{
	CHelpers::CreateComponent(this, &Mesh, "Mesh");
	CHelpers::CreateComponent(this, &CollisionComponent, "SphereComponent");
	CHelpers::CreateActorComponent(this, &Projectile, "Projectile");

	CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));
	CollisionComponent->OnComponentHit.AddDynamic(this, &ACBullet::OnHit);
	CollisionComponent->InitSphereRadius(5.0f);
	RootComponent = Mesh;

	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/Weapons/Meshs/SM_Sphere.SM_Sphere'");
	Mesh->SetStaticMesh(mesh);

	UMaterialInstanceConstant* material;
	CHelpers::GetAsset<UMaterialInstanceConstant>(&material, "MaterialInstanceConstant'/Game/Weapons/Materials/M_Bullet_Inst.M_Bullet_Inst'");
	Mesh->SetMaterial(0, material);
	Mesh->SetRelativeScale3D(FVector(1.0f, 0.025f, 0.025f));
	Mesh->SetCollisionProfileName("NoCollision");

	Projectile->InitialSpeed = 2e+4f;
	Projectile->MaxSpeed = 2e+4f;
	Projectile->ProjectileGravityScale = 0.0f;
	//Projectile->SetUpdatedComponent(CollisionComponent);
	Projectile->bRotationFollowsVelocity = true;
	Projectile->bShouldBounce = true;
}

void ACBullet::BeginPlay()
{
	Super::BeginPlay();

	SetLifeSpan(3.0f);
}

void ACBullet::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != this && OtherComponent->IsSimulatingPhysics())
	{
		OtherComponent->AddImpulseAtLocation(Projectile->Velocity * 100.0f, Hit.ImpactPoint);
	}
}

void ACBullet::FireInDirection(const FVector& ShootDirection)
{
	Projectile->Velocity = ShootDirection * Projectile->InitialSpeed;
}

