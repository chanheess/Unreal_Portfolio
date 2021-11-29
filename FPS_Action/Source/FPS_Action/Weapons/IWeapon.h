#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IWeapon.generated.h"

UINTERFACE(MinimalAPI)
class UIWeapon : public UInterface
{
	GENERATED_BODY()
};

class FPS_ACTION_API IIWeapon
{
	GENERATED_BODY()

public:
	virtual class ACWeapon* GetWeapon() = 0;
	virtual void GetLocationAndDirection(FVector& OutStart, FVector& OutEnd, FVector& OutDirection) = 0;
	virtual void OnFocus() {}
	virtual void OffFocus() {}
};

