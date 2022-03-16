#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"
#include "CGameInstance.generated.h"

USTRUCT(BlueprintType)
struct FMyCharacterData : public FTableRowBase
{
	GENERATED_BODY()

public:
	FMyCharacterData() : Level(1), MaxHp(100.0f), Attack(10.0f), DropExp(10),
		NextExp(30){}

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
		int32 Level;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
		float MaxHp;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
		float Attack;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
		int32 DropExp;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
		int32 NextExp;
};


UCLASS()
class TEST_API UCGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UCGameInstance();

	virtual void Init() override;

public:
	FMyCharacterData* GetMyCharacterData(int32 Level);

private:
	UPROPERTY()
		class UDataTable* MyCharacterTable;
};
