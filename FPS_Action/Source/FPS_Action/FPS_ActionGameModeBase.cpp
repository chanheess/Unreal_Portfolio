#include "FPS_ActionGameModeBase.h"
#include "Utilities/Global.h"


AFPS_ActionGameModeBase::AFPS_ActionGameModeBase()
{
	CHelpers::GetClass<APawn>(&DefaultPawnClass, "Blueprint'/Game/Player/BP_CPlayer.BP_CPlayer_C'");
}