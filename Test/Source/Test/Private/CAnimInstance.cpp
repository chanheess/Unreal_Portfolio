#include "CAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"

UCAnimInstance::UCAnimInstance()
{
	IsInAir = false;
	IsDead = false;


	static ConstructorHelpers::FObjectFinder<UAnimMontage> ATTACK_MONTAGE(TEXT("AnimMontage'/Game/Character/Warriors/Montages/AttackMontage.AttackMontage'"));
	if (ATTACK_MONTAGE.Succeeded())
	{
		AttackMontage = ATTACK_MONTAGE.Object;
	}
}

void UCAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	ACharacter* character = Cast<ACharacter>(TryGetPawnOwner());
	if (NULL == character) return;

}

void UCAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	ACharacter* character = Cast<ACharacter>(TryGetPawnOwner());
	if (NULL == character) return;
	if (IsDead) return;

	Speed = character->GetVelocity().Size2D();
	Direction = CalculateDirection(character->GetVelocity(), character->GetControlRotation());
	Pitch = character->GetBaseAimRotation().Pitch;
	IsInAir = character->GetMovementComponent()->IsFalling();
}

void UCAnimInstance::PlayAttackMontage()
{
	Montage_Play(AttackMontage, 1.0f);
}

void UCAnimInstance::JumpToAttackMontageSection(int32 NewSection)
{
	Montage_IsPlaying(AttackMontage);
	Montage_JumpToSection(GetAttackMontageSectionName(NewSection), AttackMontage);
}

void UCAnimInstance::AnimNotify_AttackHitCheck()
{
	OnAttackHitCheck.Broadcast();
}

void UCAnimInstance::AnimNotify_NextAttackCheck()
{
	OnNextAttackCheck.Broadcast();
}

FName UCAnimInstance::GetAttackMontageSectionName(int32 Section)
{
	FMath::IsWithinInclusive<int32>(Section, 1, 4);
	return FName(*FString::Printf(TEXT("Attack%d"), Section));
}