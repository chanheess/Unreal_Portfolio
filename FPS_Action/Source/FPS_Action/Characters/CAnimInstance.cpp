#include "CAnimInstance.h"
#include "GameFramework/Character.h"
#include "../Utilities/Global.h"
#include "../Weapons/CWeapon.h"
#include "../Weapons/IWeapon.h"

void UCAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	OwnerCharacter = Cast<ACharacter>(TryGetPawnOwner());
	CheckNull(OwnerCharacter);

	UCActionComponent* action = CHelpers::GetComponent<UCActionComponent>(OwnerCharacter);
	CheckNull(action);

	action->OnActionTypeChanged.AddDynamic(this, &UCAnimInstance::OnActionTypeChanged);
}


void UCAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	CheckNull(OwnerCharacter);

	Speed = OwnerCharacter->GetVelocity().Size2D();
	Direction = CalculateDirection(OwnerCharacter->GetVelocity(), OwnerCharacter->GetControlRotation());
	Pitch = OwnerCharacter->GetBaseAimRotation().Pitch;

	IIWeapon* weapon = Cast<IIWeapon>(OwnerCharacter);
	if (!!weapon)
	{
		bEquipped = weapon->GetWeapon()->GetEquipped();
		bAiming = weapon->GetWeapon()->GetAiming();
		bRunning = weapon->GetRunning();
		bFiring = weapon->GetWeapon()->GetFiring();
	}

}

void UCAnimInstance::OnActionTypeChanged(EActionType InPrevType, EActionType InNewType)
{
	ActionType = InNewType;
}
