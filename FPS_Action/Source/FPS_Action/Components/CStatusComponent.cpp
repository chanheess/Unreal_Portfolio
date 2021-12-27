#include "CStatusComponent.h"
#include "../Utilities/Global.h"

UCStatusComponent::UCStatusComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UCStatusComponent::SetMove()
{
	bCanMove = true;
}

void UCStatusComponent::SetStop()
{
	bCanMove = false;
}


void UCStatusComponent::BeginPlay()
{
	Super::BeginPlay();

}

