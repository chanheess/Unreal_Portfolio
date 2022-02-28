#include "CDoAction_Gun.h"
#include "../Utilities/Global.h"
#include "GameFramework/Character.h"
#include "../Components/CStateComponent.h"
#include "../Components/CStatusComponent.h"
#include "CAttachment.h"


/*
1. ����޽ø� �����ͼ� �ش� �ѱ��ִ� ���� ��ƼŬ �־��ش�.
2. ���� ĳ������ ����޽ÿ��� ī�޶� �����ִ°��� �Ÿ��� ��´�.


*/


void ACDoAction_Gun::DoAction()
{
	Super::DoAction();
	CheckFalse(Datas.Num() > 0);

	CheckFalse(State->IsIdleMode());
	State->SetActionMode();

	//�Ѿ��� ���� ���� �߻�ǰ� �����
	OnSoundCue();

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

	TSubclassOf<UCameraShake> shake = Datas[0].CameraShakeClass;
	if (!!shake)
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->PlayerCameraManager->PlayCameraShake(shake);

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
