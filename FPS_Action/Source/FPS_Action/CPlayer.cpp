#include "CPlayer.h"
#include "Utilities/Global.h"
#include "CAnimInstance.h"
#include "Weapons/CPistol.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Widgets/CUserWidget_CrossHair.h"

ACPlayer::ACPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetCapsuleComponent());
	SpringArm->SetRelativeLocation(FVector(0, 0, 60));
	SpringArm->SocketOffset = FVector(0, 20, 20);
	SpringArm->TargetArmLength = 200.0f;
	SpringArm->bDoCollisionTest = false;
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);
	Camera->SetRelativeLocation(FVector(10, 0, -5));
	Camera->SetRelativeRotation(FRotator(-20.0f, 0, 0));
	Camera->bUsePawnControlRotation = true;

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->MaxWalkSpeed = 400.0f;

	USkeletalMesh* mesh;
	CHelpers::GetAsset<USkeletalMesh>(&mesh, "SkeletalMesh'/Game/Soldier/Mesh/Soldier/SK_Soldier.SK_Soldier'");
	GetMesh()->SetSkeletalMesh(mesh);
	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	TSubclassOf<UCAnimInstance> animInstance;
	CHelpers::GetClass<UCAnimInstance>(&animInstance, "AnimBlueprint'/Game/Soldier/Animations/Soldier/ABP_Player.ABP_Player_C'");
	GetMesh()->SetAnimInstanceClass(animInstance);

	CHelpers::GetClass<UCUserWidget_CrossHair>(&CrossHairClass, "WidgetBlueprint'/Game/Widgets/WB_CrossHair.WB_Crosshair_C'");
}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();

	Crosshair = CreateWidget<UCUserWidget_CrossHair, APlayerController>(GetController<APlayerController>(), CrossHairClass);
	Crosshair->AddToViewport();
	Crosshair->SetVisibility(ESlateVisibility::Hidden);

	Pistol = ACPistol::Spawn(GetWorld(), this);
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

	PlayerInputComponent->BindAction("Aim", EInputEvent::IE_Pressed, this, &ACPlayer::OnAim);
	PlayerInputComponent->BindAction("Aim", EInputEvent::IE_Released, this, &ACPlayer::OffAim);

	PlayerInputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &ACPlayer::OnFire);
	PlayerInputComponent->BindAction("Fire", EInputEvent::IE_Released, this, &ACPlayer::OffFire);
}

void ACPlayer::OnMoveForward(float Axis)
{
	FRotator rotator = FRotator(0, GetControlRotation().Yaw, 0);
	FVector direction = FQuat(rotator).GetForwardVector().GetSafeNormal2D();

	AddMovementInput(direction, Axis);
}

void ACPlayer::OnMoveRight(float Axis)
{
	FRotator rotator = FRotator(0, GetControlRotation().Yaw, 0);
	FVector direction = FQuat(rotator).GetRightVector().GetSafeNormal2D();

	AddMovementInput(direction, Axis);
}

void ACPlayer::OnHorizontalLook(float Axis)
{
	AddControllerYawInput(Axis);
}

void ACPlayer::OnVerticalLook(float Axis)
{
	AddControllerPitchInput(Axis);
}

void ACPlayer::OnRun()
{
	CheckTrue(Pistol->GetAiming());
	bRunning = true;

	GetCharacterMovement()->MaxWalkSpeed = Pistol->GetMaxRunSpeed();

	CheckFalse(Pistol->GetEquipped());
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
}

void ACPlayer::OffRun()
{
	GetCharacterMovement()->MaxWalkSpeed = 400.0f;
	bRunning = false;

	CheckFalse(Pistol->GetEquipped());
	bUseControllerRotationYaw = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;
}

void ACPlayer::OnPistol()
{
	CheckTrue(bRunning);

	if (Pistol->GetEquipped())
	{
		CheckTrue(Pistol->GetAiming());
		Crosshair->SetVisibility(ESlateVisibility::Hidden);
		Pistol->Unequip();
	
		return;
	}

	Pistol->Equip();
	Crosshair->SetVisibility(ESlateVisibility::Visible);
}

void ACPlayer::OnAim()
{
	CheckFalse(Pistol->GetEquipped());

	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->MaxWalkSpeed = 320.0f;

	ZoomIn();
	//Camera->Deactivate();
	Pistol->Begin_Aim();

	//Crosshair->SetVisibility(ESlateVisibility::Hidden);
}

void ACPlayer::OffAim()
{
	CheckFalse(Pistol->GetEquipped());

	GetCharacterMovement()->bUseControllerDesiredRotation = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->MaxWalkSpeed = 400.0f;

	ZoomOut();
	//Camera->Activate();
	Pistol->End_Aim();

	//Crosshair->SetVisibility(ESlateVisibility::Visible);
}

void ACPlayer::OnFire()
{
	Pistol->Begin_Fire();
}

void ACPlayer::OffFire()
{
	Pistol->End_Fire();
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

