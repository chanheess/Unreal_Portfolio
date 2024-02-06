#include "CGameInstance.h"
#include "CLog.h"

UCGameInstance::UCGameInstance()
{
	FString CharacterDataPath = TEXT("DataTable'/Game/GameData/MyCharacterData.MyCharacterData'");
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_MYCHARACTER(*CharacterDataPath);

	if (!DT_MYCHARACTER.Succeeded()) return;
	MyCharacterTable = DT_MYCHARACTER.Object;

	//if (!MyCharacterTable->GetRowMap().Num() > 0) return;
}

void UCGameInstance::Init()
{
	Super::Init();
}

FMyCharacterData* UCGameInstance::GetMyCharacterData(int32 Level)
{
	return MyCharacterTable->FindRow<FMyCharacterData>(*FString::FromInt(Level), TEXT(""));
}
