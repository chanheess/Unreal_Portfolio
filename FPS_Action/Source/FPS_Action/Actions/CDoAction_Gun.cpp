#include "CDoAction_Gun.h"
#include "../Utilities/Global.h"
#include "GameFramework/Character.h"
#include "Engine/StaticMeshActor.h"
#include "../Components/CStateComponent.h"
#include "../Components/CStatusComponent.h"
#include "CAttachment.h"
#include "../Characters/ICharacter.h"
#include "../Actions/CBullet.h"


/*
1. 무기메시를 가져와서 해당 총구있는 곳에 파티클 넣어준다.
2. 현재 캐릭터의 무기메시에서 카메라가 보고있는곳의 거리를 찍는다.

cactiondata에서 doaction에 setdatas에 현재 equipmentdata를 넘겨주어 장비정보를 받아온다.
*/
//Datas[(int32)Type]->GetEquipment()

void ACDoAction_Gun::DoAction()
{
	Super::DoAction();
	CheckFalse(Datas.Num() > 0);

	CheckFalse(State->IsIdleMode());
	State->SetActionMode();
	
	//총알이 있을 때만 발사되게 만들기
	OnSoundCue();
	Firing();

	OwnerCharacter->PlayAnimMontage(Datas[0].AnimMontage, Datas[0].PlayRatio, Datas[0].StartSection);
}

void ACDoAction_Gun::Begin_DoAction()
{
	Super::Begin_DoAction();

	OwnerCharacter->StopAnimMontage();
	OwnerCharacter->PlayAnimMontage(Datas[0].AnimMontage, Datas[0].PlayRatio, Datas[0].StartSection);
}

void ACDoAction_Gun::End_DoAction()
{
	Super::End_DoAction();

	OwnerCharacter->StopAnimMontage(Datas[0].AnimMontage);

	State->SetIdleMode();
	Status->SetMove();
}

void ACDoAction_Gun::RestoreGlobalDilation()
{
	UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 1.0f);
}

void ACDoAction_Gun::Firing()
{
	TSubclassOf<UCameraShake> shake = Datas[0].CameraShakeClass;
	if (!!shake)
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->PlayerCameraManager->PlayCameraShake(shake);

	Pitch = 0.0f;

	IICharacter* character = Cast<IICharacter>(OwnerCharacter);
	FVector start, end, direction;

	TArray<AActor*> attachmentActors;	//bp_attachpistol
	OwnerCharacter->GetAttachedActors(attachmentActors);

	FVector muzzleLocation = OwnerCharacter->GetMesh()->GetSocketLocation(attachmentActors[0]->GetAttachParentSocketName());
	start = muzzleLocation;

	//언젠가 muzzle소켓을 발견시에
	//FVector muzzleLocation = mesh->GetSocketLocation("MuzzleSocket");
	//FRotator muzzleRotation = mesh->GetSocketRotation("MuzzleSocket");
	//start = muzzleLocation;
	character->GetLocationAndDirection(start, end, direction);


	TSubclassOf<ACBullet> BulletClass = Datas[0].BulletClass;
	if (!!BulletClass)
		GetWorld()->SpawnActor<ACBullet>(BulletClass, muzzleLocation, direction.Rotation());
	if (Pitch > -LimitPitch)
		OwnerCharacter->AddControllerPitchInput(Pitch);

	UGameplayStatics::SpawnEmitterAttached(Datas[0].EjectParticle, OwnerCharacter->GetMesh(), attachmentActors[0]->GetAttachParentSocketName(), FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::KeepRelativeOffset);
	UGameplayStatics::SpawnEmitterAttached(Datas[0].FlashParticle, OwnerCharacter->GetMesh(), attachmentActors[0]->GetAttachParentSocketName(), FVector(-2, 10, 23), FRotator::ZeroRotator, EAttachLocation::KeepRelativeOffset);

	//충돌 어떤 식으로 검출하는 건지 지정
	FCollisionQueryParams params;
	params.AddIgnoredActor(this);	//자기 자신 제거
	params.AddIgnoredActor(OwnerCharacter);

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