#include "CDoAction_Rifle.h"
#include "../Utilities/Global.h"
#include "GameFramework/Character.h"
#include "Engine/StaticMeshActor.h"
#include "../Components/CStateComponent.h"
#include "../Components/CStatusComponent.h"
#include "CAttachment.h"
#include "../Characters/ICharacter.h"
#include "../Actions/CBullet.h"

/*
1. ����޽ø� �����ͼ� �ش� �ѱ��ִ� ���� ��ƼŬ �־��ش�.
2. ���� ĳ������ ����޽ÿ��� ī�޶� �����ִ°��� �Ÿ��� ��´�.

cactiondata���� doaction�� setdatas�� ���� equipmentdata�� �Ѱ��־� ��������� �޾ƿ´�.
*/
//Datas[(int32)Type]->GetEquipment()

void ACDoAction_Rifle::DoAction()
{
	Super::DoAction();
	CheckFalse(Datas.Num() > 0);

	if (bEnable == true)
	{
		bExist = true;
		bEnable = false;

		return;
	}

	CheckFalse(State->IsIdleMode());
	State->SetActionMode();

	//�Ѿ��� ���� ���� �߻�ǰ� �����
	
	OnSoundCue();
	Firing();
	if (BulletNum > 30) return;

	//bExist = false;
	//OnSoundCue();
	//GetWorld()->GetTimerManager().SetTimer(AutoFireTimer, this, &ACDoAction_Rifle::Firing, 0.1f, true, 0.0f);

	CLog::Print(BulletNum);

	OwnerCharacter->PlayAnimMontage(Datas[0].AnimMontage, Datas[0].PlayRatio, Datas[0].StartSection);
}

void ACDoAction_Rifle::Begin_DoAction()
{
	Super::Begin_DoAction();

	CheckFalse(bExist);
	bExist = false;

	//OwnerCharacter->StopAnimMontage();

	/*if (BulletNum > 30) return;

	BulletNum++;
	OnSoundCue();
	GetWorld()->GetTimerManager().SetTimer(AutoFireTimer, this, &ACDoAction_Rifle::Firing, 0.1f, true, 0.0f);*/


	OwnerCharacter->PlayAnimMontage(Datas[0].AnimMontage, Datas[0].PlayRatio, Datas[0].StartSection);
}

void ACDoAction_Rifle::End_DoAction()
{
	Super::End_DoAction();

	OwnerCharacter->StopAnimMontage(Datas[0].AnimMontage);

	State->SetIdleMode();
	Status->SetMove();

	GetWorld()->GetTimerManager().ClearTimer(AutoFireTimer);
}

void ACDoAction_Rifle::RestoreGlobalDilation()
{
	UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 1.0f);
}

void ACDoAction_Rifle::Firing()
{
	BulletNum++;

	TSubclassOf<UCameraShake> shake = Datas[0].CameraShakeClass;
	if (!!shake)
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->PlayerCameraManager->PlayCameraShake(shake);

	Pitch = 0.0f;

	IICharacter* character = Cast<IICharacter>(OwnerCharacter);
	FVector start, end, direction;

	TArray<AActor*> attachmentActors;	//bp_attach
	OwnerCharacter->GetAttachedActors(attachmentActors);

	FVector muzzleLocation = OwnerCharacter->GetMesh()->GetSocketLocation(attachmentActors[0]->GetAttachParentSocketName());
	start = muzzleLocation;

	character->GetLocationAndDirection(muzzleLocation, end, direction);

	TSubclassOf<ACBullet> BulletClass = Datas[0].BulletClass;
	if (!!BulletClass)
		GetWorld()->SpawnActor<ACBullet>(BulletClass, muzzleLocation, direction.Rotation());
	if (Pitch > -LimitPitch)
		OwnerCharacter->AddControllerPitchInput(Pitch);

	UGameplayStatics::SpawnEmitterAttached(Datas[0].EjectParticle, OwnerCharacter->GetMesh(), attachmentActors[0]->GetAttachParentSocketName(), FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::KeepRelativeOffset);
	UGameplayStatics::SpawnEmitterAttached(Datas[0].FlashParticle, OwnerCharacter->GetMesh(), attachmentActors[0]->GetAttachParentSocketName(), FVector(-2, 10, 23), FRotator::ZeroRotator, EAttachLocation::KeepRelativeOffset);

	//�浹 � ������ �����ϴ� ���� ����
	FCollisionQueryParams params;
	params.AddIgnoredActor(this);	//�ڱ� �ڽ� ����
	params.AddIgnoredActor(OwnerCharacter);

	DrawDebugLine(GetWorld(), start, end, FColor::Green, false, 3.0f);
	DrawDebugLine(GetWorld(), muzzleLocation, end, FColor::Red, false, 3.0f);

	FHitResult hitResult;
	if (GetWorld()->LineTraceSingleByChannel(hitResult, start, end, ECollisionChannel::ECC_Visibility, params))
	{
		FRotator decalRotator = UKismetMathLibrary::MakeRotFromX(hitResult.ImpactNormal);
		UGameplayStatics::SpawnDecalAtLocation(GetWorld(), (UMaterialInterface*)Datas[0].DecalMaterial, FVector(5), hitResult.Location, decalRotator, 10.0f);
	}

	if (GetWorld()->LineTraceSingleByChannel(hitResult, start, end, ECollisionChannel::ECC_WorldDynamic, params))
	{
		//CLog::Print(hitResult.GetActor()->GetName());
		FDamageEvent DamageEvent;
		hitResult.GetActor()->TakeDamage(Datas[0].Power, DamageEvent, OwnerCharacter->GetController(), this);

		FRotator decalRotator = UKismetMathLibrary::MakeRotFromX(hitResult.ImpactNormal);
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Datas[0].ImpactParticle, hitResult.Location, decalRotator, true);

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
				}
			}//if (!!meshComponent)
		}//if (!!staticMeshActor)
	}
}
