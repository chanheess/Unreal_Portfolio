#include "CStatusComponent.h"
#include "../Utilities/Global.h"

UCStatusComponent::UCStatusComponent()
{
	
}

void UCStatusComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UCStatusComponent::SetMove()
{
	bCanMove = true;
}

void UCStatusComponent::SetStop()
{
	bCanMove = false;
}
