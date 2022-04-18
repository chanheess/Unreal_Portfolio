#include "CDoAction_Melee.h"
#include "../Utilities/Global.h"
#include "GameFramework/Character.h"
#include "../Components/CStateComponent.h"
#include "../Components/CStatusComponent.h"

void ACDoAction_Melee::DoAction()
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

	OnSoundCue();

	OwnerCharacter->PlayAnimMontage(Datas[0].AnimMontage, Datas[0].PlayRatio, Datas[0].StartSection);
	Datas[0].bCanMove ? Status->SetMove() : Status->SetStop();
}

void ACDoAction_Melee::Begin_DoAction()
{
	Super::Begin_DoAction();

	CheckFalse(bExist);
	bExist = false;

	OwnerCharacter->StopAnimMontage();

	ComboNum++;
	OnSoundCue(ComboNum);

	OwnerCharacter->PlayAnimMontage(Datas[ComboNum].AnimMontage, Datas[ComboNum].PlayRatio, Datas[ComboNum].StartSection);
	Datas[0].bCanMove ? Status->SetMove() : Status->SetStop();
}

void ACDoAction_Melee::End_DoAction()
{
	Super::End_DoAction();

	OwnerCharacter->StopAnimMontage(Datas[ComboNum].AnimMontage);

	ComboNum = 0;

	State->SetIdleMode();
	Status->SetMove();
}

void ACDoAction_Melee::OnAttachmentBeginOverlap(ACharacter* InAttacker, AActor* InAttackCauser, ACharacter* InOtherCharacter)
{
	Super::OnAttachmentBeginOverlap(InAttacker, InAttackCauser, InOtherCharacter);

	for (const ACharacter* other : HittedCharacter)
	{
		if (InOtherCharacter == other)
			return;
	}
	HittedCharacter.Add(InOtherCharacter);

	float hitStop = Datas[ComboNum].HitStop;
	if (FMath::IsNearlyZero(hitStop) == false)
	{
		UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 1e-3f);
		UKismetSystemLibrary::K2_SetTimer(this, "RestoreGlobalDilation", hitStop * 1e-3f, false);
	}

	UParticleSystem* hitEffect = Datas[ComboNum].ImpactParticle;
	if (!!hitEffect)
	{
		FTransform transform = Datas[ComboNum].EffectTransform;
		transform.AddToTranslation(InAttackCauser->GetActorLocation());
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), hitEffect, transform);
	}

	FDamageEvent e;
	InOtherCharacter->TakeDamage(Datas[ComboNum].Power, e, InAttacker->GetController(), InAttackCauser);

	if (!OwnerCharacter->IsPlayerControlled()) return;

	TSubclassOf<UCameraShake> shake = Datas[ComboNum].CameraShakeClass;
	if (!!shake)
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->PlayerCameraManager->PlayCameraShake(shake);
}

void ACDoAction_Melee::OnAttachmentEndOverlap(ACharacter* InAttacker, AActor* InAttackCauser, ACharacter* InOtherCharacter)
{
	Super::OnAttachmentEndOverlap(InAttacker, InAttackCauser, InOtherCharacter);

	HittedCharacter.Empty();
}

void ACDoAction_Melee::RestoreGlobalDilation()
{
	UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 1.0f);
}
