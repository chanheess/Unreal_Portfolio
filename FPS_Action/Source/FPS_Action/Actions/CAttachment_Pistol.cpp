#include "CAttachment_Pistol.h"
#include "../Utilities/Global.h"
#include "GameFramework/Character.h"
#include "Components/SceneComponent.h"
#include "Components/ShapeComponent.h"
#include "../Components/CStateComponent.h"
#include "../Components/CStatusComponent.h"

ACAttachment_Pistol::ACAttachment_Pistol()
{
	CHelpers::CreateComponent<UStaticMeshComponent>(this, &StaticMesh, "StaticMesh");
}

void ACAttachment_Pistol::BeginPlay()
{
	Super::BeginPlay();
}
