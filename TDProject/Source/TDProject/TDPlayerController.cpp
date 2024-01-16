#include "TDPlayerController.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ATDPlayerController::ATDPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

void ATDPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	//LookMouseCursor();
}

// Called when the game starts or when spawned
void ATDPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ATDPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &ATDPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ATDPlayerController::MoveRight);
	
}

void ATDPlayerController::MoveForward(float InAxis)
{
	APawn* const MyPawn = GetPawn();

	if(MyPawn)
	{
		FVector Direction = FVector::ForwardVector;
		MyPawn->AddMovementInput(Direction, InAxis);
	}
}

void ATDPlayerController::MoveRight(float InAxis)
{
	APawn* const MyPawn = GetPawn();

	if (MyPawn)
	{
		FVector Direction = FVector::RightVector;
		MyPawn->AddMovementInput(Direction, InAxis);
	}
}

void ATDPlayerController::LookMouseCursor()
{
	//���߿� ���� �ٶ󺸰� �� �� �������. �ش� ��ġ���� ����ȯ�ؼ� ���� ���������ؼ�...

	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if(Hit.bBlockingHit)
	{
		APawn* const MyPawn = GetPawn();

		if(MyPawn)
		{
			FVector MousePoint = FVector(Hit.Location.X, Hit.Location.Y, MyPawn->GetActorLocation().Z);
			FRotator LookRotation = UKismetMathLibrary::FindLookAtRotation(MyPawn->GetActorLocation(), MousePoint);

			MyPawn->SetActorRotation(LookRotation);
		}
	}
}
