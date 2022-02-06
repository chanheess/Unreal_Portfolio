#include "CPlayer.h"
#include "../Utilities/Global.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/InputComponent.h"
#include "../Components/CMontagesComponent.h"
#include "../Components/CActionComponent.h"
#include "../Components/COptionComponent.h"
#include "../Components/CStatusComponent.h"
#include "../Widgets/CUserWidget_CrossHair.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialInstanceDynamic.h"

ACPlayer::ACPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	CHelpers::CreateActorComponent(this, &Action, "Action");
	CHelpers::CreateActorComponent(this, &Montages, "Montages");
	CHelpers::CreateActorComponent(this, &Option, "Option");
	CHelpers::CreateActorComponent(this, &Status, "Status");
	CHelpers::CreateActorComponent(this, &State, "State");

	CHelpers::CreateComponent(this, &SpringArm, "SpringArm", GetMesh());
	SpringArm->SetRelativeLocation(FVector(5, 20, 130));
	SpringArm->SetRelativeRotation(FRotator(0, 0, 0));
	SpringArm->SocketOffset = FVector(0, 0, 0);
	SpringArm->TargetArmLength = 1.0f; 
	SpringArm->bDoCollisionTest = false;
	SpringArm->bUsePawnControlRotation = true;


	CHelpers::CreateComponent(this, &Camera, "Camera", SpringArm);
	Camera->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	Camera->SetRelativeRotation(FRotator(0, 0, 0));
	Camera->bUsePawnControlRotation = true;

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0, 720, 0);
	GetCharacterMovement()->MaxWalkSpeed = Status->GetRunSpeed();

	CHelpers::CreateComponent(this, &ArmMesh, "ArmMesh", SpringArm);
	ArmMesh->SetRelativeLocation(FVector(0, 0, -90));
	ArmMesh->SetRelativeRotation(FRotator(0, -90, 0));
	ArmMesh->SetOnlyOwnerSee(true);
	ArmMesh->bCastDynamicShadow = false;
	ArmMesh->CastShadow = false;

	USkeletalMesh* mesh;
	CHelpers::GetAsset<USkeletalMesh>(&mesh, "SkeletalMesh'/Game/Soldier/Mesh/Soldier/SK_Soldier.SK_Soldier'");
	GetMesh()->SetSkeletalMesh(mesh);
	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
	GetMesh()->SetOwnerNoSee(true);

	TSubclassOf<UAnimInstance> animInstance;
	CHelpers::GetClass<UAnimInstance>(&animInstance, "AnimBlueprint'/Game/Player/ABP_Player.ABP_Player_C'");
	GetMesh()->SetAnimInstanceClass(animInstance);

	CHelpers::GetClass<UCUserWidget_CrossHair>(&CrossHairClass, "WidgetBlueprint'/Game/Widgets/WB_CrossHair.WB_Crosshair_C'");
}

void ACPlayer::BeginPlay()
{
	Crosshair = CreateWidget<UCUserWidget_CrossHair, APlayerController>(GetController<APlayerController>(), CrossHairClass);
	Crosshair->AddToViewport();

	State->OnStateTypeChanged.AddDynamic(this, &ACPlayer::OnStateTypeChanged);

	UMaterialInstanceConstant* body;
	CHelpers::GetAssetDynamic<UMaterialInstanceConstant>(&body, "MaterialInstanceConstant'/Game/Soldier/Materials/Soldier/MI_Soldier_1.MI_Soldier_1'");
	BodyMaterial = UMaterialInstanceDynamic::Create(body, this);
	GetMesh()->SetMaterial(0, BodyMaterial);

	Super::BeginPlay();

	Action->SetUnarmedMode();
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

	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ACPlayer::OnJump);
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Released, this, &ACPlayer::OffJump);

	PlayerInputComponent->BindAction("Sprint", EInputEvent::IE_Pressed, this, &ACPlayer::OnSprint);
	PlayerInputComponent->BindAction("Sprint", EInputEvent::IE_Released, this, &ACPlayer::OffSprint);
	PlayerInputComponent->BindAction("Walk", EInputEvent::IE_Pressed, this, &ACPlayer::OnWalk);
	PlayerInputComponent->BindAction("Walk", EInputEvent::IE_Released, this, &ACPlayer::OffWalk);

	PlayerInputComponent->BindAction("Pistol", EInputEvent::IE_Pressed, this, &ACPlayer::OnPistol);
	PlayerInputComponent->BindAction("Rifle", EInputEvent::IE_Pressed, this, &ACPlayer::OnRifle);
	PlayerInputComponent->BindAction("Knife", EInputEvent::IE_Pressed, this, &ACPlayer::OnKnife);

	PlayerInputComponent->BindAction("Action", EInputEvent::IE_Pressed, this, &ACPlayer::OnDoAction);

	//PlayerInputComponent->BindAction("Aim", EInputEvent::IE_Pressed, this, &ACPlayer::OnAim);
	//PlayerInputComponent->BindAction("Aim", EInputEvent::IE_Released, this, &ACPlayer::OffAim);

	//PlayerInputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &ACPlayer::OnFire);
	//PlayerInputComponent->BindAction("Fire", EInputEvent::IE_Released, this, &ACPlayer::OffFire);
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

