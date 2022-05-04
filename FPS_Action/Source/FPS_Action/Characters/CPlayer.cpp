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
	SpringArm->TargetArmLength = 250.0f; 
	SpringArm->bDoCollisionTest = true;
	SpringArm->bUsePawnControlRotation = true;


	CHelpers::CreateComponent(this, &Camera, "Camera", SpringArm);
	//Camera->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	Camera->SetRelativeLocation(FVector(0, 20, 40));
	Camera->SetRelativeRotation(FRotator(0, 0, 0));
	Camera->bUsePawnControlRotation = true;

	//rotation control
	bUseControllerRotationYaw = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;

	GetCharacterMovement()->RotationRate = FRotator(0, 720, 0);
	GetCharacterMovement()->MaxWalkSpeed = Status->GetWalkSpeed();

	GetCapsuleComponent()->SetCollisionProfileName(TEXT("CPlayer"));

	USkeletalMesh* mesh;
	CHelpers::GetAsset<USkeletalMesh>(&mesh, "SkeletalMesh'/Game/Soldier/Mesh/Soldier/SK_Soldier.SK_Soldier'");
	GetMesh()->SetSkeletalMesh(mesh);
	//GetMesh()->SetRelativeLocation(FVector(-18, 5, -130));
	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	//GetMesh()->SetOwnerNoSee(true);
	//GetMesh()->SetOnlyOwnerSee(true);
	//GetMesh()->SetupAttachment(SpringArm);	//X

	TSubclassOf<UAnimInstance> animInstance;
	CHelpers::GetClass<UAnimInstance>(&animInstance, "AnimBlueprint'/Game/Player/ABP_Player.ABP_Player_C'");
	//CHelpers::GetClass<UAnimInstance>(&animInstance, "AnimBlueprint'/Game/Player/ABP_ArmPlayer.ABP_ArmPlayer_C'");
	GetMesh()->SetAnimInstanceClass(animInstance);

	//arm_mesh
	//USkeletalMesh* mesh2;
	//CHelpers::GetAsset<USkeletalMesh>(&mesh2, "SkeletalMesh'/Game/Soldier/Mesh/Soldier/SK_Soldier.SK_Soldier'");
	//CHelpers::CreateComponent(this, &ArmMesh, "ArmMesh", SpringArm);

	//ArmMesh->SetSkeletalMesh(mesh2);
	////ArmMesh->SetRelativeLocation(FVector(-18, 5, -130));
	//ArmMesh->SetRelativeLocation(FVector(0, 0, -90));
	//ArmMesh->SetRelativeRotation(FRotator(0, -90, 0));
	////ArmMesh->SetOnlyOwnerSee(true);
	//ArmMesh->SetOwnerNoSee(true);
	//ArmMesh->bCastDynamicShadow = false;
	//ArmMesh->CastShadow = false;

	//TSubclassOf<UAnimInstance> animInstance2;
	////CHelpers::GetClass<UAnimInstance>(&animInstance2, "AnimBlueprint'/Game/Player/ABP_ArmPlayer.ABP_ArmPlayer_C'");
	//CHelpers::GetClass<UAnimInstance>(&animInstance2, "AnimBlueprint'/Game/Player/ABP_Player.ABP_Player_C'");
	//ArmMesh->SetAnimInstanceClass(animInstance2);

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
	//ArmMesh->SetMaterial(0, BodyMaterial);

	Super::BeginPlay();

	OnKnife();
}

