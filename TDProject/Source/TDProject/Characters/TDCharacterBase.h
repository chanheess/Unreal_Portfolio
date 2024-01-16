#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "TDCharacterBase.generated.h"

UCLASS(Blueprintable)
class TDPROJECT_API ATDCharacterBase : public APaperCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATDCharacterBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

#pragma region Camera
public:
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

#pragma endregion Camera


#pragma region Rotation
public:
	UFUNCTION(BlueprintCallable)
	void CharacterLookAt();

public:
	FRotator DefaultRotation;

#pragma endregion Rotation

};
