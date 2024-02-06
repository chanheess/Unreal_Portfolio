#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CSection.generated.h"

UCLASS()
class FPS_ACTION_API ACSection : public AActor
{
	GENERATED_BODY()
	
public:	
	ACSection();
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void ComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void ComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
	UPROPERTY(VisibleAnywhere)
		class USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* Trigger;

	UPROPERTY(VisibleAnywhere)
		class UTextRenderComponent* Text;

	UPROPERTY(VisibleAnywhere)
		class UPointLightComponent* PointLight;

	UPROPERTY(EditAnywhere)
		TArray<UStaticMeshComponent*> GateMeshes;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ACEnemy_Zombie> zombie;

	UPROPERTY(EditAnywhere)
		float EnemySpawnTime;

	UPROPERTY(EditAnywhere)
		float ItemBoxSpawnTime;

	UPROPERTY(VisibleAnywhere)
		bool bNoBattle;

	FTimerHandle SpawnNPCTimerHandle = {};
	FTimerHandle SpawnItemBoxTimerHandle = {};

private:
	enum class ESectionState : uint8
	{
		READY = 0,
		BATTLE,
		COMPLETE
	};

	void SetState(ESectionState NewState);
	ESectionState CurrentState = ESectionState::READY;

private:
	void OnNPCSpawn();

};
