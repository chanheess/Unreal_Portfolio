#include "FPS_ActionGameModeBase.h"
#include "Utilities/Global.h"
#include "Characters/CPlayer.h"


AFPS_ActionGameModeBase::AFPS_ActionGameModeBase()
{
	CHelpers::GetClass<APawn>(&DefaultPawnClass, "Blueprint'/Game/BluePrint/BP_CPlayer.BP_CPlayer_C'");
}