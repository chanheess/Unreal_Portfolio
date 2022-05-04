#include "CAnimInstance_Zombie.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"

UCAnimInstance_Zombie::UCAnimInstance_Zombie()
{
	IsInAir = false;
	IsDead = false;


	static ConstructorHelpers::FObjectFinder<UAnimMontage> ATTACK_MONTAGE(TEXT("AnimMontage'/Game/Zombie/Montage/Zombie_Attack1_Montage.Zombie_Attack1_Montage'"));
	if (ATTACK_MONTAGE.Succeeded())
	{
		AttackMontage = ATTACK_MONTAGE.Object;
	}
}

void UCAnimInstance_Zombie::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	ACharacter* character = Cast<ACharacter>(TryGetPawnOwner());
	if (NULL == character) return;

}

void UCAnimInstance_Zombie::NativeUpdateAnimation(float DeltaSeconds)
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

void UCAnimInstance_Zombie::PlayAttackMontage()
{
	Montage_Play(AttackMontage, 1.0f);
}

void UCAnimInstance_Zombie::JumpToAttackMontageSection(int32 NewSection)
{
	Montage_IsPlaying(AttackMontage);
	Montage_JumpToSection(GetAttackMontageSectionName(NewSection), AttackMontage);
}

void UCAnimInstance_Zombie::AnimNotify_AttackHitCheck()
{
	OnAttackHitCheck.Broadcast();
}

void UCAnimInstance_Zombie::AnimNotify_NextAttackCheck()
{
	OnNextAttackCheck.Broadcast();
}

FName UCAnimInstance_Zombie::GetAttackMontageSectionName(int32 Section)
{
	FMath::IsWithinInclusive<int32>(Section, 1, 4);
	return FName(*FString::Printf(TEXT("Attack%d"), Section));
}
