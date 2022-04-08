#pragma once

#include "CoreMinimal.h"
#include "CAttachment.h"
#include "CAttachment_Pistol.generated.h"

UCLASS()
class FPS_ACTION_API ACAttachment_Pistol : public ACAttachment
{
	GENERATED_BODY()

public:
	ACAttachment_Pistol();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* StaticMesh;

public:
	FORCEINLINE UStaticMeshComponent* GetWeaponMesh() { return StaticMesh; }
};