void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//FVector start, end, direction;
	//GetLocationAndDirection(start, end, direction);
	//FHitResult hitResult;
	//TArray<AActor*> ignoreActors;
	//ignoreActors.Add(this);
	//if (UKismetSystemLibrary::LineTraceSingleByProfile(GetWorld(), start, end, "Pawn", false, ignoreActors, EDrawDebugTrace::ForOneFrame, hitResult, true, FLinearColor::Green, FLinearColor::Red))
	//{
	//}
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

	PlayerInputComponent->BindAction("Run", EInputEvent::IE_Pressed, this, &ACPlayer::OnRun);
	PlayerInputComponent->BindAction("Run", EInputEvent::IE_Released, this, &ACPlayer::OffRun);

	PlayerInputComponent->BindAction("Pistol", EInputEvent::IE_Pressed, this, &ACPlayer::OnPistol);
	PlayerInputComponent->BindAction("Rifle", EInputEvent::IE_Pressed, this, &ACPlayer::OnRifle);
	PlayerInputComponent->BindAction("Knife", EInputEvent::IE_Pressed, this, &ACPlayer::OnKnife);

	PlayerInputComponent->BindAction("Action", EInputEvent::IE_Pressed, this, &ACPlayer::OnDoAction);
	PlayerInputComponent->BindAction("Action", EInputEvent::IE_Released, this, &ACPlayer::OffDoAction);

	//PlayerInputComponent->BindAction("Aim", EInputEvent::IE_Pressed, this, &ACPlayer::OnAim);
	//PlayerInputComponent->BindAction("Aim", EInputEvent::IE_Released, this, &ACPlayer::OffAim);
}

float ACPlayer::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float FinalDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	UE_LOG(LogTemp, Warning, TEXT("Actor Name : %s Damage : %f"), *GetName(), FinalDamage);
	return FinalDamage;
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

void ACPlayer::OnRun()
{
	GetCharacterMovement()->MaxWalkSpeed = Status->GetRunSpeed();
}

void ACPlayer::OffRun()
{
	GetCharacterMovement()->MaxWalkSpeed = Status->GetWalkSpeed();
}

void ACPlayer::OnPistol()
{
	CheckFalse(State->IsIdleMode());

	//ArmMesh->SetRelativeLocation(FVector(-18, 5, -130));
	Action->SetPistolMode();
}

void ACPlayer::OnRifle()
{
	CheckFalse(State->IsIdleMode());

	//ArmMesh->SetRelativeLocation(FVector(-18, 5, -130));
	Action->SetRifleMode();
}

void ACPlayer::OnKnife()
{
	CheckFalse(State->IsIdleMode());

	//ArmMesh->SetRelativeLocation(FVector(-18, 16, -140));
	Action->SetKnifeMode();
}

void ACPlayer::OnDoAction()
{
	Status->SetReleased(false);
	Action->DoAction();
	//Action->DoAction_Toogle();
	//CLog::Print("tset");
}

void ACPlayer::OffDoAction()
{
	Status->SetReleased(true);
	//Action->DoAction_Toogle();
}

void ACPlayer::Hitted()
{
	Status->SubHealth(DamageValue);
	DamageValue = 0.0f;

	//Cast<UCUserWidget_Health>(HealthWidget->GetUserWidgetObject())->Update(Status->GetHealth(), Status->GetMaxHealth());	//데이터 갱신

	if (Status->GetHealth() <= 0.0f)
	{
		State->SetDeadMode();

		return;
	}

	Montages->PlayHitted();

	//hitscan
	FVector start = GetActorLocation();
	FVector target = DamageInstigator->GetPawn()->GetActorLocation();
	UKismetMathLibrary::FindLookAtRotation(start, target);
	DamageInstigator = NULL;

	ChangeColor(FLinearColor(1, 0, 0, 1));
	UKismetSystemLibrary::K2_SetTimer(this, "RestoreColor", 0.1f, false);
}

void ACPlayer::Dead()
{
	CheckFalse(State->IsDeadMode());
	Montages->PlayDead();
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

void ACPlayer::OnStateTypeChanged(EStateType InPrevType, EStateType InNewType)
{
	switch (InNewType)
	{
		case EStateType::Aim: break; 
		case EStateType::Hitted: Hitted(); break;
		case EStateType::Dead: Dead(); break;
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

void ACPlayer::RestoreColor()
{
	FLinearColor color = FLinearColor(0, 0, 0, 0);
	ChangeColor(color);
}

void ACPlayer::GetLocationAndDirection(FVector& OutStart, FVector& OutEnd, FVector& OutDirection)
{
	OutDirection = Camera->GetForwardVector();

	FTransform transform = Camera->GetComponentToWorld();
	FVector cameraLocation = transform.GetLocation();
	OutStart = cameraLocation + OutDirection;

	//탄착군을 위한 것
	FVector conDirection = UKismetMathLibrary::RandomUnitVectorInConeInDegrees(OutDirection, 0.2f);
	conDirection *= 3000.0f;

	OutEnd = cameraLocation + conDirection;
}

