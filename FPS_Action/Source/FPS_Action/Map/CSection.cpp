#include "CSection.h"
#include "../Utilities/Global.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/PointLightComponent.h"
#include "../Characters/CEnemy.h"
#include "CItemBox.h"

ACSection::ACSection()
{
	CHelpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers::CreateComponent<UBoxComponent>(this, &Trigger, "Trigger", Scene);
	CHelpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);
	CHelpers::CreateComponent<UPointLightComponent>(this, &PointLight, "PointLight", Scene);

	Trigger->SetRelativeScale3D(FVector(3));	//크기 3
	Trigger->bHiddenInGame = false;	//인게임에서 박스 보이게

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->SetRelativeScale3D(FVector(2));
	Text->TextRenderColor = FColor::Red;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());

	PointLight->SetLightColor(FLinearColor::Red);
	bNoBattle = false;

	EnemySpawnTime = 2.0f;
	ItemBoxSpawnTime = 5.0f;

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &ACSection::ComponentBeginOverlap);
	Trigger->OnComponentEndOverlap.AddDynamic(this, &ACSection::ComponentEndOverlap);
}

void ACSection::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	SetState(bNoBattle ? ESectionState::COMPLETE : ESectionState::READY);
}

void ACSection::BeginPlay()
{
	Super::BeginPlay();

	PointLight->SetVisibility(true);
	SetState(bNoBattle ? ESectionState::COMPLETE : ESectionState::READY);
}

void ACSection::ComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PointLight->SetVisibility(false);
	if (CurrentState == ESectionState::READY)
		SetState(ESectionState::BATTLE);

}

void ACSection::ComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	PointLight->SetVisibility(true);
}

void ACSection::SetState(ESectionState NewState)
{
	switch (NewState)
	{
	case ACSection::ESectionState::READY:
		Trigger->SetCollisionProfileName(TEXT("ABTrigger"));
		OperateGate(true);
		break;
	case ACSection::ESectionState::BATTLE:
		Trigger->SetCollisionProfileName(TEXT("NoCollision"));
		OperateGate(false);

		GetWorld()->GetTimerManager().SetTimer(SpawnNPCTimerHandle, FTimerDelegate::CreateUObject(this, &ACSection::OnNPCSpawn), EnemySpawnTime, false);
		GetWorld()->GetTimerManager().SetTimer(SpawnItemBoxTimerHandle, FTimerDelegate::CreateLambda([this]()-> void
			{
				FVector2D RandXY = FMath::RandPointInCircle(600.0f);
				GetWorld()->SpawnActor<ACItemBox>(GetActorLocation() + FVector(RandXY, 30.0f), FRotator::ZeroRotator);
			}), ItemBoxSpawnTime, false);
		break;
	case ACSection::ESectionState::COMPLETE:
		Trigger->SetCollisionProfileName(TEXT("NoCollision"));
		OperateGate(true);
		break;
	default:
		break;
	}

	CurrentState = NewState;
}

void ACSection::OperateGate(bool bOpen)
{
	//for (UStaticMeshComponent* Gate : GateMeshes)
	//{
	//
	//}
}

void ACSection::OnNPCSpawn()
{
	GetWorld()->SpawnActor<ACEnemy>(GetActorLocation() + FVector::UpVector * 88.0f, FRotator::ZeroRotator);
}
