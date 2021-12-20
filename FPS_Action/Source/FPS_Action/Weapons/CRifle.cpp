#include "CRifle.h"
#include "../Utilities/Global.h"
#include "../CPlayer.h"
#include "Camera/CameraComponent.h"
#include "Camera/CameraShake.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMeshActor.h"
#include "Sound/SoundCue.h"

ACRifle* ACRifle::Spawn(UWorld* InWorld, ACharacter* InOwner)
{
	FActorSpawnParameters params;
	params.Owner = InOwner;

	//스폰할 파라미터를 지정해서 사용할 수 있게됨
	return InWorld->SpawnActor<ACRifle>(params);
}

ACRifle::ACRifle() : ACWeapon()
{
	PrimaryActorTick.bCanEverTick = true;

	LimitPitch = 0.25f;
	HolsterSocket = "Rifle_BackSocket";
	HandSocket = "SKT_Rifle";

	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/Soldier/Mesh/Weapon/SM_Rifle.SM_Rifle'");
	Mesh->SetStaticMesh(mesh);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	CHelpers::GetAsset<USoundCue>(&FireSoundCue, "SoundCue'/Game/GunsAudioPack/ShotGun_v1/Cue/ShotGun_v1_variation_01_wav_Cue.ShotGun_v1_variation_01_wav_Cue'");
}

void ACRifle::BeginPlay()
{
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HolsterSocket);
}

void ACRifle::Begin_Aim()
{
	bAiming = true;
}

void ACRifle::End_Aim()
{
	bAiming = false;
}


