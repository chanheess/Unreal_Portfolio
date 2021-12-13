#include "CPistol.h"
#include "../Utilities/Global.h"
#include "../CPlayer.h"
#include "Camera/CameraComponent.h"
#include "Camera/CameraShake.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMeshActor.h"
#include "Sound/SoundCue.h"

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

	AimSpringArm = CreateDefaultSubobject<USpringArmComponent>("AimSpringArm");
	AimSpringArm->SetupAttachment(Mesh);
	AimSpringArm->SetRelativeLocation(FVector(0, 0, 12));
	AimSpringArm->SetRelativeRotation(FRotator(0, 90, 0));
	AimSpringArm->TargetArmLength = 30.0f;
	AimSpringArm->bDoCollisionTest = false;
	AimSpringArm->bUsePawnControlRotation = true;
	AimSpringArm->SocketOffset = FVector(0, 0, 0);
	//AimSpringArm->bInheritPitch = false;
	//AimSpringArm->bInheritRoll = false;
	//AimSpringArm->bInheritYaw = false;

	AimCamera = CreateDefaultSubobject<UCameraComponent>("AimCamera");
	AimCamera->SetupAttachment(AimSpringArm);
	AimCamera->SetRelativeLocation(FVector(0));
	AimCamera->SetRelativeRotation(FRotator(0));
	AimCamera->bUsePawnControlRotation = true;
	
	CHelpers::GetAsset<USoundCue>(&FireSoundCue, "SoundCue'/Game/GunsAudioPack/Pistol_v1/Cue/Pistol_v1_wav_Cue.Pistol_v1_wav_Cue'");
}

void ACPistol::BeginPlay()
{
	Super::BeginPlay();
	
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HolsterSocket);
}

void ACPistol::Begin_Aim()
{
	//AimCamera->Activate();
	bAiming = true;
}

void ACPistol::End_Aim()
{
	//AimCamera->Deactivate();
	bAiming = false;
}