void ACPlayer::OnJump()
{
	bPressedJump = true;
}

void ACPlayer::OffJump()
{
	bPressedJump = false;
}

void ACPlayer::OnWalk()
{
	GetCharacterMovement()->MaxWalkSpeed = Status->GetWalkSpeed();
}

void ACPlayer::OffWalk()
{
	GetCharacterMovement()->MaxWalkSpeed = Status->GetRunSpeed();
}

void ACPlayer::OnSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = Status->GetSprintSpeed();

	CheckFalse(State->IsIdleMode());
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
}

void ACPlayer::OffSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = Status->GetRunSpeed();

	CheckFalse(State->IsIdleMode());
	bUseControllerRotationYaw = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;
}

void ACPlayer::OnPistol()
{
	CheckFalse(State->IsIdleMode());

	Action->SetPistolMode();
}

void ACPlayer::OnRifle()
{
	CheckFalse(State->IsIdleMode());

	Action->SetRifleMode();
}

void ACPlayer::OnKnife()
{
	CheckFalse(State->IsIdleMode());

	Action->SetKnifeMode();
}

void ACPlayer::OnDoAction()
{
	Action->DoAction();
}

//void ACPlayer::OnAim()
//{
//	//CheckFalse(Weapon->GetEquipped());
//	CheckFalse(State->IsIdleMode());
//
//	GetCharacterMovement()->bUseControllerDesiredRotation = false;
//	GetCharacterMovement()->bOrientRotationToMovement = true;
//	GetCharacterMovement()->MaxWalkSpeed = 320.0f;
//
//	ZoomIn();
//	//Camera->Deactivate();
//	//Weapon->Begin_Aim();
//
//	//Crosshair->SetVisibility(ESlateVisibility::Hidden);
//}
//
//void ACPlayer::OffAim()
//{
//	//CheckFalse(Weapon->GetEquipped());
//	CheckFalse(State->IsIdleMode());
//
//	GetCharacterMovement()->bUseControllerDesiredRotation = true;
//	GetCharacterMovement()->bOrientRotationToMovement = false;
//	GetCharacterMovement()->MaxWalkSpeed = 400.0f;
//
//	ZoomOut();
//	//Camera->Activate();
//	//Weapon->End_Aim();
//
//	//Crosshair->SetVisibility(ESlateVisibility::Visible);
//}

//void ACPlayer::OnFire()
//{
//	CheckFalse(State->IsIdleMode());
//	State->SetFireMode();
//}
//
//void ACPlayer::OffFire()
//{
//	CheckFalse(State->IsFireMode());
//	State->SetFireMode();
//}

void ACPlayer::OnStateTypeChanged(EStateType InPrevType, EStateType InNewType)
{
	switch (InNewType)
	{
	case EStateType::Fire: break;
	case EStateType::Aim: break; 
	}

}

void ACPlayer::OnFocus()
{
	Crosshair->OnFocus();
}

void ACPlayer::OffFocus()
{
	Crosshair->OffFocus();
}

void ACPlayer::ChangeColor(FLinearColor InColor)
{
	BodyMaterial->SetVectorParameterValue("BodyColor", InColor);
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

