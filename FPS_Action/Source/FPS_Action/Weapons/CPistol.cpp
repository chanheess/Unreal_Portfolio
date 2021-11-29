#include "CPistol.h"
#include "../Utilities/Global.h"
#include "../CPlayer.h"
#include "Camera/CameraComponent.h"
#include "Camera/CameraShake.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMeshActor.h"
#include "GameFramework/Character.h"
//#include "Particles/PxParticleSystem.h"
//#include "Sound/SoundCue.h"
//#include "Materials/MaterialInstanceConstant.h"

ACPistol* ACPistol::Spawn(UWorld* InWorld, ACharacter* InOwner)
{
	FActorSpawnParameters params;
	params.Owner = InOwner;

	//스폰할 파라미터를 지정해서 사용할 수 있게됨
	return InWorld->SpawnActor<ACPistol>(params);
}

ACPistol::ACPistol() : ACWeapon()
{
	PrimaryActorTick.bCanEverTick = true;

	LimitPitch = 0.25f;
	HolsterSocket = "Pistol_HolsterSocket";
	HandSocket = "SKT_Pistol";

	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/Soldier/Mesh/Weapon/SM_Pistol.SM_Pistol'");
	Mesh->SetStaticMesh(mesh);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	CHelpers::GetClass<UCameraShake>(&CameraShakeClass, "Blueprint'/Game/BluePrint/BP_CameraShake.BP_CameraShake_C'");
}

void ACPistol::BeginPlay()
{
	Super::BeginPlay();
	
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HolsterSocket);
}

void ACPistol::Begin_Aim()
{
	bAiming = true;
}

void ACPistol::End_Aim()
{
	bAiming = false;
}

void ACPistol::Begin_Fire()
{
	CheckFalse(bEquipped);
	CheckFalse(bAiming);
	CheckTrue(bFiring);

	bFiring = true;
	Pitch = 0.0f;

	Firing();
}

void ACPistol::End_Fire()
{
	bFiring = false;
}

void ACPistol::Firing()
{
	IIWeapon* weapon = Cast<IIWeapon>(OwnerCharacter);
	CheckNull(weapon);

	FVector start, end, direction;
	weapon->GetLocationAndDirection(start, end, direction);

	//카메라 진동	
	ACPlayer* player = Cast<ACPlayer>(OwnerCharacter);
	if (!!player)	//플레이어영역
	{
		APlayerController* controller = player->GetController<APlayerController>();
		controller->PlayerCameraManager->PlayCameraShake(CameraShakeClass);
	}

	Pitch -= LimitPitch * GetWorld()->GetDeltaSeconds();
	if (Pitch > -LimitPitch)
		OwnerCharacter->AddControllerPitchInput(Pitch);

	//어떤 식으로 검출하는 건지 지정
	FCollisionQueryParams params;
	params.AddIgnoredActor(this);	//자기 자신 제거
	params.AddIgnoredActor(OwnerCharacter);

	FHitResult hitResult;

	if (GetWorld()->LineTraceSingleByChannel(hitResult, start, end, ECollisionChannel::ECC_WorldDynamic, params))
	{
		AStaticMeshActor* staticMeshActor = Cast<AStaticMeshActor>(hitResult.GetActor());
		if (!!staticMeshActor)
		{
			UStaticMeshComponent* meshComponent = Cast<UStaticMeshComponent>(staticMeshActor->GetRootComponent());
			if (!!meshComponent)
			{
				if (meshComponent->BodyInstance.bSimulatePhysics)
				{
					direction = staticMeshActor->GetActorLocation() - OwnerCharacter->GetActorLocation();
					direction.Normalize();

					meshComponent->AddImpulseAtLocation(direction * meshComponent->GetMass() * 100, OwnerCharacter->GetActorLocation());

					return;
				}
			}//if (!!meshComponent)
		}//if (!!staticMeshActor)
	}
}

