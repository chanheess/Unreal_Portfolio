#include "CPlayer.h"
#include "CAnimInstance.h"
#include "../Utilities/Global.h"
#include "../Weapons/CWeapon.h"
#include "../Weapons/CPistol.h"
#include "../Weapons/CRifle.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "../Components/CStatusComponent.h"
#include "../Components/COptionComponent.h"
#include "../Widgets/CUserWidget_CrossHair.h"

ACPlayer::ACPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	CHelpers::CreateActorComponent(this, &Status, "Status");
	CHelpers::CreateActorComponent(this, &Option, "Option");

	CHelpers::CreateComponent(this, &SpringArm, "SpringArm", GetMesh());
	SpringArm->SetRelativeLocation(FVector(0, 0, 60));
	SpringArm->SetRelativeRotation(FRotator(0, 90, 0));
	SpringArm->SocketOffset = FVector(0, 20, 20);
	SpringArm->TargetArmLength = 200.0f; 
	SpringArm->bDoCollisionTest = false;
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bEnableCameraLag = true;

	CHelpers::CreateComponent(this, &Camera, "Camera", SpringArm);
	Camera->SetRelativeLocation(FVector(10, 0, -5));
	Camera->SetRelativeRotation(FRotator(-20.0f, 0, 0));
	Camera->bUsePawnControlRotation = true;

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0, 720, 0);
	GetCharacterMovement()->MaxWalkSpeed = Status->GetRunSpeed();

	USkeletalMesh* mesh;
	CHelpers::GetAsset<USkeletalMesh>(&mesh, "SkeletalMesh'/Game/Soldier/Mesh/Soldier/SK_Soldier.SK_Soldier'");
	GetMesh()->SetSkeletalMesh(mesh);
	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	TSubclassOf<UAnimInstance> animInstance;
	CHelpers::GetClass<UAnimInstance>(&animInstance, "AnimBlueprint'/Game/Soldier/Animations/Soldier/ABP_Player.ABP_Player_C'");
	GetMesh()->SetAnimInstanceClass(animInstance);

	CHelpers::GetClass<UCUserWidget_CrossHair>(&CrossHairClass, "WidgetBlueprint'/Game/Widgets/WB_CrossHair.WB_Crosshair_C'");
}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();

	Crosshair = CreateWidget<UCUserWidget_CrossHair, APlayerController>(GetController<APlayerController>(), CrossHairClass);
	Crosshair->AddToViewport();
	Crosshair->SetVisibility(ESlateVisibility::Hidden);

	Weapon = ACWeapon::Spawn(GetWorld(), this);
	Pistol = ACPistol::Spawn(GetWorld(), this);
	Rifle = ACRifle::Spawn(GetWorld(), this);
}

void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACPlayer::OnMoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPlayer::OnMoveRight);
	PlayerInputComponent->BindAxis("HorizontalLook", this, &ACPlayer::OnHorizontalLook);
	PlayerInputComponent->BindAxis("VerticalLook", this, &ACPlayer::OnVerticalLook);

	PlayerInputComponent->BindAction("Run", EInputEvent::IE_Pressed, this, &ACPlayer::OnRun);
	PlayerInputComponent->BindAction("Run", EInputEvent::IE_Released, this, &ACPlayer::OffRun);

	PlayerInputComponent->BindAction("Pistol", EInputEvent::IE_Pressed, this, &ACPlayer::OnPistol);
	PlayerInputComponent->BindAction("Rifle", EInputEvent::IE_Pressed, this, &ACPlayer::OnRifle);

	PlayerInputComponent->BindAction("Aim", EInputEvent::IE_Pressed, this, &ACPlayer::OnAim);
	PlayerInputComponent->BindAction("Aim", EInputEvent::IE_Released, this, &ACPlayer::OffAim);

	PlayerInputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &ACPlayer::OnFire);
	PlayerInputComponent->BindAction("Fire", EInputEvent::IE_Released, this, &ACPlayer::OffFire);
}

