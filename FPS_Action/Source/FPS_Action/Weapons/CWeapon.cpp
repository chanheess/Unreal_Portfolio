#include "CWeapon.h"
#include "IWeapon.h"
#include "../Utilities/Global.h"
#include "../CPlayer.h"
#include "../CBullet.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMeshActor.h"
#include "Particles/PxParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "Sound/SoundCue.h"
#include "Materials/MaterialInstanceConstant.h"

ACWeapon::ACWeapon()
{
	PrimaryActorTick.bCanEverTick = true;

	CHelpers::CreateComponent<UStaticMeshComponent>(this, &Mesh, "Mesh");

	CHelpers::GetAsset<UAnimMontage>(&EquippedMontage, "AnimMontage'/Game/Soldier/Animations/Montages/WeaponEquipped.WeaponEquipped'");
	CHelpers::GetAsset<UAnimMontage>(&UnequippedMontage, "AnimMontage'/Game/Soldier/Animations/Montages/WeaponUnEquipped.WeaponUnEquipped'");
	CHelpers::GetAsset<UAnimMontage>(&FiringMontage, "AnimMontage'/Game/Soldier/Animations/Montages/PistolFiring.PistolFiring'");

	CHelpers::GetAsset<UParticleSystem>(&FlashParticle, "ParticleSystem'/Game/Weapons/Particles_Rifle/Particles/VFX_Muzzleflash.VFX_Muzzleflash'");
	CHelpers::GetAsset<UParticleSystem>(&EjectParticle, "ParticleSystem'/Game/Weapons/Particles_Rifle/Particles/VFX_Eject_bullet.VFX_Eject_bullet'");
	CHelpers::GetAsset<UParticleSystem>(&ImpactParticle, "ParticleSystem'/Game/Weapons/Particles_Rifle/Particles/VFX_Impact_Default.VFX_Impact_Default'");
	CHelpers::GetAsset<UMaterialInstanceConstant>(&DecalMaterial, "MaterialInstanceConstant'/Game/Weapons/Materials/M_Decal_Inst.M_Decal_Inst'");

	CHelpers::GetClass<ACBullet>(&BulletClass, "Blueprint'/Game/BluePrint/BP_CBullet.BP_CBullet_C'");
	CHelpers::GetClass<UCameraShake>(&CameraShakeClass, "Blueprint'/Game/BluePrint/BP_CameraShake.BP_CameraShake_C'");
}

void ACWeapon::BeginPlay()
{
	Super::BeginPlay();
}

void ACWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckFalse(bAiming);

	IIWeapon* weapon = Cast<IIWeapon>(OwnerCharacter);
	CheckNull(weapon);

	FVector start, end, direction;
	weapon->GetLocationAndDirection(start, end, direction);

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
					weapon->OnFocus();

					return;
				}
			}//if (!!meshComponent)
		}//if (!!staticMeshActor)
	}

	weapon->OffFocus();
}

void ACWeapon::Equip()
{
	CheckTrue(bEquipped);
	OwnerCharacter->PlayAnimMontage(EquippedMontage);
}

void ACWeapon::Unequip()
{
	CheckFalse(bEquipped);
	OwnerCharacter->PlayAnimMontage(UnequippedMontage);
}

void ACWeapon::Equipped_Montage()
{
	bEquipped = true;
	OwnerCharacter->bUseControllerRotationYaw = true;
	OwnerCharacter->GetCharacterMovement()->bOrientRotationToMovement = false;
	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HandSocket);
}

void ACWeapon::Unequipped_Montage()
{
	bEquipped = false;
	OwnerCharacter->bUseControllerRotationYaw = false;
	OwnerCharacter->GetCharacterMovement()->bOrientRotationToMovement = true;
	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HolsterSocket);
}

void ACWeapon::Begin_Fire()
{
	CheckFalse(bEquipped);
	CheckTrue(bFiring);
	OwnerCharacter->PlayAnimMontage(FiringMontage);
}

void ACWeapon::End_Fire()
{
	CheckFalse(bEquipped);
	CheckFalse(bFiring);
	bFiring = false;
}

void ACWeapon::Begin_Firing_Montage()
{
	bFiring = true;
	Pitch = 0.0f;

	Fired();
}

void ACWeapon::End_Firing_Montage()
{
	CheckFalse(bFiring);
	bFiring = false;
}

void ACWeapon::Fired()
{
	IIWeapon* weapon = Cast<IIWeapon>(OwnerCharacter);
	CheckNull(weapon);

	FVector muzzleLocation = Mesh->GetSocketLocation("MuzzleSocket");
	FRotator muzzleRotation = Mesh->GetSocketRotation("MuzzleSocket");
	FVector start, end, direction;

	start = Mesh->GetSocketLocation("MuzzleSocket");
	weapon->GetLocationAndDirection(start, end, direction);

	//DrawDebugLine(GetWorld(), start, end, FColor::Green, false, 3.0f);

	//카메라 진동	
	ACPlayer* player = Cast<ACPlayer>(OwnerCharacter);
	if (!!player)	//플레이어영역
	{
		APlayerController* controller = player->GetController<APlayerController>();
		controller->PlayerCameraManager->PlayCameraShake(CameraShakeClass);
	}

	UGameplayStatics::SpawnEmitterAttached(FlashParticle, Mesh, "MuzzleSocket", FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::KeepRelativeOffset);

	FVector ejectLocation = Mesh->GetSocketLocation("EjectSocket");
	UGameplayStatics::SpawnEmitterAttached(EjectParticle, Mesh, "EjectSocket", FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::KeepRelativeOffset);
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), FireSoundCue, muzzleLocation);

	if (!!BulletClass)
		GetWorld()->SpawnActor<ACBullet>(BulletClass, muzzleLocation, direction.Rotation());

	Pitch -= LimitPitch * GetWorld()->GetDeltaSeconds();
	if (Pitch > -LimitPitch)
		OwnerCharacter->AddControllerPitchInput(Pitch);

	//충돌 어떤 식으로 검출하는 건지 지정
	FCollisionQueryParams params;
	params.AddIgnoredActor(this);	//자기 자신 제거
	params.AddIgnoredActor(OwnerCharacter);

	FHitResult hitResult;
	if (GetWorld()->LineTraceSingleByChannel(hitResult, start, end, ECollisionChannel::ECC_Visibility, params))
	{
		FRotator decalRotator = UKismetMathLibrary::MakeRotFromX(hitResult.ImpactNormal);
		//FRotator decalRotator = hitResult.ImpactNormal.Rotation();

		UGameplayStatics::SpawnDecalAtLocation(GetWorld(), DecalMaterial, FVector(5), hitResult.Location, decalRotator, 10.0f);
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticle, hitResult.Location, decalRotator, true);
	}

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


