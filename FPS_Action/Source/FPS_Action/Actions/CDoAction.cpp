#include "CDoAction.h"
#include "../Utilities/Global.h"
#include "GameFramework/Character.h"
#include "../Components/CStateComponent.h"
#include "../Components/CStatusComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Sound/SoundCue.h"

ACDoAction::ACDoAction()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACDoAction::BeginPlay()
{
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	State = CHelpers::GetComponent<UCStateComponent>(OwnerCharacter);
	Status = CHelpers::GetComponent<UCStatusComponent>(OwnerCharacter);

	Super::BeginPlay();
}

void ACDoAction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACDoAction::OnSoundCue(int cueNum)
{
	CheckFalse(Datas.Num() > cueNum);

	USoundCue* fireSoundCue = Datas[cueNum].FireSoundCue;
	if (!!fireSoundCue)
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), fireSoundCue, OwnerCharacter->GetActorLocation());
}

