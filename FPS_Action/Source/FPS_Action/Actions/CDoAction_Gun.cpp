#include "CDoAction_Gun.h"
#include "../Utilities/Global.h"
#include "GameFramework/Character.h"
#include "Engine/StaticMeshActor.h"
#include "../Components/CStateComponent.h"
#include "../Components/CStatusComponent.h"
#include "CAttachment.h"
#include "../Characters/ICharacter.h"
#include "../Actions/CBullet.h"
#include "../Components/CActionComponent.h"
#include "../Actions/CAttachment_Pistol.h"

ACDoAction_Gun::ACDoAction_Gun() : ACDoAction()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACDoAction_Gun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACDoAction_Gun::DoAction()
{
	Super::DoAction();
	CheckFalse(Datas.Num() > 0);

	CheckFalse(State->IsIdleMode());
	State->SetActionMode();
	
	if(Datas[0].CurrentWeapon == 2)
		Firing();

	OwnerCharacter->PlayAnimMontage(Datas[0].AnimMontage, Datas[0].PlayRatio, Datas[0].StartSection);

	CLog::Log("DoActionFire");
}

void ACDoAction_Gun::Begin_DoAction()
{
	Super::Begin_DoAction();

	Firing();
	CLog::Log("BeginFire");
}

void ACDoAction_Gun::End_DoAction()
{
	Super::End_DoAction();

	if (Status->IsReleased() == false && Datas[0].CurrentWeapon == 1)
	{
		OwnerCharacter->PlayAnimMontage(Datas[0].AnimMontage, Datas[0].PlayRatio, Datas[0].StartSection);
		return;
	}
	
	OwnerCharacter->StopAnimMontage(Datas[0].AnimMontage);
	State->SetIdleMode();
	Status->SetMove();

	CLog::Print("EndFire");
}

void ACDoAction_Gun::RestoreGlobalDilation()
{
	UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 1.0f);
}

void ACDoAction_Gun::Firing()
{
	Pitch = 0.0f;

	OnSoundCue();

	TSubclassOf<UCameraShake> shake = Datas[0].CameraShakeClass;
	if (!!shake)
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->PlayerCameraManager->PlayCameraShake(shake);

	IICharacter* character = Cast<IICharacter>(OwnerCharacter);
	FVector start, end, direction;

	UCActionComponent* action = CHelpers::GetComponent<UCActionComponent>(OwnerCharacter);
	CheckNull(action);

	ACAttachment_Pistol* weaponMesh = Cast<ACAttachment_Pistol>(action->GetCurrent()->GetAttachment());
	CheckNull(weaponMesh);
	CheckNull(weaponMesh->GetWeaponMesh());

	FVector muzzleLocation = weaponMesh->GetWeaponMesh()->GetSocketLocation("MuzzleSocket");
	//FRotator muzzleRotation = weaponMesh->GetWeaponMesh()->GetSocketRotation("MuzzleSocket");

	character->GetLocationAndDirection(start, end, direction);

	Pitch -= Datas[0].LimitPitch * GetWorld()->GetDeltaSeconds();
	if (Pitch > -Datas[0].LimitPitch)	//반동
		OwnerCharacter->AddControllerPitchInput(Pitch);

	UGameplayStatics::SpawnEmitterAttached(Datas[0].EjectParticle, weaponMesh->GetWeaponMesh(), "EjectSocket", FVector::ZeroVector, FRotator(0, 180, 0), EAttachLocation::KeepRelativeOffset);
	UGameplayStatics::SpawnEmitterAttached(Datas[0].FlashParticle, weaponMesh->GetWeaponMesh(), "MuzzleSocket", FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::KeepRelativeOffset);

	FCollisionQueryParams params;
	params.AddIgnoredActor(this);	//자기 자신 제거
	params.AddIgnoredActor(OwnerCharacter);

	FHitResult hitResult;
	if (GetWorld()->LineTraceSingleByChannel(hitResult, start, end, ECollisionChannel::ECC_Visibility, params))
	{
		FRotator decalRotator = UKismetMathLibrary::MakeRotFromX(hitResult.ImpactNormal);
		UGameplayStatics::SpawnDecalAtLocation(GetWorld(), (UMaterialInterface*)Datas[0].DecalMaterial, FVector(5), hitResult.Location, decalRotator, 10.0f);
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Datas[0].ImpactParticle, hitResult.Location, decalRotator, true);
	}

	TSubclassOf<class ACBullet> BulletClass = Datas[0].BulletClass;
	if (GetWorld()->LineTraceSingleByChannel(hitResult, start, end, ECollisionChannel::ECC_WorldDynamic, params))
	{
		CLog::Print(hitResult.GetActor()->GetName());

		FDamageEvent DamageEvent;
		hitResult.GetActor()->TakeDamage(Datas[0].Power, DamageEvent, OwnerCharacter->GetController(), this);
		if (!!BulletClass)
		{
			ACBullet* Bullet = GetWorld()->SpawnActor<ACBullet>(BulletClass, muzzleLocation, direction.Rotation());
			Bullet->SetProjectileVelocity(muzzleLocation, hitResult.Location, 1.0f);

			//DrawDebugLine(GetWorld(), muzzleLocation, hitResult.Location, FColor::Red, false, 3.0f);
		}
	}
	else
	{
		if (!!BulletClass)
		{
			ACBullet* Bullet = GetWorld()->SpawnActor<ACBullet>(BulletClass, muzzleLocation, direction.Rotation());
			Bullet->SetProjectileVelocity(muzzleLocation, end, 1.0f);
		}
	}

	//DrawDebugLine(GetWorld(), start, end, FColor::Green, false, 3.0f);
	

	//if (!!BulletClass)
	//	GetWorld()->SpawnActor<ACBullet>(BulletClass, muzzleLocation, direction.Rotation());
	
}