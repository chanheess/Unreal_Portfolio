#include "CEnemy_Zombie.h"
#include "CAnimInstance_Zombie.h"
#include "../Utilities/Global.h"
#include "Materials/MaterialInstanceConstant.h"
#include "../Components/CActionComponent.h"
#include "../Components/CMontagesComponent.h"
#include "../Components/CStatusComponent.h"

ACEnemy_Zombie::ACEnemy_Zombie() : ACEnemy()
{
	CHelpers::GetAsset<USkeletalMesh>(&mesh, "SkeletalMesh'/Game/Zombie/Mesh/SK_Zombie.SK_Zombie'");
	GetMesh()->SetSkeletalMesh(mesh);

	//CHelpers::GetClass<UAnimInstance>(&animInstance, "AnimBlueprint'/Game/Enemies/ABP_Enemy_Zombie1.ABP_Enemy_Zombie1_C'");
	//GetMesh()->SetAnimInstanceClass(animInstance);

	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimInstance(TEXT("AnimBlueprint'/Game/Enemies/ABP_Enemy_Zombie1.ABP_Enemy_Zombie1_C'"));
	if (AnimInstance.Succeeded())
		GetMesh()->SetAnimInstanceClass(AnimInstance.Class);
}

void ACEnemy_Zombie::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	animInstance = Cast<UCAnimInstance_Zombie>(GetMesh()->GetAnimInstance());
	if (NULL == animInstance) return;

	animInstance->OnMontageEnded.AddDynamic(this, &ACEnemy_Zombie::OnAttackMontageEnded);

	animInstance->OnNextAttackCheck.AddLambda([this]()->void {
		CanNextCombo = false;

		if (IsComboInputOn)
		{
			AttackStartComboState();
			animInstance->JumpToAttackMontageSection(CurrentCombo);
		}
		});

	animInstance->OnAttackHitCheck.AddUObject(this, &ACEnemy_Zombie::AttackCheck);

	//Status->OnHpIsZero.AddLambda([this]() -> void {
	//
	//	CLog::Print("OnHpIsZero");
	//	animInstance->SetDeadAnim();
	//	SetActorEnableCollision(false);
	//	});
}

void ACEnemy_Zombie::BeginPlay()
{
	UMaterialInstanceConstant* body;
	CHelpers::GetAssetDynamic<UMaterialInstanceConstant>(&body, "MaterialInstanceConstant'/Game/Zombie/Materials/MI_Zombie_1.MI_Zombie_1'");
	BodyMaterial = UMaterialInstanceDynamic::Create(body, this);
	GetMesh()->SetMaterial(0, BodyMaterial);

	Super::BeginPlay();
}

void ACEnemy_Zombie::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	CheckFalse(IsAttacking);
	//CheckFalse(CurrentCombo > 0);
	IsAttacking = false;
	//AttackEndComboState();	//¤¸¤©³²
	OnAttackEnd.Broadcast();
}

void ACEnemy_Zombie::AttackStartComboState()
{
	CanNextCombo = true;
	IsComboInputOn = false;
	FMath::IsWithinInclusive<int32>(CurrentCombo, 0, MaxCombo - 1);
	CurrentCombo = FMath::Clamp<int32>(CurrentCombo + 1, 1, MaxCombo);
}

void ACEnemy_Zombie::AttackEndComboState()
{
	IsComboInputOn = false;
	CanNextCombo = false;
	CurrentCombo = 0;
}

void ACEnemy_Zombie::AttackCheck()
{
	FHitResult HitResult;
	FCollisionQueryParams Params(NAME_None, false, this);
	bool bResult = GetWorld()->SweepSingleByChannel(
		HitResult,
		GetActorLocation(),
		GetActorLocation() + GetActorForwardVector() * AttackRange,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(AttackRadius),
		Params
	);

#if ENABLE_DRAW_DEBUG

	FVector TraceVec = GetActorForwardVector() * AttackRange;
	FVector Center = GetActorLocation() + TraceVec * 0.5f;
	float HalfHeight = AttackRange * 0.5f + AttackRadius;
	FQuat CapsuleRot = FRotationMatrix::MakeFromZ(TraceVec).ToQuat();
	FColor DrawColor = bResult ? FColor::Green : FColor::Red;
	float DebugLifeTime = 5.0f;

	DrawDebugCapsule(
		GetWorld(),
		Center,
		HalfHeight,
		AttackRadius,
		CapsuleRot,
		DrawColor,
		false,
		DebugLifeTime
	);
#endif

	if (bResult)
	{
		if (HitResult.Actor.IsValid())
		{
			CLog::Print(*HitResult.Actor->GetName(), 0, 1.0f);

			FDamageEvent DamageEvent;
			HitResult.Actor->TakeDamage(10, DamageEvent, GetController(), this);
		}
	}
}

void ACEnemy_Zombie::Attack()
{
	if (IsAttacking)
	{
		if (CanNextCombo)
		{
			IsComboInputOn = true;
		}
	}
	else
	{
		//AttackStartComboState();
		animInstance->PlayAttackMontage();
		//animInstance->JumpToAttackMontageSection(CurrentCombo);
		IsAttacking = true;
	}
}
