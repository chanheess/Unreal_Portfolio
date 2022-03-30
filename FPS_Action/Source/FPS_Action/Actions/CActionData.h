#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CActionData.generated.h"

USTRUCT(BlueprintType)
struct FEquipmentData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		class UAnimMontage* AnimMontage;

	UPROPERTY(EditAnywhere)
		float PlayRatio;

	UPROPERTY(EditAnywhere)
		FName StartSection;

	UPROPERTY(EditAnywhere)
		bool bCanMove = true;

	UPROPERTY(EditAnywhere)
		bool bPawnControl = true;

};

USTRUCT(BlueprintType)
struct FDoActionData : public FEquipmentData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
		float Power = 5.0f;

	UPROPERTY(EditDefaultsOnly)
		float HitStop;

	UPROPERTY(EditDefaultsOnly)
		float LimitPitch;

	UPROPERTY(EditDefaultsOnly)
		class USoundCue* FireSoundCue;

	UPROPERTY(EditDefaultsOnly)
		class UParticleSystem* FlashParticle;

	UPROPERTY(EditDefaultsOnly)
		class UParticleSystem* EjectParticle;

	UPROPERTY(EditDefaultsOnly)
		class UParticleSystem* ImpactParticle;

	UPROPERTY(EditDefaultsOnly)
		class UMaterialInstanceConstant* DecalMaterial;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UCameraShake> CameraShakeClass;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class ACBullet> BulletClass;

	UPROPERTY(EditAnywhere)
		FTransform EffectTransform;
};

UCLASS()
class FPS_ACTION_API UCActionData : public UDataAsset
{
	GENERATED_BODY()

public:
	void BeginPlay(class ACharacter* InOwnerCharacter);

public:
	FORCEINLINE class ACAttachment* GetAttachment() { return Attachment; }
	FORCEINLINE class ACEquipment* GetEquipment() { return Equipment; }
	FORCEINLINE class ACDoAction* GetDoAction() { return DoAction; }
	FORCEINLINE FLinearColor GetEquipmentColor() { return EquipmentColor; }

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		TSubclassOf<class ACAttachment> AttachmentClass;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		TSubclassOf<class ACEquipment> EquipmentClass;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		TSubclassOf<class ACDoAction> DoActionClass;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		TArray<FDoActionData> DoActionDatas;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		FEquipmentData EquipmentData;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		FLinearColor EquipmentColor;

private:
	FString GetLabelName(class ACharacter* InOwnerCharacter, FString InName);

private:
	class ACAttachment* Attachment;
	class ACEquipment* Equipment;
	class ACDoAction* DoAction;
};
