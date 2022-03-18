#include "TestGameModeBase.h"

ATestGameModeBase::ATestGameModeBase()
{
	static ConstructorHelpers::FClassFinder<APawn> BPMyCharacter(TEXT("Blueprint'/Game/Player/BP_MyCharacter.BP_MyCharacter_C'"));
	DefaultPawnClass = BPMyCharacter.Class;
}