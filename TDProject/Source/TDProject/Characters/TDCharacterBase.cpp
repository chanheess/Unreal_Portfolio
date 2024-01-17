#include "TDCharacterBase.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ATDCharacterBase::ATDCharacterBase()
{
	// Set this character to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 0.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	//Character default setting
	//DefaultRotation = GetMesh()->GetRelativeRotation();
}

// Called when the game starts or when spawned
void ATDCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATDCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATDCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATDCharacterBase::CharacterLookAt()
{
	APlayerController* MyController = (APlayerController*)GetController();

	if(!MyController)
	{
		return;
	}

	FHitResult Hit;
	MyController->GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.bBlockingHit)
	{
		FVector MouseLoc = FVector(Hit.Location.X, Hit.Location.Y, GetActorLocation().Z);

		FRotator LookRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), MouseLoc);
		//int LookRotation = 180;
		//
		//if(MousePoint.X < GetActorLocation().X)
		//{
		//	LookRotation = -180;
		//}
		
		//SetActorRelativeRotation()
		//
		//SetActorRotation({ MousePoint.X + LookRotation, GetActorRotation().Yaw, MousePoint.Z + LookRotation });
	}
}