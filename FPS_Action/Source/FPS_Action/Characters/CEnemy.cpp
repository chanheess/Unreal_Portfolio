#include "CEnemy.h"
#include "../Utilities/Global.h"
#include "../Actions/CActionData.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Animation/AnimInstance.h"
#include "Components/SkeletalMeshComponent.h"
#include "../Components/CMontagesComponent.h"
#include "../Components/CActionComponent.h"
#include "../Components/CStatusComponent.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/WidgetComponent.h"
#include "../Widgets/CUserWidget_Name.h"
#include "../Widgets/CUserWidget_Health.h"
#include "../AI/CAIController.h"

ACEnemy::ACEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	CHelpers::CreateComponent<UWidgetComponent>(this, &HealthWidget, "HealthWidget", GetMesh());
	CHelpers::CreateComponent<UWidgetComponent>(this, &NameWidget, "NameWidget", GetMesh());

	CHelpers::CreateActorComponent<UCMontagesComponent>(this, &Montages, "Montages");
	CHelpers::CreateActorComponent<UCActionComponent>(this, &Action, "Action");
	CHelpers::CreateActorComponent<UCStatusComponent>(this, &Status, "Status");
	CHelpers::CreateActorComponent<UCStateComponent>(this, &State, "State");

	AIControllerClass = ACAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	TSubclassOf<UCUserWidget_Name> nameClass;
	CHelpers::GetClass<UCUserWidget_Name>(&nameClass, "WidgetBlueprint'/Game/Widgets/WB_Name.WB_Name_C'");
	NameWidget->SetWidgetClass(nameClass);
	NameWidget->SetRelativeLocation(FVector(0, 0, 240));
	NameWidget->SetDrawSize(FVector2D(240, 30));
	NameWidget->SetWidgetSpace(EWidgetSpace::Screen);

	TSubclassOf<UCUserWidget_Health> healthClass;
	CHelpers::GetClass<UCUserWidget_Health>(&healthClass, "WidgetBlueprint'/Game/Widgets/WB_Health.WB_Health_C'");
	HealthWidget->SetWidgetClass(healthClass);
	HealthWidget->SetRelativeLocation(FVector(0, 0, 190));
	HealthWidget->SetDrawSize(FVector2D(120, 20));
	HealthWidget->SetWidgetSpace(EWidgetSpace::Screen);

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 480.0f, 0.0f);
	GetCharacterMovement()->MaxWalkSpeed = 350.0f;

}

void ACEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACEnemy::PostInitializeComponents()
{
	Super::PostInitializeComponents();

}

void ACEnemy::BeginPlay()
{
	State->OnStateTypeChanged.AddDynamic(this, &ACEnemy::OnStateTypeChanged);

	Super::BeginPlay();

	NameWidget->InitWidget();
	Cast<UCUserWidget_Name>(NameWidget->GetUserWidgetObject())->SetNameText(GetName());

	HealthWidget->InitWidget();
	Cast<UCUserWidget_Health>(HealthWidget->GetUserWidgetObject())->Update(Status->GetHealth(), Status->GetMaxHealth());

	OffWidget();
	Action->SetPistolMode();
}

void ACEnemy::OnStateTypeChanged(EStateType InPrevType, EStateType InNewType)
{
	switch (InNewType)
	{
		case EStateType::Hitted: Hitted(); break;
		case EStateType::Dead: Dead(); break;
	}
}

void ACEnemy::RestoreColor()
{
	FLinearColor color = FLinearColor(0, 0, 0, 0);
	ChangeColor(color);
}

void ACEnemy::ChangeColor(FLinearColor InColor)
{
	BodyMaterial->SetVectorParameterValue("BodyColor", InColor);
}

float ACEnemy::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	DamageInstigator = EventInstigator;
	DamageValue = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	UE_LOG(LogTemp, Warning, TEXT("Actor Name : %s Damage : %f"), *GetName(), DamageValue);

	State->SetHittedMode();

	return Status->GetHealth();
}

void ACEnemy::OnWidget()
{
	NameWidget->bHiddenInGame = false;
	HealthWidget->bHiddenInGame = false;
}

void ACEnemy::OffWidget()
{
	NameWidget->bHiddenInGame = true;
	HealthWidget->bHiddenInGame = true;
}

void ACEnemy::Hitted()
{
	Status->SubHealth(DamageValue);
	DamageValue = 0.0f;

	Cast<UCUserWidget_Health>(HealthWidget->GetUserWidgetObject())->Update(Status->GetHealth(), Status->GetMaxHealth());	//데이터 갱신

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

void ACEnemy::OnDoAction()
{
	Action->DoAction();
}

void ACEnemy::Dead()
{
	CheckFalse(State->IsDeadMode());
	Montages->PlayDead();
}