void ACPlayer::OnMoveForward(float InAxis)
{
	CheckFalse(Status->IsCanMove());

	FRotator rotator = FRotator(0, GetControlRotation().Yaw, 0);
	FVector direction = FQuat(rotator).GetForwardVector().GetSafeNormal2D();

	AddMovementInput(direction, InAxis);
}

void ACPlayer::OnMoveRight(float InAxis)
{
	CheckFalse(Status->IsCanMove());

	FRotator rotator = FRotator(0, GetControlRotation().Yaw, 0);
	FVector direction = FQuat(rotator).GetRightVector().GetSafeNormal2D();

	AddMovementInput(direction, InAxis);
}

void ACPlayer::OnHorizontalLook(float InAxis)
{
	float rate = Option->GetHorizontalLookRate();
	AddControllerYawInput(InAxis * rate * GetWorld()->GetDeltaSeconds());
}

void ACPlayer::OnVerticalLook(float InAxis)
{
	float rate = Option->GetVerticalLookRate();
	AddControllerPitchInput(InAxis * rate * GetWorld()->GetDeltaSeconds());
}

void ACPlayer::OnRun()
{
	CheckTrue(Weapon->GetAiming());
	bRunning = true;

	GetCharacterMovement()->MaxWalkSpeed = Weapon->GetMaxRunSpeed();

	CheckFalse(Weapon->GetEquipped());
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
}

void ACPlayer::OffRun()
{
	GetCharacterMovement()->MaxWalkSpeed = 400.0f;
	bRunning = false;

	CheckFalse(Weapon->GetEquipped());
	bUseControllerRotationYaw = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;
}

void ACPlayer::OnWeapon(ACWeapon& weapons)
{
	CheckTrue(bRunning);

	if (Weapon->GetEquipped())
	{
		CheckTrue(Weapon->GetAiming());
		Crosshair->SetVisibility(ESlateVisibility::Hidden);
		Weapon->Unequip();

		return;
	}

	Weapon = &weapons;
	Weapon->Equip();
	Crosshair->SetVisibility(ESlateVisibility::Visible);
}

void ACPlayer::OnPistol()
{
	CheckNull(Pistol);
	OnWeapon(*Pistol);
}

void ACPlayer::OnRifle()
{
	CheckNull(Rifle);
	OnWeapon(*Rifle);
}

void ACPlayer::OnAim()
{
	CheckFalse(Weapon->GetEquipped());

	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->MaxWalkSpeed = 320.0f;

	ZoomIn();
	//Camera->Deactivate();
	Weapon->Begin_Aim();

	//Crosshair->SetVisibility(ESlateVisibility::Hidden);
}

void ACPlayer::OffAim()
{
	CheckFalse(Weapon->GetEquipped());

	GetCharacterMovement()->bUseControllerDesiredRotation = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->MaxWalkSpeed = 400.0f;

	ZoomOut();
	//Camera->Activate();
	Weapon->End_Aim();

	//Crosshair->SetVisibility(ESlateVisibility::Visible);
}

void ACPlayer::OnFire()
{
	CheckFalse(Weapon->GetEquipped());
	Weapon->Begin_Fire();
}

void ACPlayer::OffFire()
{
	CheckFalse(Weapon->GetEquipped());
	Weapon->End_Fire();
}

void ACPlayer::OnFocus()
{
	Crosshair->OnFocus();
}

void ACPlayer::OffFocus()
{
	Crosshair->OffFocus();
}

void ACPlayer::GetLocationAndDirection(FVector& OutStart, FVector& OutEnd, FVector& OutDirection)
{
	OutDirection = Camera->GetForwardVector();

	FTransform transform = Camera->GetComponentToWorld();
	FVector cameraLocation = transform.GetLocation();
	OutStart = cameraLocation + OutDirection;

	//ÅºÂø±ºÀ» À§ÇÑ °Í
	FVector conDirection = UKismetMathLibrary::RandomUnitVectorInConeInDegrees(OutDirection, 0.f);
	conDirection *= 3000.0f;

	OutEnd = cameraLocation + conDirection;
}

