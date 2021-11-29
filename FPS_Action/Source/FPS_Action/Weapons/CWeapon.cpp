#include "CWeapon.h"
#include "IWeapon.h"
#include "../Utilities/Global.h"
#include "../CPlayer.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMeshActor.h"

ACWeapon::ACWeapon()
{
	PrimaryActorTick.bCanEverTick = true;

	CHelpers::CreateComponent<UStaticMeshComponent>(this, &Mesh, "Mesh");

	CHelpers::GetAsset<UAnimMontage>(&EquippedMontage, "AnimMontage'/Game/Soldier/Animations/Montages/WeaponEquipped.WeaponEquipped'");
	CHelpers::GetAsset<UAnimMontage>(&UnequippedMontage, "AnimMontage'/Game/Soldier/Animations/Montages/WeaponUnEquipped.WeaponUnEquipped'");
}

void ACWeapon::BeginPlay()
{
	Super::BeginPlay();
}

void ACWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckFalse(bAiming);
	CLog::Print("WeaponTick", 0, 2, FColor::Red);

	IIWeapon* weapon = Cast<IIWeapon>(OwnerCharacter);
	CheckNull(weapon);

	FVector start, end, direction;
	weapon->GetLocationAndDirection(start, end, direction);

	DrawDebugLine(GetWorld(), start, end, FColor::Green, false, 3.0f);

	//어떤 식으로 검출하는 건지 지정
	FCollisionQueryParams params;
	params.AddIgnoredActor(this);	//자기 자신 제거
	params.AddIgnoredActor(OwnerCharacter);

	FHitResult hitResult;
	if (GetWorld()->LineTraceSingleByChannel(hitResult, start, end, ECollisionChannel::ECC_WorldDynamic, params))
	{
		AStaticMeshActor* staticMeshActor = Cast<AStaticMeshActor>(hitResult.GetActor());
		if (!!staticMeshActor)
		{
			UStaticMeshComponent* meshComponent = Cast<UStaticMeshComponent>(staticMeshActor->GetRootComponent());
			if (!!meshComponent)
			{
				if (meshComponent->BodyInstance.bSimulatePhysics)
				{
					weapon->OnFocus();

					return;
				}
			}//if (!!meshComponent)
		}//if (!!staticMeshActor)
	}

	weapon->OffFocus();
}

void ACWeapon::Equip()
{
	CheckTrue(bEquipped);
	OwnerCharacter->PlayAnimMontage(EquippedMontage);
}

void ACWeapon::Unequip()
{
	CheckFalse(bEquipped);
	OwnerCharacter->PlayAnimMontage(UnequippedMontage);
}

void ACWeapon::Equipped_Montage()
{
	bEquipped = true;
	OwnerCharacter->bUseControllerRotationYaw = true;
	OwnerCharacter->GetCharacterMovement()->bOrientRotationToMovement = false;
	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HandSocket);
}

void ACWeapon::Unequipped_Montage()
{
	bEquipped = false;
	OwnerCharacter->bUseControllerRotationYaw = false;
	OwnerCharacter->GetCharacterMovement()->bOrientRotationToMovement = true;
	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HolsterSocket);
}


