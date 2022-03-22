#include "CDoAction_Gun.h"
#include "../Utilities/Global.h"
#include "GameFramework/Character.h"
#include "../Components/CStateComponent.h"
#include "../Components/CStatusComponent.h"
#include "CAttachment.h"
#include "../Characters/CPlayer.h"
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

void ACDoAction_Gun::OnAttachmentBeginOverlap(ACharacter* InAttacker, AActor* InAttackCauser, ACharacter* InOtherCharacter)
{
	Super::OnAttachmentBeginOverlap(InAttacker, InAttackCauser, InOtherCharacter);

	for (const ACharacter* other : HittedCharacter)
	{
		if (InOtherCharacter == other)
			return;
	}
	HittedCharacter.Add(InOtherCharacter);

	float hitStop = Datas[0].HitStop;
	if (FMath::IsNearlyZero(hitStop) == false)
	{
		UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 1e-3f);
		UKismetSystemLibrary::K2_SetTimer(this, "RestoreGlobalDilation", hitStop * 1e-3f, false);
	}

	UParticleSystem* hitEffect = Datas[0].ImpactParticle;
	if (!!hitEffect)
	{
		FTransform transform = Datas[0].EffectTransform;
		transform.AddToTranslation(InAttackCauser->GetActorLocation());
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), hitEffect, transform);
	}

	FDamageEvent e;
	InOtherCharacter->TakeDamage(Datas[0].Power, e, InAttacker->GetController(), InAttackCauser);
}

void ACDoAction_Gun::OnAttachmentEndOverlap(ACharacter* InAttacker, AActor* InAttackCauser, ACharacter* InOtherCharacter)
{
	Super::OnAttachmentEndOverlap(InAttacker, InAttackCauser, InOtherCharacter);

	HittedCharacter.Empty();
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

	ACPlayer* player = Cast<ACPlayer>(OwnerCharacter);

	Pitch = 0.0f;

	FVector start, end, direction;
	player->GetLocationAndDirection(start, end, direction);

	Datas[0].Get
	//player->

	TSubclassOf<ACBullet> BulletClass = Datas[0].BulletClass;
	if (!!BulletClass)
	{
		GetWorld()->SpawnActor<ACBullet>(BulletClass, start, direction.Rotation());
		CLog::Print("BulletClassIsTrue");
	}

	if (Pitch > -LimitPitch)
		OwnerCharacter->AddControllerPitchInput(Pitch);
}