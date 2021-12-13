#include "CAnimInstance.h"
#include "Utilities/Global.h"
#include "GameFramework/Character.h"
#include "Weapons/CWeapon.h"
#include "Weapons/IWeapon.h"

void UCAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	OwnerCharacter = Cast<ACharacter>(TryGetPawnOwner());
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
