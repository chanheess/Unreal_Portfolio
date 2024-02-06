#pragma once

#include "Test.h"
#include "GameFramework/Actor.h"
#include "CSection.generated.h"

UCLASS()
class TEST_API ACSection : public AActor
{
	GENERATED_BODY()
	
public:	
	ACSection();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Mesh", Meta = (AllowPrivateAccess = true))
		TArray<UStaticMeshComponent*> GateMeshs;
};
